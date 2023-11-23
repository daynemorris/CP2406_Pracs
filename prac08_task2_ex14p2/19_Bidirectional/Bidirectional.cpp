 // import <iostream>;
// import <fstream>;
// import <string>;
// import <string_view>;
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <exception>

using namespace std;

// Returns false on error
bool changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	try {
	changeNumberForID("data.txt", 263, "415-555-3333");
	}
	catch (const exception& caughtException) {
		cerr << "Error: " << caughtException.what() << endl;
	}
}

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{ filename.data() };
	if (!ioData) {
		cerr << "Error while opening file " << filename << endl;
		return false;

		string errorString = "Error while opening file: ";
		errorString.append(filename.data());

		throw runtime_error(errorString);
	}

	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());

			if (!ioData) {
				string errorString = "Error while seeking file:";

				throw runtime_error(errorString);
			}

			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
	}
	return true;
}