#include "Game.h"
#include "Stock.h"

Stock::Stock() {

}

void Stock::initial() {
	Stock::companyA = "NTUST公司";
	Stock::companyB = "NTU公司";
	Stock::companyA_money = 100;
	Stock::companyB_money = 100;
	Stock::companyA_remainNum = 100;
	Stock::companyB_remainNum = 100;
}

void Stock::newDay() {
	int range = (Stock::companyA_money / 10);
	if (rand() % 2 == 0) {
		Stock::companyA_money += (rand() % range + 1);
	}
	else {
		Stock::companyA_money -= (rand() % range + 1);
		if (Stock::companyA_money < 0)
			Stock::companyA_money = 0;
	}
	range= (Stock::companyB_money / 10);
	if (rand() % 2 == 0) {
		Stock::companyB_money += (rand() % range + 1);
	}
	else {
		Stock::companyB_money -= (rand() % range + 1);
		if (Stock::companyB_money < 0)
			Stock::companyB_money = 0;
	}
}

void Game::bankSystem() {

	while (1) {
		system("cls");
		Display::setConsoleCursorCoordinate(0, 0);
		cout << "Player " << (this->whosTurn + 1) << "　擁有金額：" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].money;
		cout << "　存款：" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].deposit;
		cout << "　借款：" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].loan;
		cout << "\n========今日股價========\n";
		cout << "【" << Stock::companyA << "】每張：" << Stock::companyA_money << "元，剩餘：" << Stock::companyA_remainNum << "\n";
		cout << "【" << Stock::companyB << "】每張：" << Stock::companyB_money << "元，剩餘：" << Stock::companyB_remainNum << "\n";
		cout << "========================\n";
		cout << "你擁有【" << Stock::companyA << "】：" << this->players[this->whosTurn].stockNum[Stock::companyA]
			<< "張\t你擁有【" << Stock::companyB << "】：" << this->players[this->whosTurn].stockNum[Stock::companyB]
			<< "張\n========================\n\n";
		cout << "\n\n\n========歡迎來到銀行，請問你想要？========\n";
		cout << "1.存款　2.提款　3.借or還款　4.買賣股票　5.離開：";
		string temp = "";
		cin >> temp;
		if (temp == "1") {
			cout << "請輸入欲存入金額：";
			int deposit = 0;
			cin >> deposit;
			if (deposit > 0) {
				if (this->players[this->whosTurn].money >= deposit) {
					this->players[this->whosTurn].money -= deposit;
					this->players[this->whosTurn].deposit += deposit;
					cout << "存款成功";
				}
				else {
					cout << "你這窮Ｂ沒那麼多錢存拉";
				}
			}
			else {
				cout << "輸入必須為大於零的整數喔";
			}
		}
		else if (temp == "2") {
			if (this->players[this->whosTurn].deposit > 0) {
				cout << "請輸入提款金額：";
				int drawMoney = 0;
				cin >> drawMoney;
				if (drawMoney <= this->players[this->whosTurn].deposit) {
					if (drawMoney > 0) {
						this->players[this->whosTurn].deposit -= drawMoney;
						this->players[this->whosTurn].money += drawMoney;
						cout << "提款成功";
					}
					else {
						cout << "提款金額必須大於零";
					}
				}
				else {
					cout << "你這窮Ｂ沒那麼多錢讓你提款拉";
				}
			}
			else {
				cout << "你這窮Ｂ沒錢可以提款拉";
			}
		}
		else if (temp == "3") {
			
			cout << "請輸入借or還金額(輸入正數為借款，負數為還款)：";
			int loanMoney = 0;
			cin >> loanMoney;
			
			if (loanMoney > 0 && this->players[this->whosTurn].loan > 0) {
				cout << "你先把錢給我還完再談借錢，小GG";
			}
			else {
				if (loanMoney >= 0) {
					if (loanMoney <= 10000) {
						this->players[this->whosTurn].loan += loanMoney;
						this->players[this->whosTurn].money += loanMoney;
						cout << "借款成功";
					}
					else {
						cout << "最多只能借你 10000元";
					}
				}
				else {
					if ((-1) * loanMoney <= this->players[this->whosTurn].money) {
						if ((-1) * loanMoney <= this->players[this->whosTurn].loan) {
							this->players[this->whosTurn].loan += loanMoney;
							this->players[this->whosTurn].money += loanMoney;
							cout << "還款成功";
						}
						else {
							cout << "還太多啦";
						}
					}
					else {
						cout << "你身上的錢不夠還款，去賺點錢再來";
					}
				}
				
				
			}
		}
		else if (temp == "4") {
			//Stock::newDay();
			
			cout << "1.買股票 2.賣股票：";
			int buyOrSell = 0;
			cin >> buyOrSell;
			cout << "1."<< Stock::companyA <<" 2." << Stock::companyB <<"：";
			int company = 0;
			cin >> company;
			if (buyOrSell == 1) {
				// buy
				cout << "輸入購買數：";
				int num = 0;
				cin >> num;
				if (num > 0) {
					if (company == 1) {
						if (Stock::companyA_remainNum >= num) {
							if (num * Stock::companyA_money <= this->players[this->whosTurn].deposit) {
								this->players[this->whosTurn].deposit -= (num * Stock::companyA_money);
								this->players[this->whosTurn].stockNum[Stock::companyA] += num;
								Stock::companyA_remainNum -= num;
								cout << "購買成功";
							}
							else {
								cout << "存款不足";
							}
						}
						else {
							cout << "數量不足";
						}
					}
					else if (company == 2) {
						if (Stock::companyB_remainNum >= num) {
							if (num * Stock::companyB_money <= this->players[this->whosTurn].deposit) {
								this->players[this->whosTurn].deposit -= (num * Stock::companyB_money);
								this->players[this->whosTurn].stockNum[Stock::companyB] += num;
								Stock::companyB_remainNum -= num;
								cout << "購買成功";
							}
							else {
								cout << "存款不足";
							}
						}
						else {
							cout << "數量不足";
						}
					}
					else {
						cout << "輸入錯誤";
					}
				}
				else {
					cout << "輸入錯誤";
				}
				
			}
			else if (buyOrSell == 2) {
				// sell
				cout << "輸入販賣數：";
				int num = 0;
				cin >> num;
				if (num > 0) {
					if (company == 1) {
						if (this->players[this->whosTurn].stockNum[Stock::companyA] >= num) {
							Stock::companyA_remainNum += num;
							this->players[this->whosTurn].deposit += (num * Stock::companyA_money);
							this->players[this->whosTurn].stockNum[Stock::companyA] -= num;
							cout << "販賣成功";
						}
						else {
							cout << "數量不足";
						}
					}
					else if (company == 2) {
						if (this->players[this->whosTurn].stockNum[Stock::companyB] >= num) {
							Stock::companyB_remainNum += num;
							this->players[this->whosTurn].deposit += (num * Stock::companyB_money);
							this->players[this->whosTurn].stockNum[Stock::companyB] -= num;
							cout << "販賣成功";
						}
						else {
							cout << "數量不足";
						}
					}
					else {
						cout << "輸入錯誤";
					}
				}
				else {
					cout << "輸入錯誤";
				}
				
			}
			else {
				cout << "輸入錯誤";
			}
		}
		else {
			this->allClean();
			break;
		}
		cout << "\n";
		system("pause");
	}
}