#include <iostream>
#include <string>
#include <cstdio>
#include "Word.h"
#ifndef DEF_NODE
#define DEF_NODE
using namespace std;

class Node{
	public: 
		// thuoc tinh
		string key; 
		Word data;	
		Node *next;
		// phuong thuc
		Node(Word &w);       // Ham khoi tao tu mot tu vung
		Node();             // Ham dung mac dinh
		virtual ~Node();    // Ham huy Node
};
Node::Node(Word &w){
	this->data = w;
	this->key = w.getWord();
	this->next = NULL;
}
Node::Node(){
	this->next = NULL;
}
Node::~Node(){
}
#endif
