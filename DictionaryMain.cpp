#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Word.h"
#include "HashTable.h"

#define CR_KTK 50
using namespace std;

void xoaManHinh();                                  // Xoa man hinh
void gotoxy(short x, short y);                      // Dat con tro tai toa do (x,y)
void veGiaoDienChinh(string input);                 // giao dien tim tu vung
void veGiaoDienChiTietTu(Word m);                   // giao dien chi tiet tu vung
void doiMau(short x);                               // Ham thay doi textcolor va backgroundcolor
Word timTu(HashTable DIC, string word);             // Tim tu vung
void khoiTaoTu(Word &w,string dong);                // Ham khoi tao tu vung
void suaTu(HashTable &tudien,Word &w);              // Sua tu vung
void themTuMoi(HashTable &tudien);                  // Nhap tu vung
void docFile(HashTable &b);                         // Doc file
void xuLyTuDien(HashTable &tudien);                 // Xu ly tu dien
void timTuGoiY(HashTable &tudien, string input);    // Tim tu goi y
void kichThuocCuaSo(SHORT width, SHORT height);     // Thay doi kich thuoc cua so
void anThanhCuon(BOOL Show);                        // Ham an thanh scroll bar
void voHieuHoaKichThuocCuaSo();                     // Ham vo hieu hoa thay doi kich thuoc man hinh
void veLoiKhongTimThayTu();                         // Ham tra ve giao dien khong tim thay tu


int main() {
	SetConsoleTitle("English-Vietnamese Dictionary");  // Ham thay doi tieu de cua so
	kichThuocCuaSo(51,44);
	anThanhCuon(0);
	voHieuHoaKichThuocCuaSo();
	//system("color E");
	HashTable b;
	xuLyTuDien(b);
	return 0;
}

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
	doiMau(12);
	cout<<endl;
	cout<<"        DAI HOC BACH KHOA - DAI HOC DA NANG " << endl;
	cout<<"          ------------------------------" << endl;
	cout<<"             KHOA CONG NGHE THONG TIN" << endl << endl << endl;
	doiMau(10);
	cout<<"           DO AN PBL2 : CO SO LAP TRINH"<<endl;
	cout<<"  Giao vien huong dan: TS.Le Thi My Hanh"<<endl;
	cout<<"  Sinh vien thuc hien: +/ Ho Duc Hoang - 20T2 "<<endl;
	cout<<"                       +/ Do Minh Quan - 20T2 "<<endl;
	cout<<endl; 
	doiMau(14);
	cout << " " << "TU DIEN ANH - VIET" << endl;	
	cout << " " << char(254) << " Esc  : Thoat chuong trinh" << endl;
	cout << " " << char(254) << " Tab  : Them tu moi" << endl;
	cout << " " << char(254) << " Enter: Xem nghia cua tu" << endl;
	doiMau(11);
	// ve khung tim kiem
	cout << char(218);
	for (int i = 0; i < CR_KTK; i++) {
		cout << char(196);
	}
	cout << char(191) << endl;
	
	cout << char(179) << input;
	for (int i = 0; i < CR_KTK - input.size(); i++) {
		cout << char(255);
	}
	cout << char(179);
	
	cout << endl << char(192);
	for (int i = 0; i < CR_KTK; i++) {
		cout << char(196);
	}
	cout << char(217);
	cout<<endl;
	gotoxy(1 + input.size(), 9);
}
void veGiaoDienChiTietTu(Word m) {
	xoaManHinh();
	int dongHienTai = 0;
	// in ra cac huong dan
	// o man hinh chi tiet tu
	doiMau(10);
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Sua tu nay" << endl;
	doiMau(14);
	// in ra cac chi tiet cua tu
	cout << endl << " " << m.getWord();
	cout << endl << " ---";
	cout << endl << " (" << m.getType() << "): ";
	cout <<m.getMean() << "; ";
	cout << endl << " ---"; 
	cout<< endl<<" "<<m.getExample();
}
void veLoiKhongTimThayTu(){
	xoaManHinh();
	int dongHienTai = 0;
	// in ra cac huong dan
	// o man hinh chi tiet tu
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Sua tu nay" << endl;
	cout << " Loi! Khong co tu nay" << endl;
}

// Ham thay doi textcolor va backgroundcolor
void doiMau(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}


Word timTu(HashTable DIC, string word){
	return  DIC.Find(word);
}


void khoiTaoTu(Word &w,string dong) {  // dong doc tu file
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
}


void suaTu(HashTable &tudien,Word &w) {
	xoaManHinh();
	
	cout << "Sua tu: '" << w.getWord()<< "':" << endl;
	// Sua loai tu
	string temp = "";
	cout << "Sua loai tu (" << w.getType() << "): ";
	getline(cin, temp);

	if (temp == "") return;
	w.setType(temp);

	// Sua nghia
	temp = "";
	cout << "Sua nghia " <<  " (" << w.getMean() << "): ";
	getline(cin, temp);
	w.setMean(temp);

	// Sua vi du
	temp = "";
	cout << "Sua vidu " <<  " (" << w.getExample() << "): ";
	getline(cin, temp);
	w.setExample(temp);
	tudien.update(w);
}


void themTuMoi(HashTable &tudien) {
	xoaManHinh();
	Word w;
	string temp = "";
	// nhap tu
	cout << "Nhap tu: ";
	getline(cin, temp);
	if (temp == "") return;
	else {
		w.setWord(temp);
	}
	// nhap loai tu
	temp = "";
	cout << "Nhap loai tu: ";
	getline(cin, temp);
	w.setType(temp);
	// nhap nghia
	temp = "";
	cout << "Nhap nghia "  << ": ";
	getline(cin, temp);
	w.setMean(temp);
	
	// nhap vi du
	temp = "";
	cout << "Nhap vi du " <<  ": ";
	getline(cin, temp);
	w.setExample(temp);
    tudien.Insert(w);
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
void timTuGoiY(HashTable &tudien, string input, int pos){
	int limit =0;
	int HIEN_THI = 10; // Hien thi toi da 10 goi y
	for(int i = 0;i<HT_SIZE;i++){
		string w = tudien.findByInput(i,input);
		if(limit<10 && w !="") {
			cout<<" "<<w<<endl;
			limit++;
		}
	} 
}

void xuLyTuDien(HashTable &tudien) {
	docFile(tudien);
	Word currentWord;
	string input = ""; // noi dung hien tai cua khung tim kiem
	int keyCode = 0;
	int pos = 0; // vi tri cua tu hien tai, vi tri thanh sang (highlight)

	while (true) { // vong lap vo tan
		veGiaoDienChinh(input);	// ve toan bo giao dien
		if(input != "") {
			gotoxy(0,18);
			timTuGoiY(tudien,input,pos+6);
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
				currentWord = timTu(tudien, input);
				if(currentWord.getWord() =="") veLoiKhongTimThayTu();
				else{
					veGiaoDienChiTietTu(currentWord);
				} 

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
				if (key == 80) { pos++; gotoxy(1,7+pos);} // DOWN
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


void kichThuocCuaSo(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void anThanhCuon(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void voHieuHoaKichThuocCuaSo()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
