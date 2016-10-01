Lab3: Inheritance


Objective: To be familiar with ordered STL list, inheritance and abstract base classes. 

Description: In this assignment, you will build an interactive program for a video store that sells DVD and books.
When the program starts, it loads inventory from an external file inventory.txt.
Each line in the inventory.txt file contains the information of one DVD/Book in one of the following formats:

|Movie|barcode|movie name|director(s) of the movie|movie price|number of copies currently in stock|number of DVD's to be ordered|

|Book|barcode|title of the book|author(s) of the book|publish date|book price|number of copies currently in stock|number of books to be ordered|

Each item in the line is separated by “|”.  

The inventory should be maintained in alphabetical order by barcode instead of title.

The program should provide the following commands:

'M'--Inquire about a specific movie by title and display inventory information for the specified movie.
    The user should be asked to input a movie title and your program should print out all information related to that movie.

'B'--Inquire about a specific book by author and display inventory information for the specified book.
    The user should be asked to input (partial) name of an author and your program should print out all information of the book written by that author.
    You may need to use code similar to the following to allow the user to input only portions of the author’s name.

string str1( "Alpha Beta Gamma Delta" );

string::size_type loc = str1.find( "Omega", 0 );

if( loc != string::npos ) 

     HYPERLINK "http://www.opengroup.org/onlinepubs/009695399/functions/cout.html" cout << "Found Omega at " << loc << endl;

else

     HYPERLINK "http://www.opengroup.org/onlinepubs/009695399/functions/cout.html" cout << "Didn't find Omega" << endl;

'R'--Return a movie/book to the inventory. The user should be asked to input the bar code. If the movie/book is in the inventory,
        the number of copies of the item should be increased by 1 if the number of copies to be ordered is 0,
        or decrease the number of copies to be ordered by 1 if it is greater than 0.

'L'-- List the entire inventory in alphabetical order by barcode

'C'--Check out a movie/book. The user should be asked to input a barcode. If the item is in the inventory and the number of copies of the item is >0,
        your program should decrease the number of copies on hand by one. If the item is in the inventory but there are no copies available,
        the number of copies to be ordered should be increased by 1. If the item is not in the inventory, an error message should be printed.

'Q'-- Quit the program. No need to save the inventory information.

Design: This assignment contains several classes: StoreItem, Movie, and Book.

StoreItem: This is the base class of the classes Movie and Book. A store item can have barcode, price for the item,
           number of copies of the item in the inventory and number of copies to be ordered. The declaration of StoreItem class is provided by the instructor.

Movie: Represents DVD information. It is a derived class of StoreItem.

Book: Represents Book information. It is a derived class of StoreItem.

The file ola3.cpp should provide the program’s user interface: read user’s input and execute appropriate commands.
The inventory must be represented as a list of StoreItem pointers (i.e. list<StoreItem *>) in order to explore the benefits of polymorphism.

Requirements & hints:

You must have a separate header and implementation files for the above classes.

The movies/books should be stored in the list in alphabetical order by barcode. 

Be sure to check for errors: Returning an item that is not supported by the store, checking out an item that is not supported by the store,
inquiring about an item that is not supported by the store, etc.

In this program, you may need to use the function typeid to obtain the runtime type of variables/pointers. The following is a sample code of using typeid.



#include <typeinfo>

void print(StoreItem *item)

{

Movie	defaultMovie;	// a movie object

Book	defaultBook;	// a book object


if ( typeid(*item) == typeid(defaultMovie) )

{

cout << “item is a movie pointer” << endl;

cout << “The director of the movie is “

<< ((Movie *)item)->getDirector() << endl;

}

else if ( typeid(*item) == typeid(defaultBook) )

{

cout << “item is a book pointer” << endl;

cout << “The author of the book is “

<< ((Book *)item)->getAuthor() << endl;

}

}

In this program, you may need to use the stringstream to implement the function createFromString in classes Book and Movie.
To user string stream, you need to include the header file sstream. The following statement creates a string stream from an string object.
The usage of stringstream is similar to a cin.

#include < sstream >

stringstream	ss(aStringVariable);

ss >> aVariable;

getline(ss, stringVariable2HoldValue, ‘|’);