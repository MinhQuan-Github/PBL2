#include <iostream>
//#include <cstdlib>
#include <string>
#include <cstdio>
#include "Word.h"
#define HT_SIZE 1000 // Hash Table Size
using namespace std;

/* -------------------------------------- KHAI BAO DANH SACH LIEN KET ----------------------------------- */

struct Node                                  // Khai bao Node
{				
	string key; // index
	Word data;	// du lieu tu vung
	Node *next;
};

Node *CreateNode(Word w)                     // Khoi tao Node
{ 
	Node *node = new Node;
	node->key = w.getWord();
	node->data = w;
	node->next = NULL;
	return node;
}

struct LinkedList                            // Khai bao danh sach List
{				
	Node *head; // Node dau
	Node *tail; // Node cuoi
};

void CreateList(LinkedList &l)               // Khoi tao danh sach List rong
{ 
	l.head = NULL;
	l.tail = NULL;
}

void AddTail(LinkedList &l, Word w);         // Ham them tu vung vao cuoi
Node *Search(LinkedList l, string word);     // Ham tim kiem tu vung trong danh sach 
void Nodeupdate(LinkedList l, Word word);    // Ham tim kiem tu vung trong danh sach 
int RemoveHead(LinkedList& l);               // Xoa node dau tien
void DestroyList(LinkedList& l);             // Xoa danh sach


void AddTail(LinkedList &l, Word w)
{ 
	Node *node = CreateNode(w);
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

Node *Search(LinkedList l, string word)
{  
	Node *node = l.head;
	while (node != NULL && node->key != word)
		node = node->next;
	if (node != NULL){
	//	cout << node->key;
		return node;
	}
	return NULL;
}

void Nodeupdate(LinkedList l, Word word)
{ 
	Node *node = l.head;
	while (node != NULL && node->key != word.getWord())
		node = node->next;
	if (node != NULL)
		node->data = word;
}

int RemoveHead(LinkedList& l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		l.head = node->next;
		delete node;         
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

void DestroyList(LinkedList& l)
{
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l);
		node = l.head;
	}
	l.tail = NULL;
}

/* -------------------------------------------- KHAI BAO BANG BAM -------------------------------------------- */

class HashTable                                  // Lop Hashtable
{ 
private:
	LinkedList DICTIONARY[HT_SIZE]; 	         // Mang cac bucket
public:
	HashTable();                                 // Ham dung mac dinh Hashtable
	~HashTable();                                // Ham huy HashTable
	int HashFunc(string word);                   // Ham bam (Hash)
	void Insert(Word n);                         // Ham chen tu vung vao Hashtable
	void Display();                              // Ham hien thi danh sach tu vung
	Word Find(string word);                      // Ham tim kiem tu vung trong Hashtable 
	int Size();                                  // Ham lay kich thuoc Hashtable
	void findByInput(Word *array, string input); // Ham goi y tu vung trong Hashtable
	void update(Word w);
};

HashTable::HashTable(){
	for (int i = 0; i < HT_SIZE; i++)
		CreateList(this->DICTIONARY[i]);
}

HashTable::~HashTable(){
	for (int i = 0; i < HT_SIZE; i++)
		DestroyList(this->DICTIONARY[i]);
}

int HashTable::HashFunc(string word){
	int sum = 0;
	for (int i = 0; i < word.size(); i++)
		sum += int(word[i]);
	return sum % HT_SIZE;
}

void HashTable::Insert(Word n){
	int index = HashFunc(n.getWord());
	AddTail(this->DICTIONARY[index], n);
}

void HashTable::Display(){
	for (int i = 0; i < HT_SIZE; i++)
		cout << this->DICTIONARY[i].head->key;
}

Word HashTable::Find(string word){
	Word error ;
	int index = HashFunc(word);
	Node *result = Search(this->DICTIONARY[index],word);
	if(result == NULL) return error;
	return result->data;
}

void HashTable::update(Word w){
	int index = HashFunc(w.getWord());
	Nodeupdate(this->DICTIONARY[index],w);
}

int HashTable::Size(){
	return HT_SIZE;
}

void HashTable::findByInput(Word *array, string input){   
	Word empty;
	const int GIOI_HAN_TU_GOI_Y = 10;
	int limit = 0;
	int index = 0;
	string substr ="";
	for(int i = 0;i<HT_SIZE;i++){
		Node *node = this->DICTIONARY[i].head;
		if (!node) continue; 
		while (node != NULL){
			substr = node->key.substr(0, input.size());
			if(substr == input && index<GIOI_HAN_TU_GOI_Y) {
				array[index] = node->data;
				index++;
			}
			node = node->next;
		}
	// if mang goi y khong du 10 tu thi them cac phan tu trong mang con lai bang Word emty("");
		if(index<GIOI_HAN_TU_GOI_Y-1){
			for(int i = index+1;i<GIOI_HAN_TU_GOI_Y;i++)
				array[i] = empty;
		}
	}
}
