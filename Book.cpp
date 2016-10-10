#include "Book.h"

using namespace std;


//Constructor to initialize Book object
Book::Book(std::string title, std::string author, std::string publishDate, std::string barcode, double price, int copy, int demand)
{
	m_title = title;
	m_author = author;
	m_publishDate = publishDate;
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}



//member function getTitle() to return private m_title variable
std::string Book::getTitle() const
{
	return m_title;
}



//member function getAuthor() to return private m_author variable
std::string Book::getAuthor() const
{
	return m_author;
}



//member function getPublishDate() to return private m_publishDate variable
std::string Book::getPublishDate() const
{
	return m_publishDate;
}



//accepts string then parses to create dynamically allocated Book object
Book * Book::createFromString(const std::string info)
{
	Book *temp = new Book();
	char ignore;

	stringstream ss(info);
	getline(ss, m_barcode, '|');
	getline(ss, m_title, '|');
	getline(ss, m_author, '|');
	getline(ss, m_publishDate, '|');
	ss >> m_price;
	ss >> ignore;
	ss >> m_copy;
	ss >> ignore;
	ss >> m_demand;
	ss >> ignore;


	return temp;
}



//print member variables of the calling Book object
void Book::printItem()
{
	cout << m_title << " " << m_author << " " << m_publishDate << " " << m_barcode << " " << m_price << " " << m_copy << " " << m_demand << endl;
}