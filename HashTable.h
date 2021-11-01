#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "Word.h"
#define HT_SIZE 100 // Hash Table Size
using namespace std;
class HashTable   /////////////////////////////////////////////////// lop tu dien
{
    private:
      Word DICTIONARY[HT_SIZE]; // Mang cac bucket
   public:
 
                         // Kiem tra xem bang bam co rong khon
    int  HashFunc(string word);   
	void Insert(Word n);              // Ham bam
    void Display();                                // Duyet toan bo bucket
    Word Find(string word);
    Word FindByIndex( int index);
    int Size();
};
 
int HashTable::HashFunc(string word){
	int sum = 0;
    for(int i =0;i<word.size();i++){
    	sum+=int(word[i]);
	}
	return sum%HT_SIZE;
}
void HashTable::Insert(Word n){
    int index = HashFunc(n.getWord());
    this->DICTIONARY[index] = n;
}
void HashTable::Display(){
    for(int i =0;i<HT_SIZE;i++){
        this->DICTIONARY[i].display();
    }
}
Word HashTable::Find(string word){
int index = HashFunc(word);
return DICTIONARY[index];
}
int HashTable::Size(){
	return HT_SIZE;
}
Word HashTable::FindByIndex(int index){
	if( index >= this.Size()) return null;
	return this.DICTIONARY[index];
}	
 
           
