#ifndef WRITER_H
#define WRITER_H



#include  <vector>
#include <string>
#include <iostream>
#include "book.h"

using namespace std;

class Writer {
	string name;
	vector<Book> books;
public:
	Writer(string name) : name(name) {}
	void AddBook(Book book);
	string getName() const;
	vector<Book> getBooks() const;
};

#endif