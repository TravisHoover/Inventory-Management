#include "Movie.h"
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;


//Constructor to initialize Movie object
Movie::Movie(std::string title, std::string director, std::string barcode, double price, int copy, int demand)
{
	m_title = title;
	m_director = director;
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}



//member function getTitle() to return private m_title variable
std::string Movie::getTitle() const
{
	return m_title;
}



//member function getDirector() to return private m_director variable
std::string Movie::getDirector() const
{
	return m_director;
}



//accepts string then parses to create dynamically allocated Movie object
Movie * Movie::createFromString(const std::string info)
{
	Movie *temp = new Movie();				//dynamically create new Movie object
	char ignore;							//disregard delimiter

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
	
	return temp;							//return pointer to new object
}



//print member variables of the calling Movie object
void Movie::printItem()
{
	cout << setw(10);

		cout << "*********************** Movie " << m_barcode << " ***********************" << endl;
		cout << "Title: " << m_title << endl;
		cout << "Director: " << m_director << endl;
		cout << "Price: \t" << m_price << endl;
		cout << "# of copies: " << m_copy << endl;
		cout << "Current demand: " << m_demand << endl;

}
