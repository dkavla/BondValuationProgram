#pragma once

/*Blueprint:
	* Bond properties:
	*	# of Years Until Maturity
	*	Yield to Maturity --> Calculate separately as member function
	*	Market Price
	*	Coupon Payments
	*	Interest Rate
	*	Face/Par Value
	*	# of payments per year:
	*		- annual
	*		- semiannual
	*		- quarterly
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

	/* Price Calculator Function */
	double price() const;

	/* Bond Specific Calculations */
	double yieldToMaturity() const;
	double modifiedDuration() const;
	double macaulayDuration() const;
	double accruedExpense(int daysSinceLastCpn) const;

private:
	int years;
	int numOfPmts;
	double cpnRate; // entered in  % form
	double parValue;
	double marketPrice;

	double calculateYTM(double topFactor, double bottomFactor) const;
	double PVOfCpn(int period) const;
	double MacDurPVOFCpn(int period) const;
};