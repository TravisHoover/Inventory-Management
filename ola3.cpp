#include <iostream>

using namespace std;

int main() {

    char userChoice;
    string movieChoice;
    string author;


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
        cin >> author;
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



    return 0;

}