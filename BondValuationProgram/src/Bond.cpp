#include <iostream>
#include "include/Bond.h"

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

/* Bond Calculations */
double Bond::yieldToMaturity() {
	/* To calculate the approximate yield to maturity the needed components are:
		* the coupon paid per period, 
		* the par value, 
		* the market price
		* the total number of periods  
	*/

	int numOfPeriods = years * numOfPmts; // establish total number of periods that coupon is paid
	double couponPerPeriod = (cpnRate * parValue) / numOfPmts; // calculate the coupon paid per period; not annually

	/* the denominator calculation */
	double numer = couponPerPeriod + ((parValue - marketPrice) / numOfPeriods);
	double denom = ((parValue + marketPrice) / 2);

	/* calculate the actual yield to maturity using the above */
	return calculateYTM(numer, denom);

}

/* private member functions */
double Bond::calculateYTM(double topFactor, double bottomFactor) {
	return topFactor / bottomFactor;
}























