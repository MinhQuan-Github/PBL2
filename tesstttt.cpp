#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Word.h"
#include "HashTable.h"
using namespace std;
void docFile() {
	ifstream fi("words.txt"); // tim tap tin
	string dong;
	if (fi.is_open()) { // mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
		cout<<dong<< endl;
			if (dong == "") continue;
		}
		fi.close(); // dong tap tin
	}
}
int main()
{ 
/*docFile();

	fstream f;                    
	f.open("words.txt", ios::in); 

	string data;                  
	getline(f, data);             

	f.close();                    

a.Input(data);
a.displayWord();*/

Word a[100];
HashTable b;
ifstream fi("words.txt"); // tim tap tin
	string dong;
	int i=0;
	if (fi.is_open()) { // mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
	
	
			if (dong == "") continue;
			a[i].Input(dong);
			i++;
			
		}
		fi.close(); // dong tap tin
	}
	for(int j=0;j<i;j++){
	b.Insert(a[j]);}
	b.Display();
	return 0;
}
