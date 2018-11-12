#pragma once
#include <string>
#include <iostream>
#include <list>
#include <forward_list>

class Person {
private:
	std::string fornavn;
	std::string etternavn;
public:
	Person(std::string surname, std::string name);

	std::string getFirstName();
	std::string getSurname();

	bool operator<(Person& p);
};
	
std::ostream& operator<<(std::ostream& os, const Person& p);

void insertOrdered(std::forward_list<Person> &p, Person person);
void insertOrdered(std::list<Person> &p, Person person);