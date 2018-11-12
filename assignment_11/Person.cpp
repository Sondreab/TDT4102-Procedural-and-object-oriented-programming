#include "Person.h"

Person::Person(std::string surname, std::string name) 
	: fornavn(name), etternavn(surname) {
}

std::string Person::getFirstName() {
	return fornavn;
}

std::string Person::getSurname() {
	return etternavn;
}

bool Person::operator<(Person& p) {
	if ((etternavn + fornavn) < (p.etternavn + p.etternavn)) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.getFirstName;
	os << " ";
	os << p.getSurname;
	os << std::endl;
	return os;
}

void insertOrdered(std::forward_list<Person> &p, Person person) {
	std::forward_list<Person>::iterator pit;
	std::forward_list<Person>::iterator previous;
	for (pit = p.begin(); pit != p.end(); ++pit) {
		if (person < *pit) {
			if (pit != p.begin()) {
				p.insert_after(previous, person);
			}
			else {
				p.push_front(person);
			}
			return;
		}
		previous = pit;
	}

	if (p.begin() == p.end()) {
		p.push_front(person);
		return;
	}

	std::forward_list<Person>::iterator prev = p.begin();
	for (pit = p.begin(); pit != p.end(); ++pit) {
		if (pit != p.end()) {
			prev = pit;
		}
	}
	p.insert_after(prev, person);
}

void insertOrdered(std::list<Person> &p, Person person) {
	std::list<Person>::iterator pit;
	for (pit = p.begin(); pit != p.end(); ++pit) {
		if (person < *pit) {
			p.insert(pit, person);
			return;
		}
	}
	p.push_back(person);
}