#include "func.h"

using namespace std;

int main() {
	ProcessRequest(CreateWriters(ReadDataFromFile("DATA.txt")), "Request.txt", "out.txt");

}