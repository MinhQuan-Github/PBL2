#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "Word.h"
#define HT_SIZE 1000 // Hash Table Size
using namespace std;
struct Node
{   string key; 
	Word data;
	Node* next;
};
Node* CreateNode(Word w)
{
	Node* node = new Node;
	node->key = w.getWord();
	node->data = w;
	node->next = NULL;  
	return node;
}
struct LinkedList
{
	Node* head;
	Node* tail;
};
void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void AddTail(LinkedList& l, Word w)
{   
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
Node* Search(LinkedList l, string word)
{
	Node* node = l.head;
	while (node != NULL && node->key != word)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}
class HashTable   /////////////////////////////////////////////////// lop tu dien
{
    private:
      LinkedList DICTIONARY[HT_SIZE]; // Mang cac bucket
   public:
 
                         // Kiem tra xem bang bam co rong khon
    HashTable();
    int  HashFunc(string word);   
	void Insert(Word n);              // Ham bam
    void Display();                                // Duyet toan bo bucket
    Word Find(string word);
    int Size();
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
	
 
           