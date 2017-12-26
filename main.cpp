#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>

#include "FullName.h"
#include "Scientist.h"

using namespace std;

// global variables
vector<FullName> scientistsNames;		//vector containing full names of scientists
list<int> scientistsIds;				//list containing ids of scientists
list<Scientist> scientists;				//list containing scientists (objects of class Scientist)

// function declarations
void loadScientists(ifstream& in);

void printNames();						//prints scientists' names
void printIds();						//prints scientists' ids
void printNamesAndIds();				//prints scientists' ids and names
void printNamesAndIdsInReverse();		//prints scientists' in reverse
void addScientist();					//adds new scientist

void fillScientistsList();				//fills scientists with scientists objects (formed of full names and ids)
void removeDuplicatesAndSortById();		//removes duplicates scientists and sorts them based on their id value
void printScientistsList();				//prints the list of scientists

// main
void main()
{
	ifstream in("scientists.txt");
	if (!in)
	{
		cerr << "ERROR: wrong input file name!";
		exit(-1);
	}

	loadScientists(in);

	printNames();
	cout << endl;
	
	printIds();
	cout << endl;

	printNamesAndIds();
	cout << endl;

	printNamesAndIdsInReverse();
	cout << endl;

	addScientist();

	printNamesAndIds();
	cout << endl;

	fillScientistsList();
	cout << "------------------" << endl;
	cout << "Lista sa duplikatima: " << endl;
	printScientistsList();
	cout << endl;
	cout << "------------------" << endl;

	removeDuplicatesAndSortById();
	cout << "------------------" << endl;
	cout << "Sortirana bez duplikata: " << endl;
	printScientistsList();
	cout << "------------------" << endl;
	cout << endl;

	return;
}

void loadScientists(ifstream& in)
{
	while(!in.eof())
	{
		int id;
		string name;
		string surname;
		
		// @TODO: read id, name and surname from input file stream
		in >> id;
		in >> name;
		in >> surname;
		FullName temp_name = FullName(name, surname);
		Scientist temp_scientist = Scientist(temp_name, id);
		scientistsNames.push_back(temp_name);
		scientistsIds.push_back(id);
		scientists.push_back(temp_scientist);
		// @TODO: create Fullname object from name and surname and add object to the proper vector
		// @TODO: add id to the proper list
		// NOTE: vector and list are already defined as global variables -> NO NEED TO MAKE NEW ONES ! <-
	}
}

void printNames()
{

	vector<FullName>::iterator it;
	for (it = scientistsNames.begin(); it != scientistsNames.end(); it++) {

		cout << *it;
	}
	
}

void printIds()
{
	list<int>::iterator it;
	for (it = scientistsIds.begin(); it != scientistsIds.end(); it++) {
		cout << *it << std::endl;
	}
}

void printNamesAndIds()
{
	list<Scientist>::iterator it;
	for (it = scientists.begin(); it != scientists.end(); it++) {
		*it << cout;
	}
}

void printNamesAndIdsInReverse()
{
	// @TODO: using iterators print scientist id and the its name and surname
	// using list of ids and vector of names, in reverse
	list<Scientist>::reverse_iterator r_it = scientists.rbegin();
	for (; r_it != scientists.rend(); r_it++) {
		*r_it << cout;
	}
	
}

void addScientist()
{
	FullName newScientist("Petar", "Petrovic");
	int newID = 999;
	
	FullName findName("Nikola", "Tesla");
	int findId = 123;
	
	// @TODO: add new scientist "Petar Petrovic" with "999" ID, after
	// "Nikola Tesla" who has "123" as ID
	Scientist temp = Scientist(newScientist, newID);
	list<Scientist>::iterator it;
	for (it = scientists.begin(); it != scientists.end(); it++) {
		if (it->getId() == findId) {
			it++;
			scientists.insert(it, temp);
			break;
		}
	}
}

void fillScientistsList()
{	

	
	list<int>::iterator id_it = scientistsIds.begin();
	vector<FullName>::iterator name_it;
	for (name_it = scientistsNames.begin(); name_it != scientistsNames.end(); name_it++) {
		scientists.push_back(Scientist(*name_it, *id_it));
		id_it++;
	}
	
	
}

bool compare_by_id(const Scientist s1, const Scientist s2) {
	
	return s1.getId() < s2.getId();
}

void removeDuplicatesAndSortById()
{
	// @TODO sort the list of scientists and remove duplicate occurencies
	//scientists.sort(&compare_by_id);
	scientists.sort([](const Scientist s1, const Scientist s2) { return s1.getId() < s2.getId(); });
	scientists.unique([](const Scientist s1, const Scientist s2) {return s1.getId() == s2.getId(); });
	//scientists.sort();
}

void printScientistsList()
{
	printNamesAndIds();
}
