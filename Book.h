#pragma once
#include "StoreItem.h"
#include <string>

class Book : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Book(std::string title = "", std::string author = "", std::string publishDate = "",
		std::string barcode = "", double price = 0, int copy = 0, int demand = 0);

	std::string getTitle() const;

	std::string getAuthor() const;

	std::string getPublishDate() const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	Book* createFromString(const std::string info);

	//Print current item to the screen
	void printItem();

private:
	std::string m_title;         // book title
	std::string m_author;		 // book directors
	std::string m_publishDate;   // book publish date
};
