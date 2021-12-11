#include <iostream>
#include <string>
#include <cstdio>
#include "Word.h"
#ifndef DEF_NODE
#define DEF_NODE
using namespace std;
class Node{
	public: 
	string key; 
	Word data;	
	Node *next;
	Node(Word w);
	Node();
	~Node(){
	};
};
Node::Node(Word w){
	this->data = w;
	this->key = w.getWord();
	this->next = NULL;
}
Node::Node(){
	this->next = NULL;
}
#endif
