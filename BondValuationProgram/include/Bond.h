#pragma once

/*Blueprint:
	* Bond properties:
	*	# of Years Until Maturity
	*	Yield to Maturity --> Calculate separately
	*	Market Price
	*	Coupon Payments
	*	Interest Rate
	*	Face/Par Value
	*	# of payments per year:
	*		- annual
	*		- semiannual
	*
	* Types of bonds:
	*	- Zero-Coupon Bonds
	*	- Corporate Bonds
	*	- Callable Bonds
	*	- Government Bonds
	*	- Convertible Bonds
	* 
	* Goal: Price the bond based off
	*/

class Bond {
public:
	Bond(int years, int pmts, double cpnRate, double par, double marketPrice);
	Bond(int years, int pmts, double cpnRate, double par);
	Bond();

	/* Accessors */
	int getYears() const;
	int getNumOfPmts() const;
	double getCpnRate() const;
	double getParValue() const;
	double getMarketPrice() const;


	/* Mutators */
	void setYears(int yrs);
	void setNumOfPmts(int pmts);
	void setCpnRate(double rate);
	void setPar(double par);
	void setMarketPrice(double price);



private:
	int years;
	int numOfPmts;
	double cpnRate; // entered in  % form
	double parValue;
	double marketPrice;

};