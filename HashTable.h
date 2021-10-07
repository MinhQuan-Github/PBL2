#include<iostream>
#include<string.h>
using namespace std;
class HashTable{
private:
string Array[255];
int size ;
public:
HashTable(){
	this->size = 0;
}
int hashFunction(string key){  
int sum = 0;
int length = key.size();
for(int i = 0;i<length;i++){
    sum+=int(key.at(i));
}
return sum % 100;
}
void set(string key,string value){
 int index = hashFunction(key);
 this->Array[index] = value;
 this->size++;
}
string get(string key){
int index = hashFunction(key);
return  this->Array[index];
}
void remove(string key){
    
this->size--;
}
void display(){
    
}
};