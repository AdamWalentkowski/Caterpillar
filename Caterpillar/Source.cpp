#include "Source.h"

ListElement *create_node(char letter) {
	ListElement *node = new ListElement;
	node->x = letter;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void add_node_back(char letter, ListElement *&tail) {
	if (letter <= 'Z' && letter >= 'A') {
		letter += ('a' - 'A');
	}
	ListElement *node = create_node(letter);
	ListElement *temp = tail;
	temp->next = node;
	node->prev = temp;
	node->next = NULL;
	tail = node;
}

void add_node_front(char letter, ListElement *&head) {
	ListElement *node = create_node(letter);
	ListElement *temp = head;
	temp->prev = node;
	node->next = temp;
	node->prev = NULL;
	head = node;
}

void print_list(ListElement *head) {
	ListElement *node = head;
	while (node != NULL) {
		fputc(node->x, stdout);
		node = node->next;
	}
}

void free_list(ListElement *head) {
	ListElement *dest;
	while (head != NULL) {
		dest = head->next;
		delete head;
		head = dest;
	}
}

void remove_node_front(ListElement *&head, bool &is_dead) {
	ListElement *dest;
	if (head->next != NULL) {
		dest = head->next;
		delete head;
		head = dest;
		head->prev = NULL;
	}
	else {
		is_dead = true;
		delete head;
	}
}

void remove_node_back(ListElement *&tail, bool &is_dead) {
	ListElement *dest;
	if (tail->prev != NULL) {
		dest = tail->prev;
		delete tail;
		tail = dest;
		tail->next = NULL;
	}
	else {
		is_dead = true;
		delete tail;
	}
}