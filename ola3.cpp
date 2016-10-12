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
    string movieChoice;			    //movie to be inquired about in menu option M
    string authorChoice;		    //author to be inquired about in menu option B
	string barcode;				    //barcode of item to be operated on
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






        if (userChoice == 'M' || userChoice == 'm') {                    //Search movies by title
            Movie defaultMovie;                     //dummy movie object for comparison

            cout << "Movie title: " << endl;    //prompt for movie title
            cin >> movieChoice;                 //accept input for movie title


            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {        //iterate through entire list to find matches
                if (typeid(*it) == typeid(defaultMovie)){       //if statement to check if it is a book or movie
                    (*it)->printItem();                         //print movie
                }
            }
            delete defaultMovie;        //delete dummy movie object
        }






        else if (userChoice == 'B' || userChoice == 'b') {            //Search books by author
            cout << "Author: " << endl;         //prompt for author
            cin >> authorChoice;                //accept input for author
        }






        else if (userChoice == 'R' || userChoice == 'r') {            //Return movie/book to inventory
            cout << "****** Return movie/book ******" << endl;
            cout << "Enter barcode: ";
            cin >> barcode;

            it = storeitems.begin();
            for (it; it != storeitems.end(); ++it) {            //iterate through entire list to find matches

                if (barcode == (*it)->getBarcode()) {

                    if ((*it)->getCopy() <= 0) {                //check to ensure there are copies available
                        cout << "This item is currently out of stock" << endl;
                    }

                    cout << "Copy for " << (*it)->getBarcode() << " has increased from " << (*it)->getCopy();
                    (*it)->increaseCopy();                                   //"check-in" item, increase copies
                    cout << " to " << (*it)->getCopy() << endl;
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
                    }

                    cout << "Copy for " << (*it)->getBarcode() << " has decreased from " << (*it)->getCopy();   //inform user of changes
                    (*it)->decreaseCopy();                                                      //"checkout" item, decrease number of copies available
                    cout << " to " << (*it)->getCopy() << endl;
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