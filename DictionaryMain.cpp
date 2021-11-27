#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Word.h"
#include "HashTable.h"
#include "UIsystem.h"
#include "UI.h"
#include "function.h"

#define CR_KTK 50
using namespace std;

void docFile(HashTable &b);                         // Doc file
void xuLyTuDien(HashTable &tudien);                 // Xu ly tu dien

int main() {
	SetConsoleTitle("English-Vietnamese Dictionary");  // Doi tieu de cua so thanh "English-Vietnamese Dictionary"
	kichThuocCuaSo(51,44);                             // Co dinh kich thuoc cua so voi so do (51,44)
	anThanhCuon(0);                                    // An thanh cuon tren cua so ung dung
	voHieuHoaKichThuocCuaSo();                         // Vo hieu hoa thay doi kich thuoc cua so 
	HashTable b;                                       // Khai bao cau truc du lieu HASHTABLE de xu ly tu dien
	giaoDienMoUngDung();
	xuLyTuDien(b);                                     // Xu li tu dien
	return 0;
}

void docFile(HashTable &b) {
	ifstream fi("words.txt"); 	// tim tap tin
	string dong;
	if (fi.is_open()) { 		// mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
			if (dong == "") {
				continue;
			}
			Word w;
			khoiTaoTu(w,dong);
			b.Insert(w);	
		}
		fi.close(); 			// dong tap tin
	}
}

void xuLyTuDien(HashTable &tudien) {
	docFile(tudien);
	Word currentWord;
	string input = ""; // noi dung hien tai cua khung tim kiem
	int keyCode = 0;
	int pos = 0; // vi tri cua tu hien tai, vi tri thanh sang (highlight)
	Word *tugoiy = new Word[10];
	int goiy=1; // so luong goi y tu tim duoc
	while (true) { // vong lap vo tan
		
		veGiaoDienChinh(input);	// ve toan bo giao dien
		
	//	gotoxy(1 + input.size(), 9);
		if(input != "") {
			gotoxy(0,18);
			timTuGoiY(tudien,tugoiy,input,pos+6,goiy);
			veGoiY(pos);
		}
		
		gotoxy(1 + input.size(), 16);
		keyCode = getch(); // tam dung chuong trinh, nhan ky tu nhap vao		
		switch (keyCode) {
			case 8: // BACKSPACE
				input = input.substr(0, input.size() - 1); // xoa ky tu cuoi
				break;
			case 9: // TAB
				themTuMoi(tudien);
				break;
			case 13: // ENTER
				// vao man hinh chi tiet tu
				//
				if(tugoiy[pos].getWord() == "") veLoiKhongTimThayTu();
					else{
					veGiaoDienChiTietTu(tugoiy[pos]);
					int k;
				do {
					k = getch();
					if (k == 8) { // BACKSPACE
						// xoa tu nay
						// xoaTu(tudien, tuHienTai);
						input = ""; pos = 0;
						break; // ve man hinh chinh
					}
					if (k == 9) { // TAB
						// sua tu nay
					suaTu(tudien,currentWord);
						input = ""; pos = 0;
						break; // ve man hinh chinh
					}
					if (k == 27) { // ESCAPE
						input = ""; // reset gia tri trong khung tim kiem
						pos = 0;
						break; // ve man hinh chinh
					}
				} while (true);
					
				}
				break;
			case 27: // ESCAPE
				doiMau(14);
				gotoxy(3,21);
				cout<<"----------------------------------------------";
				gotoxy(2,22);
				cout << "           Thanks for using our app!\n  Hope you had a great experience with this product";
				gotoxy(3,24);
				cout<<"----------------------------------------------";
				gotoxy(2, 27);
				doiMau(9);
			//	if (dulieuThaydoi == true) { // neu du lieu co thay doi
			//		cout << "Du lieu thay doi!!! Tien hanh ghi file..." << endl;
				//	ghiFile(tudien);
			//	}
				exit(EXIT_SUCCESS); // thoat chuong trinh
				break;
			case 224: {
				int key = getch();
				if (key == 72) { pos--; } // UP
				if (key == 80) { 
				if(pos<goiy-1) pos++;
				
				} // DOWN
				if (pos < 0) pos = 0;
				//if (pos > soLuongTu - 1) pos = soLuongTu - 1;
				break;
			}
			default:
				if (keyCode >= 97 && keyCode <= 122) { // a-z
					input += char(keyCode);
				}
		}
		
	};
}
