#include<iostream>
#include<cstdlib>
#include <string>
#include<cstdio>
#include "Word.h"
#define HT_SIZE 1000 // Hash Table Size
using namespace std;

struct Node {   							// Khai bao Node
	string key; 	// index
	Word data;		// du lieu tu vung
	Node* next;
};

Node* CreateNode(Word w) {					// Khoi tao Node
	Node* node = new Node;
	node->key = w.getWord();
	node->data = w;
	node->next = NULL;  
	return node;
}

struct LinkedList {							// Khai bao danh sach List
	Node* head;		// Node dau
	Node* tail;		// Node cuoi
};

void CreateList(LinkedList& l) {			// Khoi tao danh sach List rong
	l.head = NULL;	
	l.tail = NULL;
}

void AddTail(LinkedList& l, Word w) {  		// Ham them tu vung vao cuoi
	Node* node = CreateNode(w);
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

Node* Search(LinkedList l, string word) {	// Ham tim kiem tu vung trong danh sach   // about about.substring(1,1) = b
	Node* node = l.head;
	while (node != NULL && node->key!= word)
		node = node->next;
	if (node != NULL){
		cout<<node->key;
		return node;
	}	
	return NULL;
}
Node* nodefindByInput (LinkedList l, string input ) {	// Ham tim kiem tu vung trong danh sach
	Node* node = l.head;
  	if(!node) return NULL;
	string substr = node->key.substr(0,input.size());
	while (node != NULL &&  substr!= input)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}
class HashTable   							// Lop Hashtable
{
    private:
      	LinkedList DICTIONARY[HT_SIZE]; 	// Mang cac bucket
    public:
	    HashTable();						// Ham dung mac dinh Hashtable
	    int  HashFunc(string word);   		// Ham bam (Hash)
		void Insert(Word n);              	// Ham chen tu vung vào Hashtable
	    void Display();                     // Ham hien thi danh sach tu vung
	    Word Find(string word);				// Ham tim kiem tu vung trong Hashtable
	    int Size();							// Ham lay kich thuoc Hashtable
	    string findByInput(int n, string word);
};

HashTable::HashTable(){
    for(int i = 0;i<HT_SIZE;i++){
    	CreateList(this->DICTIONARY[i]);
	}
}

int HashTable::HashFunc(string word){
	int sum = 0;
    for(int i =0;i<word.size();i++){
    	sum+=int(word[i]);
	}
	return sum%HT_SIZE;
}

void HashTable::Insert(Word n){
    int index = HashFunc(n.getWord());
    AddTail(this->DICTIONARY[index],n);
}

void HashTable::Display(){
    for(int i =0;i<HT_SIZE;i++){
        cout<<this->DICTIONARY[i].head->key;
    }
}

Word HashTable::Find(string word){
	int index = HashFunc(word);
	Node *result = Search(this->DICTIONARY[index],word);
	return result->data;
}

int HashTable::Size(){
	return HT_SIZE;
}
string HashTable::findByInput(int n, string word){
 	Node* node = nodefindByInput(this->DICTIONARY[n],word);
 	if(node == NULL) return "";
 	return node->key;
 }

 
           
