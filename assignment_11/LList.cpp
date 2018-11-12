#include "LList.h"

ListNode::ListNode(const std::string& value)
	: value(value), next(nullptr) {
	
}

std::string ListNode::getValue() const {
	return value;
}

ListNode* ListNode::getNext() const {
	return next;
}

LinkedList::LinkedList()
	: head(nullptr), last(nullptr) {

}

LinkedList::~LinkedList() {
	
}


bool LinkedList::isEmpty() const {
	return head == nullptr;
}

void LinkedList::insertAtFront(const std::string & elem) {
	ListNode *node = new ListNode(value);
	if (isEmpty()) {
		last = node;
	}
	node->next = head;
	head = node;
}

void LinkedList::insertAtBack(const std::string & elem) {
	ListNode *node = new ListNode(value);
	if (isEmpty()) {
		head = node;
	}
	else {
		last->next = node;
	}
	last = node;
}

bool LinkedList::removeFromFront(std::string & output) {
	if (!isEmpty()) {
		ListNode *node = head;
		head = head->next;
		output = node->getValue();
		delete node;
		if (head == nullptr) {
			last = nullptr;
		}
		return true;
	}
	return false;
}

bool LinkedList::removeFromBack(std::string & output) {
	ListNode *current = head;
	ListNode *prev = nullptr;
	while (current != last) {
		prev = current;
		current = current->next;
	}

	if (current == nullptr) {
		return false;
	}

	last = prev;
	output = current->getValue();
	delete current;

	if (last == nullptr) {
		head = nullptr;
	}
	else {
		last->next = nullptr;
	}
	return true;
}


std::ostream & operator<<(std::ostream & stream, const LinkedList & list) {
	ListNode *current = list.head;
	stream << "The list contains:";
	while (current != nullptr) {
		stream << " " << current->getValue();
		current = current->getNext();
	}
	return stream;
}


ListNode* LinkedList::search(const std::string &value) {
	ListNode *current = head;
	while (current != last) {
		if (current->value == value) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return current;
}

void LinkedList::remove(const std::string &value) {
	std::string dummy;
	while (head != nullptr && head->value == value) {
		removeFromFront(dummy);
	}

	while (last != nullptr && last->value == value) {
		removeFromBack(dummy);
	}

	ListNode *current = head;
	ListNode *prev = nullptr;
	while (current != nullptr) {
		if (current->value == value) {
			prev->next = current->next;
			delete current;
			current = prev->next;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}
