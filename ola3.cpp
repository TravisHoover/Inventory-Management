#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"

using namespace std;

int main() {

    char userChoice;			//handles the input of user's menu choice
    string movieChoice;			//movie to be inquired about
    string authorChoice;		//author to be inquired about

	fstream inventory;
	inventory.open("inventory.txt");

	vector <StoreItem> storeitems;

	while (inventory) {
		
	};


    cout << "Menu choices are as follows: " << endl;
    cout << "'M'--Inquire about a specific movie by title and display inventory information for the specified movie." << endl;
    cout << "'B'--Inquire about a specific book by author and display inventory information for the specified book." << endl;
    cout << "'R'--Return a movie/book to the inventory." << endl;
    cout << "'L'-- List the entire inventory in alphabetical order by barcode." << endl;
    cout << "'C'--Check out a movie/book." << endl;
    cout << "'Q' --Quit the program" << endl;

    cout << "Menu choice: ";
    cin >> userChoice;



    if(userChoice == 'M') {
        cout << "Movie title: " << endl;
        cin >> movieChoice;

    }

    else if(userChoice == 'B') {
        cout << "Author: " << endl;
        cin >> authorChoice;
    }

    else if(userChoice == 'R') {

    }

    else if(userChoice == 'L') {

    }

    else if(userChoice == 'C') {

    }

    else if(userChoice == 'Q') {
        exit(0);
    }

    else
        cout << "Error, please enter M, B, R, L, C, or Q";

		
	inventory.close();
    return 0;

}