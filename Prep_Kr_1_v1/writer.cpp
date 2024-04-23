#pragma once
#include "writer.h"

void Writer::AddBook(Book book) {
	books.push_back(book);
}

string Writer::getName() const {
	return this->name;
}

vector<Book> Writer::getBooks() const {
	return this->books;
}


