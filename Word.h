#ifndef DEF_WORD
#define DEF_WORD
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
class Word {
private:
	string word;	// tu vung
	string type; 	// loai tu
	string mean;	// nghia tu
	string example;	// vi du

public:
	string getWord(); 			// Lay tu vung
	string getType();			// Lay loai tu
	string getMean();			// Lay nghia tu
	string getExample();		// Lay vi du
	void setWord(string m);		// Tao tu vung
	void setType(string m);		// Tao loai tu
	void setMean(string m);		// Tao nghia tu
	void setExample(string m);	// Tao vi du
	void display();				// Hien thi thong tin chi tiet tu vung
//	void displayMeaning();		
//	void Input(string dong);
};

string Word::getWord() {
	return this->word;
}

string Word::getType() {
	return this->type;
}

string Word::getMean() {
	return this->mean;
}

string Word::getExample() {
	return this->example;
}

void Word::setWord(string m) {
	this->word = m;
}

void Word::setType(string m) {
	this->type = m;
}

void Word::setMean(string m) {
	this->mean = m;
}

void Word::setExample(string m) {
	this->example = m;
}

void Word::display() {
	cout << this->word << endl;
	cout << this->type << endl;
	cout << this->mean << endl;
	cout << this->example << endl;
};
#endif
