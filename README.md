## Objective
To be familiar with ordered STL list, inheritance and abstract base classes. 

## Description
    An interactive program for a video store that sells DVD and books.
    When the program starts, it loads inventory from an external file inventory.txt.
    Each line in the inventory.txt file contains the information of one DVD/Book in one of the following formats:

|Movie|barcode|movie name|director(s) of the movie|movie price|number of copies currently in stock|number of DVD's to be ordered|

|Book|barcode|title of the book|author(s) of the book|publish date|book price|number of copies currently in stock|number of books to be ordered|

Each item in the line is separated by “|”.  

The inventory is maintained in alphabetical order by barcode instead of title.

## Program menu

```
'M'--Inquire about a specific movie by title and display inventory information for the specified movie.
    The user should be asked to input a movie title and your program should print out all information related to that movie.

'B'--Inquire about a specific book by author and display inventory information for the specified book.
    The user should be asked to input (partial) name of an author and your program should print out all information of the book written by that author.
    
'R'--Return a movie/book to the inventory. The user should be asked to input the bar code. If the movie/book is in the inventory,
        the number of copies of the item should be increased by 1 if the number of copies to be ordered is 0,
        or decrease the number of copies to be ordered by 1 if it is greater than 0.

'L'-- List the entire inventory in alphabetical order by barcode

'C'--Check out a movie/book. The user should be asked to input a barcode. 

'Q'-- Quit the program. No need to save the inventory information.
```

## Design
    This assignment contains several classes: StoreItem, Movie, and Book.

    StoreItem: This is the base class of the classes Movie and Book. A store item can have barcode, price for the item,
           number of copies of the item in the inventory and number of copies to be ordered.

    Movie: Represents DVD information. It is a derived class of StoreItem.

    Book: Represents Book information. It is a derived class of StoreItem.
