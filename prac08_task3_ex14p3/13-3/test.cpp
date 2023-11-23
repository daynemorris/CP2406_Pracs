// import person;
// import person_database;
// import <iostream>;
// #include "Person.h"
#include "Database.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
	try 
	{
		// Fill a database.
		Database db;
		db.add(Person{ "John", "Doe" });
		db.add(Person{ "Marc", "Gregoire", "Mg" });
		db.add(Person{ "Peter", "Van Weert", "PVW" });

		// Output all persons in the database to standard output.
		cout << "Initial database contents:" << endl;
		db.outputAll(cout);

		// Save the database to a file.
		db.save("person.db");

		// Clear the database.
		db.clear();
		cout << "\nDatabase contents after clearing:" << endl;
		db.outputAll(cout);
		
		// Load database from file.
		cout << "\nLoading database from file..." << endl;
		db.load("pxperson.db");
		cout << "\nDatabase contents after loading from file:" << endl;
		db.outputAll(cout);
	}
	catch (const exception& caughtException) 
	{
		cerr << "Error: " << caughtException.what() << endl;
	}	
}
