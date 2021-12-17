#include <iostream>
#include <string>
#include <cstdio>
#include "Node.h"
#ifndef DEF_LINKEDLIST
#define DEF_LINKEDLIST
using namespace std;

class LinkedList{
	public: 
		// thuoc tinh
		Node *head;
		Node *tail;
		// phuong thuc
		LinkedList();                      // Ham khoi tao danh sach lien ket
		virtual ~LinkedList();             // Ham huy danh sach
		LinkedList &operator += (Word &w); // Ham them tu vung vao cuoi
		void Nodeupdate(Word word);        // Ham cap nhat sua tu vung
};
LinkedList::LinkedList(){
	this->head = NULL;
	this->tail = NULL;
}
LinkedList::~LinkedList(){
	Node* head = this->head;
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
};
LinkedList &LinkedList::operator += (Word &w){
	Node *node= new Node(w);
	if (this->head == NULL)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		this->tail->next = node;
		this->tail = node;
	}
	return *this;
}
void LinkedList::Nodeupdate(Word word){
	Node *node = this->head;
	while (node != NULL && node->key != word.getWord())
		node = node->next;
	if (node != NULL)
		node->data = word;
};
#endif
