#include "StoreItem.h"

std::string StoreItem::getBarcode(void) const
{
	return std::string();
}

double StoreItem::getPrice(void) const
{
	return 0.0;
}

int StoreItem::getCopy(void) const
{
	return 0;
}

int StoreItem::getDemand(void) const
{
	return 0;
}

void StoreItem::increaseCopy(void)
{
}

void StoreItem::decreaseCopy(void)
{
}

void StoreItem::increaseDemand(void)
{
}

void StoreItem::decreaseDemand(void)
{
}

bool StoreItem::operator==(const StoreItem & rhs) const
{
	return false;
}

bool StoreItem::operator<(const StoreItem & rhs) const
{
	return false;
}
