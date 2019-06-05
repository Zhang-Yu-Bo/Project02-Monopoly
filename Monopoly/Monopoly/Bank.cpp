#include "Game.h"
#include "Stock.h"

Stock::Stock() {

}

void Stock::initial() {
	Stock::companyA = "NTUST���q";
	Stock::companyB = "NTU���q";
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
		cout << "Player " << (this->whosTurn + 1) << "�@�֦����B�G" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].money;
		cout << "�@�s�ڡG" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].deposit;
		cout << "�@�ɴڡG" << setw(6) << setfill(' ') << right << this->players[this->whosTurn].loan;
		cout << "\n========����ѻ�========\n";
		cout << "�i" << Stock::companyA << "�j�C�i�G" << Stock::companyA_money << "���A�Ѿl�G" << Stock::companyA_remainNum << "\n";
		cout << "�i" << Stock::companyB << "�j�C�i�G" << Stock::companyB_money << "���A�Ѿl�G" << Stock::companyB_remainNum << "\n";
		cout << "========================\n";
		cout << "�A�֦��i" << Stock::companyA << "�j�G" << this->players[this->whosTurn].stockNum[Stock::companyA]
			<< "�i\t�A�֦��i" << Stock::companyB << "�j�G" << this->players[this->whosTurn].stockNum[Stock::companyB]
			<< "�i\n========================\n\n";
		cout << "\n\n\n========�w��Ө�Ȧ�A�аݧA�Q�n�H========\n";
		cout << "1.�s�ڡ@2.���ڡ@3.��or�ٴڡ@4.�R��Ѳ��@5.���}�G";
		string temp = "";
		cin >> temp;
		if (temp == "1") {
			cout << "�п�J���s�J���B�G";
			int deposit = 0;
			cin >> deposit;
			if (deposit > 0) {
				if (this->players[this->whosTurn].money >= deposit) {
					this->players[this->whosTurn].money -= deposit;
					this->players[this->whosTurn].deposit += deposit;
					cout << "�s�ڦ��\";
				}
				else {
					cout << "�A�o�a�ШS����h���s��";
				}
			}
			else {
				cout << "��J�������j��s����Ƴ�";
			}
		}
		else if (temp == "2") {
			if (this->players[this->whosTurn].deposit > 0) {
				cout << "�п�J���ڪ��B�G";
				int drawMoney = 0;
				cin >> drawMoney;
				if (drawMoney <= this->players[this->whosTurn].deposit) {
					if (drawMoney > 0) {
						this->players[this->whosTurn].deposit -= drawMoney;
						this->players[this->whosTurn].money += drawMoney;
						cout << "���ڦ��\";
					}
					else {
						cout << "���ڪ��B�����j��s";
					}
				}
				else {
					cout << "�A�o�a�ШS����h�����A���ک�";
				}
			}
			else {
				cout << "�A�o�a�ШS���i�H���ک�";
			}
		}
		else if (temp == "3") {
			
			cout << "�п�J��or�٪��B(��J���Ƭ��ɴڡA�t�Ƭ��ٴ�)�G";
			int loanMoney = 0;
			cin >> loanMoney;
			
			if (loanMoney > 0 && this->players[this->whosTurn].loan > 0) {
				cout << "�A����������٧��A�ͭɿ��A�pGG";
			}
			else {
				if (loanMoney >= 0) {
					if (loanMoney <= 10000) {
						this->players[this->whosTurn].loan += loanMoney;
						this->players[this->whosTurn].money += loanMoney;
						cout << "�ɴڦ��\";
					}
					else {
						cout << "�̦h�u��ɧA 10000��";
					}
				}
				else {
					if ((-1) * loanMoney <= this->players[this->whosTurn].money) {
						if ((-1) * loanMoney <= this->players[this->whosTurn].loan) {
							this->players[this->whosTurn].loan += loanMoney;
							this->players[this->whosTurn].money += loanMoney;
							cout << "�ٴڦ��\";
						}
						else {
							cout << "�٤Ӧh��";
						}
					}
					else {
						cout << "�A���W���������ٴڡA�h���I���A��";
					}
				}
				
				
			}
		}
		else if (temp == "4") {
			//Stock::newDay();
			
			cout << "1.�R�Ѳ� 2.��Ѳ��G";
			int buyOrSell = 0;
			cin >> buyOrSell;
			cout << "1."<< Stock::companyA <<" 2." << Stock::companyB <<"�G";
			int company = 0;
			cin >> company;
			if (buyOrSell == 1) {
				// buy
				cout << "��J�ʶR�ơG";
				int num = 0;
				cin >> num;
				if (num > 0) {
					if (company == 1) {
						if (Stock::companyA_remainNum >= num) {
							if (num * Stock::companyA_money <= this->players[this->whosTurn].deposit) {
								this->players[this->whosTurn].deposit -= (num * Stock::companyA_money);
								this->players[this->whosTurn].stockNum[Stock::companyA] += num;
								Stock::companyA_remainNum -= num;
								cout << "�ʶR���\";
							}
							else {
								cout << "�s�ڤ���";
							}
						}
						else {
							cout << "�ƶq����";
						}
					}
					else if (company == 2) {
						if (Stock::companyB_remainNum >= num) {
							if (num * Stock::companyB_money <= this->players[this->whosTurn].deposit) {
								this->players[this->whosTurn].deposit -= (num * Stock::companyB_money);
								this->players[this->whosTurn].stockNum[Stock::companyB] += num;
								Stock::companyB_remainNum -= num;
								cout << "�ʶR���\";
							}
							else {
								cout << "�s�ڤ���";
							}
						}
						else {
							cout << "�ƶq����";
						}
					}
					else {
						cout << "��J���~";
					}
				}
				else {
					cout << "��J���~";
				}
				
			}
			else if (buyOrSell == 2) {
				// sell
				cout << "��J�c��ơG";
				int num = 0;
				cin >> num;
				if (num > 0) {
					if (company == 1) {
						if (this->players[this->whosTurn].stockNum[Stock::companyA] >= num) {
							Stock::companyA_remainNum += num;
							this->players[this->whosTurn].deposit += (num * Stock::companyA_money);
							this->players[this->whosTurn].stockNum[Stock::companyA] -= num;
							cout << "�c�榨�\";
						}
						else {
							cout << "�ƶq����";
						}
					}
					else if (company == 2) {
						if (this->players[this->whosTurn].stockNum[Stock::companyB] >= num) {
							Stock::companyB_remainNum += num;
							this->players[this->whosTurn].deposit += (num * Stock::companyB_money);
							this->players[this->whosTurn].stockNum[Stock::companyB] -= num;
							cout << "�c�榨�\";
						}
						else {
							cout << "�ƶq����";
						}
					}
					else {
						cout << "��J���~";
					}
				}
				else {
					cout << "��J���~";
				}
				
			}
			else {
				cout << "��J���~";
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