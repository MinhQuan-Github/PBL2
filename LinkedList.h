#include <iostream>
#include <string>
#include <cstdio>
#include "Node.h"
#ifndef DEF_LINKEDLIST
#define DEF_LINKEDLIST
using namespace std;
class LinkedList{
	public: 
		Node *head;
		Node *tail;
		LinkedList();
		virtual ~LinkedList();
		void AddTail(Word w);           // Ham them tu vung vao cuoi
		Node *Search(string word);     // Ham tim kiem tu vung trong danh sach 
		void Nodeupdate(Word word);    // Ham cap nhat/ sua tu vung

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
void LinkedList::AddTail(Word w){
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
};
Node* LinkedList::Search(string word){
	Node *node = this->head;
	while (node != NULL && node->key != word)
		node = node->next;
	if (node != NULL){
		return node;
	}
	return NULL;
};
void LinkedList::Nodeupdate(Word word){
	Node *node = this->head;
	while (node != NULL && node->key != word.getWord())
		node = node->next;
	if (node != NULL)
		node->data = word;
};
#endif
