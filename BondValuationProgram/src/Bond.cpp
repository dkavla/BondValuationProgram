#include <iostream>
#include <cmath>
#include "include/Bond.h"

using std::pow;

/* Constructors */
Bond::Bond(int years, int pmts, double cpnRate, double par, double marketPrice) 
	: years(years), numOfPmts(pmts), cpnRate(cpnRate), parValue(par), marketPrice(marketPrice) {}

Bond::Bond(int years, int pmts, double cpnRate, double par) : years(years), numOfPmts(pmts), cpnRate(cpnRate), parValue(par) {
	std::cout << "Market Price must be provided. Enter the market Price: ";
	std::cin >> marketPrice;
}

Bond::Bond() {
	std::cout << "No Arguments Passed In. Setting attributes to default 0 values...\n";
	years = 0;
	numOfPmts = 0;
	cpnRate = 0.0;
	parValue = 0.0;
	marketPrice = 0.0;
}

/* Accessors*/
int Bond::getYears() const {
	return years;
}

int Bond::getNumOfPmts() const {
	return numOfPmts;
}

double Bond::getCpnRate() const {
	return cpnRate;
}

double Bond::getParValue() const {
	return parValue;
}

double Bond::getMarketPrice() const {
	return marketPrice;
}

/* Mutators */
void Bond::setYears(int yrs) {
	years = yrs;
	std::cout << "Bond's Years To Maturity Set To " << yrs << std::endl;
}

void Bond::setNumOfPmts(int pmts) {
	numOfPmts = pmts;
	std::cout << "Coupon Payments Per Year: " << pmts << std::endl;
}

void Bond::setCpnRate(double rate) {
	cpnRate = rate;
	std::cout << "Coupon Rate Set To " << rate << "%" << std::endl;
}

void Bond::setPar(double par) {
	parValue = par;
	std::cout << "Bond Par Value Set To " << par << std::endl;
}

void Bond::setMarketPrice(double price) {
	marketPrice = price;
	std::cout << "Bond's Market Price Set To " << price << std::endl;
}

double Bond::price() const {
	/* 
		The coupons are discounted using the calculated yield to maturity.
		The final coupon payment is summed up with the par value of the bond
		and discounted. Afterwards, all the discounted coupons payments are 
		summed up together in order to get calculated price of the bond. This 
		will establish if the bond is selling at a discounted price, premium 
		price, or at par.
	*/

	double bondPrice = 0.0;
	for (int i = 1; i <= (years * numOfPmts); i++) {
		//std::cout << "Discounted Coupon in period " << i << " is " << PVOfCpn(i) << std::endl;
		bondPrice += PVOfCpn(i);
	}
	//std::cout << "Calculated Bond Price: $" << TotalOfCoupons << std::endl;
	return bondPrice;
	
}

/* Bond Calculations */
double Bond::yieldToMaturity() const {
	/* To calculate the approximate annual yield to maturity the needed components are:
		* the coupon payment, 
		* the par value, 
		* the market price
		* the total number of periods  
		The value returned is is in percentage form
	*/

	int numOfPeriods = years * numOfPmts; // establish total number of periods that coupon is paid
	double couponPerPeriod = ((cpnRate / numOfPmts) / 100) * parValue; // calculate the coupon paid per period

	/* the denominator calculation */
	double numer = couponPerPeriod + ((parValue - marketPrice) / numOfPeriods);
	double denom = ((parValue + marketPrice) / 2);

	/* calculate the actual yield to maturity using the above */
	return (calculateYTM(numer, denom) * numOfPmts) * 100; 
}

double Bond::modifiedDuration() const {
	return 0.0;
}

double Bond::macaulayDuration() const {
	return 0.0;
}

double Bond::accruedExpense(int daysSinceLastCpn) const  {
	return 0.0;
}

/* private member functions */
double Bond::calculateYTM(double topFactor, double bottomFactor) const  {
	return topFactor / bottomFactor;
}

double Bond::PVOfCpn(int period) const {
	double cpn = ((cpnRate / numOfPmts) / 100) * parValue;
	double PVFactor = 1 / pow(1 + ((yieldToMaturity() / 100) / 2), period);
	if (period == (years * numOfPmts)) {
		cpn += parValue;
	}
	return cpn * PVFactor;
}























