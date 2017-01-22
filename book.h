#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book 
{
public:
    string autor, title, category;
    bool borrowed;
    unsigned int pages;
    Book()
    {
        autor = "\0";
        title = "\0";
        category = "\0";
        borrowed = false;
        pages = 0;
    }
    Book(string n_autor, string n_title,string n_category,bool n_borrowed, unsigned int n_pages)
    {
        autor = n_autor;
        title = n_title;
        category = n_category;
        borrowed = n_borrowed;
        pages = n_pages;
    }
    ~Book(){};
    Book(const Book& which)
    {
        autor = which.autor;
        title = which.title;
        category = which.category;
        borrowed = which.borrowed;
        pages = which.pages;
    }
    Book& operator= (const Book& which)
    {
        this->autor = which.autor;
        this->title = which.title;
        this->category = which.category;
        this->borrowed = which.borrowed;
        this->pages = which.pages;
        return *this;
    }
    friend ostream& operator<< (ostream& os, Book& co)
    {
        os <<"Autor: " << co.autor << endl;
        os <<"Title: " << co.title << endl;
        os <<"Category: " << co.category << endl;
        os <<"Borrowed: " << co.borrowed << endl;
        os <<"Pages: " << co.pages << endl;
        return os;
    }
};
#endif