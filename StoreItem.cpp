#include "StoreItem.h"

StoreItem::StoreItem(std::string barcode, double price, int copy, int demand)
{
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}

std::string StoreItem::getBarcode(void) const
{
	return m_barcode;
}

double StoreItem::getPrice(void) const
{
	return m_price;
}

int StoreItem::getCopy(void) const
{
	return m_copy;
}

int StoreItem::getDemand(void) const
{
	return m_demand;
}

void StoreItem::increaseCopy(void)
{
	++m_copy;
}

void StoreItem::decreaseCopy(void)
{
	--m_copy;
}

void StoreItem::increaseDemand(void)
{
	++m_demand;
}

void StoreItem::decreaseDemand(void)
{
	--m_demand;
}

bool StoreItem::operator==(const StoreItem & rhs) const
{	
	if (this->m_barcode == rhs.m_barcode)
		return true;
	else
		return false;
}

bool StoreItem::operator<(const StoreItem & rhs) const
{
	if (this->m_barcode < rhs.m_barcode)
		return true;
	else
		return false;
}
