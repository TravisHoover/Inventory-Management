#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"

using namespace std;

bool compare_storeitem(const StoreItem* lhs, const StoreItem* rhs) {
	//std::cout << lhs->getBarcode() << " " << rhs->getBarcode() << std::endl;
	int ret = lhs->getBarcode().compare(rhs->getBarcode());
	return (ret < 0);
}

int main() {

    char userChoice;			//handles the input of user's menu choice
    string movieChoice;			//movie to be inquired about in menu option M
    string authorChoice;		//author to be inquired about in menu option B
	string barcode;				//barcode of item to be operated on



	fstream inventory;                      //create fstream variable to read inventory data
	inventory.open("inventory.txt");        //open inventory.txt


	list <StoreItem *> storeitems;								 //create list of StoreItem pointers



	while (!inventory.eof()) {              //while loop to read inventory.txt. Terminates at end of file

        //variable declaration
        string info;                        //aggregate line of data to be parsed into StoreItem object
		string mediaType;                   //handles the type of class to be created

		inventory.get();    //ignore leading '|'
		getline(inventory, mediaType, '|');     //read in media type (Book or Movie)

		getline(inventory, info);               //read in data to be parsed into appropriate object


        //If entry is a movie, create a Movie object from data contained in info and push into list of StoreItem objects
		if (mediaType == "Movie") {
			StoreItem *temp = new Movie;
			temp->createFromString(info);
			storeitems.push_back(temp);
			/*for (list <StoreItem *>::iterator it = storeitems.begin(); it != storeitems.end(); it++) {
				if (temp < *(it))
					storeitems.insert(it,temp);
			};*/
		}
            //If entry is a book, create a Book object from data contained in info and push into list of StoreItem objects
		else if (mediaType == "Book") {
			StoreItem *temp = new Book;
			temp->createFromString(info);
			storeitems.push_back(temp);
			/*for (list <StoreItem *>::iterator it = storeitems.begin(); it != storeitems.end(); it++) {
				if (temp < *(it))
					storeitems.insert(it, temp);
			};*/
		}
	};

	storeitems.sort(compare_storeitem);		//needs to sort by barcode, but is sorting by memory address

	list <StoreItem *>::iterator it;
	it = storeitems.begin();									//create first iterator
	list <StoreItem *>::iterator it2 = storeitems.begin();		//create second iterator
	it2++;		//set it2 to one node ahead of it

	
	it = storeitems.begin();
	for (it; it != storeitems.end(); ++it) {
		cout << (*it)->getBarcode() << endl;
	}

	
	//Display user interface for menu
    cout << "Menu choices are as follows: " << endl;
    cout << "'M'--Inquire about a specific movie by title and display inventory information for the specified movie." << endl;
    cout << "'B'--Inquire about a specific book by author and display inventory information for the specified book." << endl;
    cout << "'R'--Return a movie/book to the inventory." << endl;
    cout << "'L'-- List the entire inventory in alphabetical order by barcode." << endl;
    cout << "'C'--Check out a movie/book." << endl;
    cout << "'Q' --Quit the program" << endl;


    cout << "Menu choice: ";        //prompt for menu choice
    cin >> userChoice;              //read in user's menu choice



    if(userChoice == 'M') {					//Search movies by title

        cout << "Movie title: " << endl;
        cin >> movieChoice;

		cout << "******  ******" << endl;

		it = storeitems.begin();
		for (it; it != storeitems.end(); ++it) {

		}

    }
	
    else if(userChoice == 'B') {			//Search books by author
        cout << "Author: " << endl;
        cin >> authorChoice;
    }
	
    else if(userChoice == 'R') {			//Return movie/book to inventory
		cout << "****** Return movie/book ******" << endl;
		cout << "Enter barcode: ";
		cin >> barcode;

		it = storeitems.begin();
		for (it; it != storeitems.end(); ++it) {

			if (barcode == (*it)->getBarcode()) {

				if ((*it)->getCopy() == 0) {
					cout << "This item is currently out of stock" << endl;
					exit(0);
				}

				cout << "Copy for " << (*it)->getBarcode() << " has increased from " << (*it)->getCopy();
				(*it)->increaseCopy();
				cout << " to " << (*it)->getCopy() << endl;
			}
		}
    }
	
    else if(userChoice == 'L') {			//Display entire inventory by barcode
		it = storeitems.begin();
		for (it; it != storeitems.end(); ++it) {
		cout << (*it)->getBarcode() << endl;
		}
    }

    else if(userChoice == 'C') {			//Check out movie/book
		cout << "****** Check out movie/book ******" << endl;
		cout << "Enter barcode: ";
		cin >> barcode;

		it = storeitems.begin();
		for (it; it != storeitems.end(); ++it) {
			if (barcode == (*it)->getBarcode()) {

				if ((*it)->getCopy() == 0) {
					cout << "This item is currently out of stock" << endl;
					exit(0);
				}

				cout << "Copy for " << (*it)->getBarcode() << " has decreased from " << (*it)->getCopy();
				(*it)->decreaseCopy();
				cout << " to " << (*it)->getCopy() << endl;
			}
		}
    }
	
    else if(userChoice == 'Q') {            //Quit program
        exit(0);
    }

	 //Error handling for menu input
    else
        cout << "Error, please enter M, B, R, L, C, or Q";
		
		
	inventory.close();						//close file
    return 0;

}