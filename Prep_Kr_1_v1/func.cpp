
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include "writer.h"


using namespace std;


multimap<string, pair <string, int>> ReadDataFromFile(string filename) {
	multimap<string, pair <string, int> > books;
	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		cerr << "Error opening file" << endl;
		return books;
	}

	string line;
	while (getline(file, line)) {
		string author, title;
		int year;

		size_t pos = line.find(";");

		if (pos == string::npos) {
			cerr << "Error reading file" << endl;
			return books;
		}

		author = line.substr(0, pos);

		line.erase(0, pos + 1);
		pos = line.find(";")
			;
		if (pos == string::npos) {
			cerr << "Error reading file" << endl;
			return books;
		}

		title = line.substr(0, pos);

		line.erase(0, pos + 1);

		year = stoi(line);

		books.insert(pair<string, pair <string, int>>(author, pair<string, int>(title, year)));
	}
	file.close();

	return books;
}

vector<Writer> CreateWriters(multimap<string, pair <string, int>> books) {
	vector<Writer> writers;
	for (auto it = books.begin(); it != books.end(); it++) {
		bool isExist = false;
		string name = it->first;
		for (auto& i : writers) {
			if (i.getName() == name) {
				i.AddBook(Book(it->second.first, it->second.second));
				isExist = true;
				break;
			}		
		}
		if (!isExist) {
			Writer writer(name);
			writer.AddBook(Book(it->second.first, it->second.second));
			writers.push_back(writer);
			isExist = false;
		}
	}
	return writers;
}


void BooksByYear(vector <Writer> writers, int year, string OutFileName, ofstream& out) {
	

	out << "Books by year " << year << ": " << endl;

	for (auto& i : writers) {
		for (auto& j : i.getBooks()) {
			if (j.getYear() == year) {
				out << i.getName() << " " << j.getName() << endl;
			}
		}
	}
	out << endl;
}

void BooksByName(vector <Writer> writers, string name_of_book, string OutFileName, ofstream& out) {


	out << "remakes of book \"" << name_of_book << "\": " << endl;

	for (auto& i : writers) {
		for (auto& j : i.getBooks()) {
			if (j.getName() == name_of_book) {
				out << i.getName() << " " << j.getYear() << endl;
			}
		}
	}
	out << endl;
}

void Writer_Book(vector <Writer> writers, string OutFileName, ofstream& out) {
	out << "All the Books: " << endl;

	for (auto& i : writers) {
		out << i.getName() << ":" << endl;
		for (auto& j : i.getBooks()) {
			out << "\t" << j.getName() << " - " << j.getYear() << endl;
		}
	}
	out << endl;
}

void ProcessRequest(vector<Writer> writers, string RequestFilename, string OutFileName) {
	ifstream in(RequestFilename);
	if (!in.is_open()) {
		cerr << "Error opening file" << endl;
		return;
	}

	ofstream out(OutFileName);
	if (!out.is_open()) {
		cerr << "Error opening file" << endl;
		return;
	}

	string line;
	while (getline(in, line))
	{
		string Request = line.substr(0, 2);
		if (Request == "1:")
		{
			int year = stoi(line.substr(line.find(":") + 1));
			BooksByYear(writers, year, OutFileName, out);
			continue;
		}
		else if (Request == "2:") {
			string book = line.substr(line.find(":") + 1);
			BooksByName(writers, book, OutFileName, out);	
			continue;
		}
		else if (Request == "3:") {
			Writer_Book(writers, OutFileName, out);
			continue;
		}
		else {
			continue;
		}
	}

	out.close();
	in.close();


}