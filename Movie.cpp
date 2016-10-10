#include "Movie.h"
#include <iostream>
#include <sstream>


using namespace std;

Movie::Movie(std::string title, std::string director, std::string barcode, double price, int copy, int demand)
{
	m_title = title;
	m_director = director;
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}

std::string Movie::getTitle() const
{
	return m_title;
}

std::string Movie::getDirector() const
{
	return m_director;
}

Movie * Movie::createFromString(const std::string info)
{
	Movie *temp = new Movie();
	char ignore;

	stringstream ss(info);
	getline(ss, m_barcode, '|');
	getline(ss, m_title, '|');
	getline(ss, m_director, '|');
	ss >> m_price;
	ss >> ignore;
	ss >> m_copy;
	ss >> ignore;
	ss >> m_demand;
	ss >> ignore;
	
	return temp;
}

void Movie::printItem()
{
	cout << m_title << " " << m_director << " " << m_barcode << " " << m_price << " " << m_copy << " " << m_demand << endl;
}
