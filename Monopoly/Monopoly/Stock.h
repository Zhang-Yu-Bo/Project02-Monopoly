#pragma once

#ifndef _STOCK_H_
#define _STOCK_H_

class Stock
{
public:
	Stock();
	static string companyA;
	static string companyB;
	static int companyA_money;
	static int companyB_money;
	static int companyA_remainNum;
	static int companyB_remainNum;
	static void newDay();
	static void initial();
private:

};
#endif // !_STOCK_H_
