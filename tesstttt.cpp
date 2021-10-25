#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Word.h"
#include "HashTable.h"
#define CR_KTK 50
using namespace std;




void xoaManHinh() {
	system("cls");
}
void gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void veGiaoDienChinh(string input) {
	xoaManHinh();
		//int dongHienTai = 0;
	// in ra cac huong dan
	// o man hinh chinh
	cout << " " << "TEN_UNG_DUNG" << endl;	
	cout << " " << char(254) << " Esc  : Thoat chuong trinh" << endl;
	cout << " " << char(254) << " Tab  : Them tu moi" << endl;
	cout << " " << char(254) << " Enter: Xem nghia cua tu" << endl;
	
	// ve khung tim kiem
	cout << char(218);
	for (int i = 0; i < CR_KTK; i++) {
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << char(179) << input;
	cout << char(179) << "";
	for (int i = 0; i < CR_KTK -  input.size(); i++) {
		cout << char(255);
	}
	cout << char(179);
	
	cout << endl << char(192);
	for (int i = 0; i < CR_KTK; i++) {
		cout << char(196);
	}
	cout << char(217);
gotoxy(1 + input.size(), 5);
}
void veGiaoDienChiTietTu(Word m) {
	xoaManHinh();
	int dongHienTai = 0;
	// in ra cac huong dan
	// o man hinh chi tiet tu
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Sua tu nay" << endl;
	cout << " " << char(254) << " Backspace: Xoa tu nay" << endl;
	
	// in ra cac chi tiet cua tu
	cout << endl << " " << m.getWord();
	cout << endl << " ---";
	cout << endl << " (" << m.getType() << "): ";
	cout <<m.getMean() << "; ";
	cout << endl << " ---"; 
	cout<< endl<< m.getExample();
}





// Ham thay doi textcolor va backgroundcolor
void setColor(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}
void readFile() {
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
Word findWord(HashTable DIC, string word){
return DIC.Find(word);
}
void wordInit(Word &w,string dong) {  // dong doc tu file
	int i, pos;
	i = 0;
	// about/pho tu/khoang chung;sap;gan;/He is about to die;We're about to start;How about this?;
	// tach tu
	string word = "";
	while (dong[i] != '/') {word += dong[i++];}
	i++;
	w.setWord(word); // init word in class Word
	
	// tach loai tu
	string type = "";
	while (dong[i] != '/') {type += dong[i++];}
	i++;
	w.setType(type);
	
	// tach nghia
	string mean = ""; pos = 0;
	while (dong[i] != '/') {
		mean += dong[i];
		i++; 
		// nghia moi
		if (dong[i] == ';') { 
		w.setMean(mean);
		}
	}
	i++;
	
	// tach vi du
	string example = "";
	while (dong[i] != '/') {
		example += dong[i++];
		if (dong[i] == ';') {
			w.setExample(example);
		//	cout<<w.getExample();
		}
	}
		
};
void xuLyTuDien(HashTable &tudien) {
	Word currentWord;
	string input = ""; // noi dung hien tai cua khung tim kiem
	int keyCode = 0;
	int pos = 0; // vi tri cua tu hien tai, vi tri thah sang (highlight)

	while (true) { // vong lap vo tan
	veGiaoDienChinh(input);	// ve toan bo giao dien
		keyCode = getch(); // tam dung chuong trinh, nhan ky tu nhap vao		
		switch (keyCode) {
			case 8: // BACKSPACE
				input = input.substr(0, input.size() - 1); // xoa ky tu cuoi
				break;
			case 9: // TAB
			//	themTuMoi(tudien);
				break;
			case 13: // ENTER
				// vao man hinh chi tiet tu
				currentWord = findWord(tudien, input);
				veGiaoDienChiTietTu(currentWord);
				int k;
				do {
					k = getch();
					if (k == 8) { // BACKSPACE
						// xoa tu nay
					//	xoaTu(tudien, tuHienTai);
						input = ""; pos = 0;
						break; // ve man hinh chinh
					}
					if (k == 9) { // TAB
						// sua tu nay
					//	suaTu(tuHienTai);
						input = ""; pos = 0;
						break; // ve man hinh chinh
					}
					if (k == 27) { // ESCAPE
						input = ""; // reset gia tri trong khung tim kiem
						pos = 0;
						break; // ve man hinh chinh
					}
				} while (true);
				break;
			case 27: // ESCAPE
				gotoxy(2, 25);
			//	if (dulieuThaydoi == true) { // neu du lieu co thay doi
			//		cout << "Du lieu thay doi!!! Tien hanh ghi file..." << endl;
				//	ghiFile(tudien);
			//	}
			//	exit(EXIT_SUCCESS); // thoat chuong trinh
				break;
			case 224: {
				int key = getch();
				if (key == 72) { pos--; } // UP
				if (key == 80) { pos++; } // DOWN
				if (pos < 0) pos = 0;
				//if (pos > soLuongTu - 1) pos = soLuongTu - 1;
				break;
			}
			default:
				if (keyCode >= 97 && keyCode <= 122) { // a-z
					input += char(keyCode);
					cout<<char(keyCode);
				}
		}
	};
}
 
int main()
{
Word a[100];
HashTable b;
ifstream fi("words.txt"); // tim tap tin
	string dong;
	int i=0;
	if (fi.is_open()) { // mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
	
	
			if (dong == "") continue;
			wordInit(a[i],dong);
			i++;
			
		}
		fi.close(); // dong tap tin
	}
	for(int j=0;j<10;j++){
	
	b.Insert(a[j]);
//	veGiaoDienChiTietTu(a[j]);
}
//	b.Display();
//int keyCode;
//string input = "";
xuLyTuDien(b);
/*	veGiaoDienChinh();
	while(true){
		keyCode = getch();
		if (keyCode >= 97 && keyCode <= 122) { // a-z
					input += char(keyCode);
					cout<<char(keyCode);
		}
		if(keyCode == 13 ){
			Word m = findWord(b,input);
			veGiaoDienChiTietTu(m);
		}
	} */
	return 0;
}
