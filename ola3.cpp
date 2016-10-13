#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"

using namespace std;


//function to handle sorting of list after list has been created
bool compare_storeitem(const StoreItem* lhs, const StoreItem* rhs) {
	int ret = lhs->getBarcode().compare(rhs->getBarcode());
	return (ret < 0);
}


int main() {

/*********************************  Variable declaration for menu navigation  *********************************/
    char userChoice;			    //handles the input of user's menu choice
    string movieChoice;			//movie to be inquired about in menu option M
    string authorChoice;		    //author to be inquired about in menu option B
	string barcode;			    //barcode of item to be operated on
    list <StoreItem *>::iterator it;//create first iterator, will initialize to storeitems.begin() at the start of for loops


/*********************************  Open file  *********************************/
	fstream inventory;                      //create fstream variable to read inventory data
	inventory.open("inventory.txt");        //open inventory.txt


	list <StoreItem *> storeitems;								 //create list of StoreItem pointers



/*****************************  Read inventory and dynamically create a list of objects  ******************************/

	while (!inventory.eof()) {              //while loop to read inventory.txt. Terminates at end of file

        //variable declaration
        string info;                            //aggregate line of data to be parsed into StoreItem object
		string mediaType;                       //handles the type of class to be created

		inventory.get();                        //ignore leading '|'
		getline(inventory, mediaType, '|');     //read in media type (Book or Movie)

		getline(inventory, info);               //read in data to be parsed into appropriate object



        //If entry is a movie, create a Movie object from data contained in info and push into list of StoreItem objects
		if (mediaType == "Movie") {
			StoreItem *temp = new Movie;        //create new Movie object
			temp->createFromString(info);       //call createFromString to parse data in info into an object
			storeitems.push_back(temp);         //push new object onto the back of the list
		}


        //If entry is a book, create a Book object from data contained in info and push into list of StoreItem objects
		else if (mediaType == "Book") {
			StoreItem *temp = new Book;         //create new Book object
			temp->createFromString(info);       //call createFromString to parse data in info into an object
			storeitems.push_back(temp);         //push new object onto the back of the list
		}
	};
/**********************************************************************************************************************/


	storeitems.sort(compare_storeitem);		    //sort the list




/****************************************************  User Menu  *****************************************************/
    do {

        //Display user interface for menu
        cout << "Menu choices are as follows: " << endl;
        cout <<
        "'M'--Inquire about a specific movie by title and display inventory information for the specified movie." <<
        endl;
        cout <<
        "'B'--Inquire about a specific book by author and display inventory information for the specified book." <<
        endl;
        cout << "'R'--Return a movie/book to the inventory." << endl;
        cout << "'L'-- List the entire inventory in alphabetical order by barcode." << endl;
        cout << "'C'--Check out a movie/book." << endl;
        cout << "'Q' --Quit the program" << endl;


        cout << "Menu choice: ";        //prompt for menu choice
        cin >> userChoice;              //read in user's menu choice





        if (userChoice == 'M' || userChoice == 'm') {       //Search movies by title
			
            cout << "Movie title: ";						    //prompt for movie title
			getline(cin, movieChoice);					    //accept input for movie title
			
            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {        //iterate through entire list to find matches
                if (typeid(*it) == typeid(Movie)){		    //if statement to check if it is a book or movie
					if (movieChoice == static_cast<Movie*>(*it)->getTitle())		//static cast to Movie object, check title
						(*it)->printItem();                 //print movie
                }
            }
        }






        else if (userChoice == 'B' || userChoice == 'b') {            //Search books by author
			StoreItem *item;
			Book dummyBook;

            cout << "Author: " << endl;         //prompt for author
            getline(cin, authorChoice);                //accept input for author

			it = storeitems.begin();
			for (it; it != storeitems.end(); ++it) {
				item = (*it);
				if (typeid(*item) == typeid(dummyBook)) {		    //if statement to check if it is a book or movie
					string::size_type loc = static_cast<Book*>(*it)->getAuthor().find(authorChoice);		//search for authorChoice in m_author
					if (loc != std::string::npos)			//if author fragment is present
						(*it)->printItem();                 //print movie
				}
			}
        }






        else if (userChoice == 'R' || userChoice == 'r') {            //Return movie/book to inventory
            cout << "****** Return movie/book ******" << endl;
            cout << "Enter barcode: ";
            cin >> barcode;

            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {            //iterate through entire list to find matches

                if (barcode == (*it)->getBarcode()) {

                    if ((*it)->getDemand() == 0) {
						cout << "The number of copies in stock for " << (*it)->getBarcode() << " has been increased from " << (*it)->getCopy();
						(*it)->increaseCopy();
						cout << " to " << (*it)->getCopy() << endl;
                    }

					else if ((*it)->getDemand() > 0) {
						cout << "The number of copies to be ordered for " << (*it)->getBarcode() << " has been decreased from " << (*it)->getDemand();
						(*it)->decreaseDemand();
						cout << " to " << (*it)->getDemand() << endl;
					}

					else {
						cout << "Error: Invalid barcode" << endl;
					}
                }
            }
        }






        else if (userChoice == 'L' || userChoice == 'l') {            //Display entire inventory by barcode
            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {            //iterate through entire list
                (*it)->printItem();                             //print object
            }
        }






        else if (userChoice == 'C' || userChoice == 'c') {            //Check out movie/book
            cout << "****** Check out movie/book ******" << endl;
            cout << "Enter barcode: ";
            cin >> barcode;

            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {            //iterate through entire list to find matches
                if (barcode == (*it)->getBarcode()) {           //if current object is equal to user's requested barcode

                    if ((*it)->getCopy() <= 0) {                //check that there are copies
                        cout << "This item is currently out of stock" << endl;
						(*it)->increaseDemand();
                    }

					else if ((*it)->getCopy() > 0) {
						cout << "The number of copies in stock for " << (*it)->getBarcode() << " has been decreased from " << (*it)->getCopy();
						(*it)->decreaseCopy();
						cout << " to " << (*it)->getCopy() << endl;
					}
					else {
						cout << "Error: Invalid barcode" << endl;
					}
                }
            }
        }




        else if (userChoice == 'Q' || userChoice == 'q') {            //Quit program
            exit(0);
        }



            //Error handling for menu input
        else
            cout << "Error, please enter M, B, R, L, C, or Q";
		cout << endl << endl;       //formatting, keeps menu iterations from mashing up
    }while(userChoice != 'Q' || userChoice != 'q');     //repeat menu until user chooses to stop

/**********************************************************************************************************************/


	inventory.close();						//close file
    return 0;

}