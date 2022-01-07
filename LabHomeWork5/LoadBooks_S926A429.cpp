//
//  LoadBooks_S926A429.cpp
//  LabHomeWork5
//
//  Created by Raymond Donkemezuo on 11/21/21.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Book {
private:
    char title[1000];
    char author[1000];
    int year_of_publication;
public:
    // - TAG: A functon to print out a book details
    void print_details() {
        cout << "Title: " << title << endl;
        cout << "Athor: " << author << endl;
        cout << "Year: " << year_of_publication << endl;
    }
    // - TAG: A functon to set book title
    void set_title(char book_title[1000]){
        int index = 0;
        while (book_title[index]) {
            title[index] = book_title[index];
            index++;
        }
    }
    // - TAG: A functon to set book author
    void set_author(char book_author[1000]){
        int index = 0;
        while (book_author[index]) {
            author[index] = book_author[index];
            index++;
        }
    }
    // - TAG: A functon to set book publication year
    void set_publication_year(int book_year) {
        year_of_publication = book_year;
    }
};

// A function that takes a file name and checks if that file exist
bool fileExist(string fileName) {
    ifstream file_with_filename(fileName);
    if (file_with_filename) {
        return true;
    } else {
        return false;
    }
}

// A function that ask the user for an input string and returns that string
string ask_user_for_file_name() {
    string user_input_file_name;
    cout << "Enter file name: ";
    cin >> user_input_file_name;
    return user_input_file_name;
}
// A function that reads a file and print out it's content
// Parameters: A string - file name to read
void read_text_file_content(string filename) {
    ifstream ifs;
    ifs.open(filename);
    Book books[100];
    int index_to_append = 0;
    int number_of_books = 0;
    char title[1000];
    char author[1000];
    int year;
    if (fileExist(filename)) {
        ifs >> number_of_books;
        ifs.ignore();
        while (!ifs.eof()) {
            Book book;
            ifs.getline(title, 1000);
            ifs.getline(author, 1000);
            ifs >> year;
            book.set_title(title);
            book.set_author(author);
            book.set_publication_year(year);
            books[index_to_append] = book;
            index_to_append++;
            ifs.ignore();
        }
        ifs.close();
        cout << endl;
        cout << "Books found: " << number_of_books << endl << endl;
        for (int index = 0; index < number_of_books; index++) {
            cout << "Book " << index + 1 << ":" << endl;
            books[index].print_details();
            cout << endl << endl;
        }
    } else {
        cout << "No file with the given name '" << filename << "'" << endl;
        return;
    }
}

// Program Base function
void print_book_list_from_file() {
    cout << "This program reads book details from a given file name \n \n";
    string file_name = ask_user_for_file_name();
    read_text_file_content(file_name);
}

int main() {
    print_book_list_from_file();
}
