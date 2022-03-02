#include <iostream>


/* User Defined Headers */
#include "include/Bond.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	double par = 1000.0;
	double couponRate = 8.0;
	int timeToMaturity = 5;
	int freq = 2;
	double marketPrice = 922.78;

	Bond b1(timeToMaturity, freq, couponRate, par, marketPrice);

	cout.setf(std::ios::fixed);
	cout.setf(std::ios::showpoint);
	cout.precision(2);
	std::cout << "YTM: " << b1.yieldToMaturity() << "%" << std::endl;
	std::cout << "Market Value: $" << b1.price() << std::endl;
	std::cout << "Macaulay Duration: " << b1.macaulayDuration() << std::endl;
	std::cout << "Modified Duration: " << b1.modifiedDuration() << "%" << std::endl;


	return 0;
}