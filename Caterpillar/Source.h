#define _CRT_SECURE_NO_WARNINGS
#ifndef SOURCE_H
#define SOURCE_H
#include <malloc.h>
#include <stdio.h>

struct ListElement {
	char x;
	ListElement *next, *prev;
};

ListElement *create_node(char letter);
void add_node_back(char letter, ListElement *&tail);
void add_node_front(char letter, ListElement *&head);
void print_list(ListElement *head);
void free_list(ListElement *head);
void remove_node_front(ListElement *&head, bool &is_dead);
void remove_node_back(ListElement *&tail, bool &is_dead);
#endif