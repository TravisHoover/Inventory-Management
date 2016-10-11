#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"

using namespace std;

int main() {

    char userChoice;			//handles the input of user's menu choice
    string movieChoice;			//movie to be inquired about in menu option M
    string authorChoice;		//author to be inquired about in menu option B


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
		}
            //If entry is a book, create a Book object from data contained in info and push into list of StoreItem objects
		else if (mediaType == "Book") {
			StoreItem *temp = new Book;
			temp->createFromString(info);
			storeitems.push_back(temp);
		}
            //Error handling
		else
			cout << "Error reading mediaType" << endl;

	};

	list <StoreItem *>::iterator it = storeitems.begin();		//create first iterator
	list <StoreItem *>::iterator it2 = storeitems.begin();		//create second itereator
	it2++;		//set it2 to one node ahead of it
	for (it; it != storeitems.end(); ++it)
	{
		bool whileFlag = false;
		int loop = 1000;

		do {

			//cout << "it:  " << (*it)->getBarcode() << '\t' << "it2:  " << (*it2)->getBarcode() << endl;
			if ((*it)->getBarcode() < (*it2)->getBarcode()) {
				//cout << "swapping" << endl;
				swap(*it, *it2);
				whileFlag = true;
			}
			else if ((*it)->getBarcode() > (*it2)->getBarcode())
				swap(*it2, *it);

			else
				whileFlag = false;

			if (next(it2, 1) != storeitems.end())
				it2++;

			else {
				it2 = storeitems.begin();
				whileFlag = true;
			}
			loop--;
		} while (loop > 0);
	}

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

    }

    else if(userChoice == 'B') {			//Search books by author
        cout << "Author: " << endl;
        cin >> authorChoice;
    }

    else if(userChoice == 'R') {			//Return movie/book to inventory

    }

    else if(userChoice == 'L') {			//Display entire inventory by barcode

    }

    else if(userChoice == 'C') {			//Check out movie/book

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