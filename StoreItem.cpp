#include "StoreItem.h"

StoreItem::StoreItem(std::string barcode, double price, int copy, int demand)
{
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}


//member function to return private m_barcode variable
std::string StoreItem::getBarcode(void) const
{
	return m_barcode;
}


//member function to return private m_price variable
double StoreItem::getPrice(void) const
{
	return m_price;
}


//member function to return private m_copy variable
int StoreItem::getCopy(void) const
{
	return m_copy;
}


//member function to return private m_demand variable
int StoreItem::getDemand(void) const
{
	return m_demand;
}


//member function to increase m_copy by 1
void StoreItem::increaseCopy(void)
{
	++m_copy;
}


//member function to decrease m_copy by 1
void StoreItem::decreaseCopy(void)
{
	--m_copy;
}


//member function to increase m_demand by 1
void StoreItem::increaseDemand(void)
{
	++m_demand;
}


//member function to decrease m_demand by 1
void StoreItem::decreaseDemand(void)
{
	--m_demand;
}


//overloaded operator to compare m_barcode values of two StoreItem objects
bool StoreItem::operator==(const StoreItem & rhs) const
{	
	if (this->m_barcode == rhs.m_barcode)
		return true;
	else
		return false;
}


//overloaded operator to compare m_barcode values of two StoreItem objects
bool StoreItem::operator<( const StoreItem & rhs) const
{
	return this->m_barcode < rhs.m_barcode;
}
