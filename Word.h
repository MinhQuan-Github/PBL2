#ifndef DEF_WORD
#define DEF_WORD
#include <iostream>
#include <fstream>
using namespace std;
class Word {
	private:
		string word;	// tu vung
		string type; 	// loai tu
		string mean;	// nghia tu
		string example;	// vi du
	
	public:
		Word();                     // Ham dung mac dinh
		~Word();                    // Ham huy
		string getWord(); 			// Lay tu vung
		string getType();			// Lay loai tu
		string getMean();			// Lay nghia tu
		string getExample();		// Lay vi du
		void setWord(string m);		// Tao tu vung
		void setType(string m);		// Tao loai tu
		void setMean(string m);		// Tao nghia tu
		void setExample(string m);	// Tao vi du
		const Word &operator = (const Word &m);  // Da nang hoa toan tu =
		void display();				// Hien thi thong tin chi tiet tu vung
};

Word::Word(){
	this->word    = "";
	this->example = "";
	this->type    = "";
	this->mean    = "";
}

Word::~Word(){}

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

const Word &Word::operator = (const Word &m) {
	this->word = m.word;
	this->type = m.type;
	this->mean = m.mean;
	this->example = m.example;
	return *this;
}

void Word::display() {
	cout << this->word << endl;
	cout << this->type << endl;
	cout << this->mean << endl;
	cout << this->example << endl;
};
#endif
