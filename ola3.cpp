#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"
//#include "inventory.txt"

using namespace std;

int main() {

    //char userChoice;			//handles the input of user's menu choice
    //string movieChoice;			//movie to be inquired about
    //string authorChoice;		//author to be inquired about
	//string mediaType;			//


	fstream inventory;
	inventory.open("inventory.txt");

	list <StoreItem *> storeitems;

	while (!inventory.eof()) {
		string info;
		string mediaType;

		inventory.get();
		getline(inventory, mediaType, '|');

		getline(inventory, info);

		if (mediaType == "Movie") {
			StoreItem *temp = new Movie;
			temp->createFromString(info);
			storeitems.push_back(temp);
		}
		else if (mediaType == "Book") {
			StoreItem *temp = new Book;
			temp->createFromString(info);
			storeitems.push_back(temp);
		}
		else
			cout << "Error reading mediaType" << endl;

	};

	/*
    cout << "Menu choices are as follows: " << endl;
    cout << "'M'--Inquire about a specific movie by title and display inventory information for the specified movie." << endl;
    cout << "'B'--Inquire about a specific book by author and display inventory information for the specified book." << endl;
    cout << "'R'--Return a movie/book to the inventory." << endl;
    cout << "'L'-- List the entire inventory in alphabetical order by barcode." << endl;
    cout << "'C'--Check out a movie/book." << endl;
    cout << "'Q' --Quit the program" << endl;

    cout << "Menu choice: ";
    cin >> userChoice;



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

    else if(userChoice == 'Q') {
        exit(0);
    }

    else
        cout << "Error, please enter M, B, R, L, C, or Q";

	*/	
	inventory.close();						//close file
    return 0;

}