#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Word.h"
#include "HashTable.h"

#define CR_KTK 50
#ifndef DEF_DICTIONARY
#define DEF_DICTIONARY
using namespace std;
class DICTIONARY {
	private:
		HashTable TUDIEN;
	public:
		DICTIONARY();
		void xoaManHinh();                                           // Xoa man hinh
		void gotoxy(short x, short y);                               // Dat con tro tai toa do (x,y)
		void veGiaoDienChinh(string input);                          // giao dien tim tu vung
		void veGiaoDienChiTietTu(Word m);                            // giao dien chi tiet tu vung
		void doiMau(short x);                                        // Ham thay doi textcolor va backgroundcolor
		Word timTu(string word);                                     // Tim tu vung
		void khoiTaoTu(Word &w,string dong);                         // Ham khoi tao tu vung
		void suaTu(Word &w);                                         // Sua tu vung
		void themTuMoi();                                            // Nhap tu vung
		void docFile();                                              // Doc file
		void xuLyTuDien();                                           // Xu ly tu dien
		void timTuGoiY(Word *a, string input, int pos, int &size);   // Tim tu goi y
		void kichThuocCuaSo(SHORT width, SHORT height);              // Thay doi kich thuoc cua so
		void anThanhCuon(BOOL Show);                                 // Ham an thanh scroll bar
		void voHieuHoaKichThuocCuaSo();                              // Ham vo hieu hoa thay doi kich thuoc man hinh
		void veLoiKhongTimThayTu();                                  // Ham tra ve giao dien khong tim thay tu
		void veGoiY(int pos);                                        // Giao dien khong tim thay tu
		void giaoDienMoUngDung();                                    // Giao dien cho ung dung
};

void DICTIONARY::giaoDienMoUngDung(){
	this->gotoxy(0,9);
	this->doiMau(10);
	cout << "            <>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "            <---------------------------->" << endl;
	cout << "            <- \\\\          // ----------->" << endl;
	cout << "            <-- \\\\        // ------------>" << endl;
	cout << "            <--- \\\\      // ------------->" << endl;
	cout << "            <---- \\\\    // -- ######### ->" << endl;
	cout << "            <----- \\\\  // --- #         ->" << endl;
	cout << "            <------ \\\\// ---- #         ->" << endl;
	cout << "            <------- \\/ ----- ######### ->" << endl;
	cout << "            <--------  ------ #         ->" << endl;
	cout << "            <---------------- #         ->" << endl;
	cout << "            <---------------- ######### ->" << endl;
	cout << "            <---------------------------->" << endl;
	cout << "            <<<<<<<<<<<<<<<<<<<<<<<<<<<<<>"  << endl << endl << endl;
	this->doiMau(15);
	cout << "   ------  ENGLISH - VIETNAMESE DICTIONARY  ------";
	
	this->doiMau(14);
	this->gotoxy(0,40);
	cout << "                         from " << endl;
	cout << "                       ITF - Inc" << endl;
	
	Sleep(3500);
}

DICTIONARY::DICTIONARY(){
	SetConsoleTitle("English-Vietnamese Dictionary");  // Ham thay doi tieu de cua so
	this->kichThuocCuaSo(51,44);
	this->anThanhCuon(0);
	this->voHieuHoaKichThuocCuaSo();
	this->giaoDienMoUngDung();
	this->xuLyTuDien();
}

void DICTIONARY::xoaManHinh() {
	system("cls");
}


void DICTIONARY::gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void DICTIONARY::veGiaoDienChinh(string input) {
	this->xoaManHinh();
	
//	in ra cac thong tin ve de tai do an
	this->doiMau(12);
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
	
//	in ra cac option tuy chon khi thao tac voi tu dien
	this->doiMau(14);
	cout << " " << "TU DIEN ANH - VIET" << endl;	
	cout << " " << char(254) << " Esc  : Thoat chuong trinh" << endl;
	cout << " " << char(254) << " Tab  : Them tu moi" << endl;
	cout << " " << char(254) << " Enter: Xem nghia cua tu" << endl;
	this->doiMau(11);
	
//  ve khung tim kiem
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
	
//	dat con tro tai vi tri thanh tim kiem
	gotoxy(1 + input.size(), 9);
}

void DICTIONARY::veGiaoDienChiTietTu(Word m) {
	this->xoaManHinh();
	int dongHienTai = 0;
	
//  in ra cac huong dan
	this->doiMau(10);
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Sua tu nay" << endl;
	doiMau(14);
//  in ra cac chi tiet cua tu
	cout << endl << " " << m.getWord();
	cout << endl << " ---";
	cout << endl << " (" << m.getType() << "): ";
	cout <<m.getMean() << "; ";
	cout << endl << " ---"; 
	cout<< endl<<" "<<m.getExample();
}

void DICTIONARY::veLoiKhongTimThayTu(){
	this->xoaManHinh();
//  in ra cac huong dan
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Them tu moi" << endl;
	cout << " Loi! Khong co tu nay" << endl;
}

void DICTIONARY::doiMau(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}

Word DICTIONARY::timTu(string word){
	return this->TUDIEN.Find(word);
}

void DICTIONARY::khoiTaoTu(Word &w,string dong) {
	int i, pos;
	i = 0;
	
	// about/pho tu/khoang chung;sap;gan;/He is about to die;We're about to start;How about this?;
	// tach tu
	string word = "";
	while (dong[i] != '/') word += dong[i++];
	i++;
	w.setWord(word); // init word in class Word
	
	// tach loai tu
	string type = "";
	while (dong[i] != '/') type += dong[i++];
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

void DICTIONARY::suaTu(Word &w) {	
	

	while (1) {
		string temp = ""; 
		this->xoaManHinh();
		char nhaplai;
		
		this->doiMau(12);
		cout << endl << " " << w.getWord();
		cout << endl << " ---";
		cout << endl << " (" << w.getType() << "): ";
		cout << w.getMean() << "; ";
		cout << endl << " ---"; 
		cout<< endl<<" "<< w.getExample() << endl << endl;
		
		this->doiMau(14);
		cout << "   */ Sua tu : " << w.getWord() << endl;
		// Sua loai 
		while (1){
			cout << " - Sua loai tu : ";
			//cin.ignore();
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				cout << " <#> Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
				break;
			}
			//cout << temp << endl;
			w.setType(temp);
			//cout << w.getType();
			break;
		}
	
		// Sua nghia
		while (1){
			cout << " - Sua nghia : ";
			//cin.ignore();
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				cout << " <#> Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
				break;
			}
			w.setMean(temp);
			break;
		}
		
		// Sua vi du
		while (1){
			cout << " - Sua vi du : ";
			//cin.ignore();
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				cout << " <#> Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
				break;
			}
			w.setExample(temp);
			break;
		}
		
		// Hien thi lai tu vung sau khi sua
		doiMau(10);
		cout << endl << " " << w.getWord();
		cout << endl << " ---";
		cout << endl << " (" << w.getType() << "): ";
		cout << w.getMean() << "; ";
		cout << endl << " ---"; 
		cout<< endl<<" "<< w.getExample() << endl << endl;
		
		// Kiem tra chac chan chua
		this->doiMau(14);
		cout << " <!!!> Ban co chac chan thay doi khong (c/k) ? "; cin >> nhaplai;
		if (nhaplai == 'c' || nhaplai == 'C') {
			this->TUDIEN.update(w);
			break;
		} else continue;
	}
	this->xoaManHinh();
	this->gotoxy(0,20);
	this->doiMau(12);
	cout << "               " << char(218);
	for (int i = 0; i < 23; i++) {
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "               " << char(179) << "  DA SUA THANH CONG !  " << char(179);
	
	cout << endl << "               " << char(192);
	for (int i = 0; i < 23; i++) {
		cout << char(196);
	}
	cout << char(217);
	cout<<endl;
	Sleep(1500);
	            
	
	
//	this->xoaManHinh();
//	
//	cout << "Sua tu: '" << w.getWord()<< "':" << endl;
//	// Sua loai tu
//	string temp = "";
//	cout << "Sua loai tu (" << w.getType() << "): ";
//	getline(cin, temp);
//	if (temp == "") return;
//	w.setType(temp);
//
//	// Sua nghia
//	temp = "";
//	cout << "Sua nghia " <<  " (" << w.getMean() << "): ";
//	getline(cin, temp);
//	w.setMean(temp);
//
//	// Sua vi du
//	temp = "";
//	cout << "Sua vidu " <<  " (" << w.getExample() << "): ";
//	getline(cin, temp);
//	w.setExample(temp);
//	this->TUDIEN.update(w);
}

void DICTIONARY::themTuMoi() {
	FILE *f;
    f = fopen("words.txt", "a+");
    

    
	this->xoaManHinh();
	Word w;
	string temp = "";
	// nhap tu
	cout << "Nhap tu: ";
	getline(cin, temp);
	if (temp == "") return;
	else {
		w.setWord(temp);
	//	cout<<temp;
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
    this->TUDIEN.Insert(w);
    string www = w.getWord()+"/"+w.getType()+"/"+w.getMean()+";/"+w.getExample()+";/";
    const char *cstr = www.c_str();
    fprintf(f,cstr);
    fprintf(f, "\n");
    fclose(f);
}

void DICTIONARY::docFile() {
	ifstream fi("words.txt"); 	// tim tap tin
	string dong;
	if (fi.is_open()) { 		// mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
			if (dong == "") {
				continue;
			}
			Word w;
			this->khoiTaoTu(w,dong);
			this->TUDIEN.Insert(w);	
		}
		fi.close(); 			// dong tap tin
	}
}

void DICTIONARY::timTuGoiY(Word *a, string input, int pos, int &size){

	 // Hien thi toi da 10 goi y
	size = 10;
	this->TUDIEN.findByInput(a,input);
	for(int i = 0;i<10;i++){
		if(a[i].getWord() !=""){
			cout<<" "<<a[i].getWord()<<endl;
		}
		else{
			size = i;
			break;
		}
	}
	
/*		string w = tudien.findByInput(i,input);
		if(w!="")	cout<<" "<<w<<endl;
		
	if(limit<10 && w !="") {
			cout<<" "<<w<<endl;
			limit++;
		} */
	//} 
}

void DICTIONARY::veGoiY(int pos){
	this->gotoxy(20,pos+18);
	cout<<"<--";
}

void DICTIONARY::xuLyTuDien() {
	this->docFile();
	Word currentWord;
	string input = ""; // noi dung hien tai cua khung tim kiem
	int keyCode = 0;
	string test ="";
	int pos = 0; // vi tri cua tu hien tai, vi tri thanh sang (highlight)
	Word *tugoiy = new Word[10];
	int goiy=1; // so luong goi y tu tim duoc
	while (true) { // vong lap vo tan
		
		this->veGiaoDienChinh(input);	// ve toan bo giao dien
		
	//	gotoxy(1 + input.size(), 9);
		if(input != "") {
			this->gotoxy(0,18);
			this->timTuGoiY(tugoiy,input,pos+6,goiy);
			this->veGoiY(pos);
		}
	 
		gotoxy(1 + input.size(), 16);
		keyCode = getch(); // tam dung chuong trinh, nhan ky tu nhap vao		
		switch (keyCode) {
			case 8: // BACKSPACE
				input = input.substr(0, input.size() - 1); // xoa ky tu cuoi
				break;
			case 9: // TAB
				this->themTuMoi();
				break;
			case 13: // ENTER
				// vao man hinh chi tiet tu
				//
				test = tugoiy[pos].getWord().substr(0, input.size());
				if(tugoiy[pos].getWord() == ""|| input!=test) {
						int k;
							this->veLoiKhongTimThayTu();
				do {
					k = getch();
					if (k == 9) { // TAB
						// sua tu nay
					this->themTuMoi();
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
					else{
					this->veGiaoDienChiTietTu(tugoiy[pos]);
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
					this->suaTu(tugoiy[pos]);
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
				this->doiMau(14);
				this->gotoxy(3,21);
				cout<<"----------------------------------------------";
				this->gotoxy(2,22);
				cout << "           Thanks for using our app!\n  Hope you had a great experience with this product";
				this->gotoxy(3,24);
				cout<<"----------------------------------------------";
				this->gotoxy(2, 27);
				this->doiMau(9);
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

void DICTIONARY::kichThuocCuaSo(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void DICTIONARY::anThanhCuon(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void DICTIONARY::voHieuHoaKichThuocCuaSo()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
#endif
