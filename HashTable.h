#include <iostream>
#include <string>
#include <cstdio>
#include "Word.h"
#include "Node.h"
#include "LinkedList.h"
#define HT_SIZE 1000 // Hash Table Size
using namespace std;


/* -------------------------------------------- KHAI BAO BANG BAM -------------------------------------------- */

class HashTable {                                    // Lop Hashtable 
	private:
		LinkedList DICTIONARY[HT_SIZE]; 	         // Mang cac bucket
	public:
		HashTable();                                 // Ham dung mac dinh Hashtable
		virtual ~HashTable();                        // Ham huy HashTable
		int HashFunc(string word);                   // Ham bam (Hash)
		void Insert(Word n);                         // Ham chen tu vung vao Hashtable
		void Display();                              // Ham xuat key
		Word Find(string word);                      // Ham tim kiem tu vung trong Hashtable 
		int Size();                                  // Ham lay kich thuoc Hashtable
		void findByInput(Word *array, string input); // Ham goi y tu vung trong Hashtable
		void update(Word w);
};

HashTable::HashTable(){
//	for (int i = 0; i < HT_SIZE; i++)
//		this->DICTIONARY[i]->LinkedList();
}

HashTable::~HashTable(){
	for (int i = 0; i < HT_SIZE; i++)
		this->DICTIONARY[i].~LinkedList();
}

int HashTable::HashFunc(string word){
	int sum = 0;
	for (int i = 0; i < word.size(); i++)
		sum += int(word[i]);
	return sum % HT_SIZE;
}

void HashTable::Insert(Word n){
	int index = HashFunc(n.getWord());
	this->DICTIONARY[index].AddTail(n);

}

void HashTable::Display(){
	for (int i = 0; i < HT_SIZE; i++)
		cout << this->DICTIONARY[i].head->key;
}

Word HashTable::Find(string word){
	Word error ;
	int index = HashFunc(word);
	Node *result = this->DICTIONARY[index].Search(word);
	if(result == NULL) return error;
	return result->data;
}

void HashTable::update(Word w){
	int index = HashFunc(w.getWord());
	this->DICTIONARY[index].Nodeupdate(w);
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
	for (int i = 0;i<HT_SIZE;i++){
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
		if (index<GIOI_HAN_TU_GOI_Y-1){
			for(int i = index+1;i<GIOI_HAN_TU_GOI_Y;i++)
				array[i] = empty;
		}
	}
}
