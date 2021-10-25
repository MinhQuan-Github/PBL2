#ifndef DEF_WORD
#define DEF_WORD
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
class Word
{
private:
	string word;
	string type; // adj or verb or noun
	string mean;
	string example;

public:
	string getWord(); // Lay tu ra de set index trong hash table;
	string getType();
	string getMean();
	string getExample();
	void setWord(string m);
	void setType(string m);
	void setMean(string m);
	void setExample(string m);
	void display();
	void displayMeaning();
	void Input(string dong);
};
string Word::getWord()
{
	return this->word;
}
string Word::getType()
{
	return this->type;
}
string Word::getMean()
{
	return this->mean;
}
string Word::getExample()
{
	return this->example;
}
void Word::setWord(string m)
{
	this->word = m;
}
void Word::setType(string m)
{
	this->type = m;
}
void Word::setMean(string m)
{
	this->mean = m;
}
void Word::setExample(string m)
{
	this->example = m;
}
void Word::display()
{
	cout << this->word << endl;
	cout << this->type << endl;
	cout << this->mean << endl;
	cout << this->example << endl;
};
#endif
