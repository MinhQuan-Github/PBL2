#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "DICTIONARY.h"

#define CR_KTK 50
using namespace std;

int main(){
	char *fileName = "words.txt";
	DICTIONARY a(fileName);
	return 0;
}
