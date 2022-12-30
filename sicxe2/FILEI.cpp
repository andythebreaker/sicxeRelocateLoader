#include "pch.h"
#include "FILEI.h"

#define INA "ina.txt"
#define INB "inb.txt"

#define setdbg false
#define dbg if(setdbg)

using namespace std;

FILEI::FILEI()
{
}

list<string> FILEI::autoread() {
	// Create a text string, which is used to output the text file
	string myText;
	list<string> myList = {};
	// Read from the text file
	ifstream MyReadFile(INB);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		dbg cout << myText;
		myList.push_back(myText);
	}

	// Close the file
	MyReadFile.close();
	return myList;
}
list<string> FILEI::autoread(string inputfilenamefromusr) {
	// Create a text string, which is used to output the text file
	string myText;
	list<string> myList = {};
	// Read from the text file
	ifstream MyReadFile(inputfilenamefromusr);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		dbg cout << myText;
		myList.push_back(myText);
	}

	// Close the file
	MyReadFile.close();
	return myList;
}

FILEI::~FILEI()
{
}
