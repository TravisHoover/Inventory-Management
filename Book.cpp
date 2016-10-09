#include "Book.h"
#include <sstream>



//Book::Book()


Book::Book(std::string title, std::string author, std::string publishDate, std::string barcode, double price, int copy, int demand)
{
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
}


//Book::~Book()