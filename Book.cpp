#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;

//Book::Book()


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


std::string Book::getTitle() const
{
	return m_title;
}


std::string Book::getAuthor() const
{
	return m_author;
}

std::string Book::getPublishDate() const
{
	return m_publishDate;
}


Book * Book::createFromString(const std::string info)
{
	return nullptr;
}


void Book::printItem()
{
	cout << m_title << " " << m_author << " " << m_publishDate << " " << m_barcode << " " << m_price << " " << m_copy << " " << m_demand << endl;
}


//Book::~Book()