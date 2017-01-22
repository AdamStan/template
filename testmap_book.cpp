#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "book.h"			//defines class Book
#include "map_template.h"		//defines template map_template<Key,Value>

int main(void)
{
        map_template<string,Book> Database;
        
	Database.Add("Salesman",Book("Jan Kowalski","Salesman","adventure",true,128));
	Database.Add("I'm going to",Book("Adam Nowak","I'm going to","romance",false,254));
	Database.Add("The Great Poland",Book("Janusz Cebula","The Great Poland","historical fiction",true,732));

	cout << "PIERWOTNA Databse: \n" << Database << "/***THE_END***/\n" << endl;

	map_template<string,Book> NewDatabase = Database;
	
	Book* pB;
	pB = NewDatabase.Find("I'm going to");	
	pB->category = "New adventure";		
	pB = NewDatabase.Find("Salesman");	
	pB->pages = 29;				

	Database = NewDatabase;			
	cout << "ZMIENIONA Databse: \n" << Database << "/***THE_END***/\n" << endl;		
}