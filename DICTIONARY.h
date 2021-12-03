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
		DICTIONARY(char *fileName);
		void xoaManHinh();                                           // Xoa man hinh
		void gotoxy(short x, short y);                               // Dat con tro tai toa do (x,y)
		void veGiaoDienChinh(string input);                          // giao dien tim tu vung
		void veGiaoDienChiTietTu(Word m);                            // giao dien chi tiet tu vung
		void doiMau(short x);                                        // Ham thay doi textcolor va backgroundcolor
		Word timTu(string word);                                     // Tim tu vung
		void suaTu(Word &w);                                         // Sua tu vung
		void themTuMoi();                                            // Nhap tu vung
		void docFile(char *fileName );                                              // Doc file
		void xuLyTuDien();                                           // Xu ly tu dien
		void timTuGoiY(Word *a, string input, int pos, int &size);   // Tim tu goi y
		void kichThuocCuaSo(SHORT width, SHORT height);              // Thay doi kich thuoc cua so
		void anThanhCuon(BOOL Show);                                 // Ham an thanh scroll bar
		void voHieuHoaKichThuocCuaSo();                              // Ham vo hieu hoa thay doi kich thuoc man hinh
		void veLoiKhongTimThayTu();                                  // Ham tra ve giao dien khong tim thay tu
		void veGoiY(int pos);                                        // Giao dien khong tim thay tu
		void giaoDienMoUngDung();                                    // Giao dien cho ung dung
};

DICTIONARY::DICTIONARY(char *fileName){
	SetConsoleTitle(" English-Vietnamese Dictionary ");
	this->docFile(fileName);
	this->kichThuocCuaSo(51,44);
	this->anThanhCuon(0);
	this->voHieuHoaKichThuocCuaSo();
	this->giaoDienMoUngDung();
	this->xuLyTuDien();
}


void DICTIONARY::giaoDienMoUngDung(){
	this->gotoxy(0,9);
	this->doiMau(10);
	cout << "            " << char(218);
	for(int i = 1 ; i <= 27 ; i++ ) cout << char(196);
	cout << char(191) << endl; 
	cout << "            " << char(179) << " ------------------------- " << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#########"; this->doiMau(10); cout<< " --------------- " << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#        "; this->doiMau(10); cout<< " --------------- " << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#        "; this->doiMau(10); cout<< " --------------- " << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#########"; this->doiMau(10); cout<< " -"; this->doiMau(12); cout <<" #           # "; this->doiMau(10); cout << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#        "; this->doiMau(10); cout<< " --"; this->doiMau(12); cout <<" #    ";this->doiMau(14); cout << char(3); this->doiMau(12); cout << "    #  "; this->doiMau(10); cout << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#        "; this->doiMau(10); cout<< " ---"; this->doiMau(12); cout <<" #       # "; this->doiMau(10); cout <<"- " << char(179)<< endl;
	cout << "            " << char(179) << " "; this->doiMau(12); cout << "#########"; this->doiMau(10); cout<< " ----"; this->doiMau(12); cout <<" #     # "; this->doiMau(10); cout <<"-- " << char(179)<< endl;
	cout << "            " << char(179) << " ---------------"; this->doiMau(12); cout <<" #   # "; this->doiMau(10); cout <<"--- " << char(179)<< endl;
	cout << "            " << char(179) << " ----------------"; this->doiMau(12); cout <<" # # "; this->doiMau(10); cout <<"---- " << char(179)<< endl;
	cout << "            " << char(179) << " -----------------"; this->doiMau(12); cout <<" # "; this->doiMau(10); cout <<"----- " << char(179)<< endl;
	cout << "            " << char(179) << " ------------------------- " << char(179)<< endl;
	cout << "            " << char(192);
	for(int i = 1 ; i <= 27 ; i++ ) cout << char(196);
	cout << char(217)<< endl << endl;
	this->doiMau(15);
	cout << "   ------  ENGLISH - VIETNAMESE DICTIONARY  ------";
	this->doiMau(14);
	this->gotoxy(0,40);
	cout << "                         from " << endl;
	cout << "                       ITF - Inc" << endl;
	Sleep(3500);
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
	this->doiMau(12);
	cout << " " << "TU DIEN ANH - VIET" << endl;	
	this->doiMau(14);
	cout << " " << char(254) << " Esc  : Thoat chuong trinh" << endl;
	cout << " " << char(254) << " Tab  : Them tu moi" << endl;
	cout << " " << char(254) << " Enter: Xem nghia cua tu" << endl;
	this->doiMau(11);
	
//  ve khung tim kiem
	cout << char(218); for (int i = 0; i < CR_KTK; i++) cout << char(196); cout << char(191) << endl; 
	cout << char(179) << input; for (int i = 0; i < CR_KTK - input.size(); i++) cout << char(255); cout << char(179);	
	cout << endl << char(192); for (int i = 0; i < CR_KTK; i++) cout << char(196); cout << char(217) << endl;
	
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
	m.display();
}

void DICTIONARY::veLoiKhongTimThayTu(){
	this->xoaManHinh();
	int dongHienTai = 0;
	
//  in ra cac huong dan
	cout << " " << char(254) << " Esc      : Ve lai man hinh chinh" << endl;
	cout << " " << char(254) << " Tab      : Them tu moi" << endl;
	cout << " Loi! Khong co tu nay" << endl;
}

Word DICTIONARY::timTu(string word){
	return this->TUDIEN.Find(word);
}
void DICTIONARY::suaTu(Word &w) {	
	Word tmp = w;
	
	// Qua trinh sua tu vung
	while (1) {
		string temp = ""; 
		this->xoaManHinh();
		char nhaplai;
		
		// Chi tiet tu vung hien tai
		this->doiMau(12);
		w.display();
		
		this->doiMau(14);
		cout << "   */ Sua tu : " << w.getWord() << endl;

		// Sua loai 
		while (1){
			this->doiMau(14);
			cout << " " << char(16) << " Sua loai tu : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if(temp != "") w.setType(temp);
			break;
		}
	
		// Sua nghia
		while (1){
			this->doiMau(14);
			cout << " " << char(16) << " Sua nghia : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if(temp != "") w.setMean(temp);
			break;
		}
		
		// Sua vi du
		while (1){
			this->doiMau(14);
			cout << " " << char(16) << " Sua vi du : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if(temp != "") w.setExample(temp);
			break;
		}
		
		// Hien thi lai tu vung sau khi sua
		this->xoaManHinh();
		doiMau(10);
	    w.display();
		
		// Kiem tra chac chan chua
		this->doiMau(14);
		cout << " <!!!> Ban co chac chan thay doi khong (c/k) ? "; cin >> nhaplai;
		if (nhaplai == 'c' || nhaplai == 'C') break;
		else {
			w = tmp;
			continue;	
		}
	}
	
	// Cap nhat tu vung sau khi chinh sua
	this->TUDIEN.update(w);
	
	// In ra thanh thong bao Da Sua Thanh Cong
	this->xoaManHinh();
	this->gotoxy(0,20);
	this->doiMau(14);
	cout << "               " << char(218); for (int i = 0; i < 23; i++) cout << char(196); cout << char(191) << endl;
	cout << "               " << char(179); this->doiMau(10); cout << "  DA SUA THANH CONG !  "; this->doiMau(14); cout << char(179) << endl;
	cout << "               " << char(192); for (int i = 0; i < 23; i++) cout << char(196); cout << char(217) << endl;
	Sleep(1500);
}

void DICTIONARY::themTuMoi() {
	// Mo file
	FILE *f;
    f = fopen("words.txt", "a+");
    Word w;
    
    // Qua trinh them tu moi
	while (1) {
		string temp = ""; 
		this->xoaManHinh();
		char nhaplai;
		
		this->doiMau(12);
		cout << "   " << char(3);
		this->doiMau(10);
		cout << " Them tu vung : " << endl << endl;
		
		// Nhap tu
		while (1){
			this->doiMau(14);	
			cout << " " << char(16) << " Nhap tu vung : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") { 
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if (temp == "") w.setWord("null");
			else w.setWord(temp);
			break;
		}

		// Nhap loai Tu 
		while (1){
			this->doiMau(14);
			cout << " "<< char(16) << " Nhap loai tu : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if (temp == "") w.setType("null");
			else w.setType(temp);
			break;
		}
	
		// Nhap Nghia Tu
		while (1){
			this->doiMau(14);
			cout << " "<< char(16) << " Nhap nghia tu vung : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if (temp == "") w.setMean("null");
			else w.setMean(temp);
			break;
		}
		
		// Nhap Vi Du
		while (1){
			this->doiMau(14);
			cout << " "<< char(16) << " Nhap vi du tu vung : ";
			fflush(stdin);
			getline(cin, temp);
			if (temp == "") {
				this->doiMau(12);
				cout << " " << char(19) << "/ Ki tu khong hop le !! Ban co muon nhap lai khong (c/k) ? ";
				cin >> nhaplai;
				if (nhaplai == 'c' || nhaplai == 'C') continue;
			}
			if (temp == "") w.setExample("null");
			else w.setExample(temp);
			break;
		}
		
		// Hien thi lai tu vung sau khi sua
		doiMau(10);
		this->xoaManHinh();
		w.display();
		
		// Kiem tra chac chan chua
		this->doiMau(14);
		cout << " <!!!> Ban co chac chan them tu moi khong (c/k) ? "; cin >> nhaplai;
		if (nhaplai == 'c' || nhaplai == 'C') break;
		else continue;
	}
	
	// Chen tu moi vao bang bam
	this->TUDIEN.Insert(w);
	
	// In ra thanh thong bao Da Them Thanh Cong
	this->xoaManHinh();
	this->gotoxy(0,20);
	this->doiMau(14);
	cout << "               " << char(218); for (int i = 0; i < 23; i++) cout << char(196); cout << char(191) << endl;
	cout << "               " << char(179); this->doiMau(10); cout <<"  DA THEM THANH CONG ! "; this->doiMau(14); cout << char(179) << endl;
	cout << "               " << char(192); for (int i = 0; i < 23; i++) cout << char(196); cout << char(217) << endl;
	Sleep(1500);
	
	// Cap nhat vao tu dien
    string www = w.getWord()+"/"+w.getType()+"/"+w.getMean()+";/"+w.getExample()+";/";
    const char *cstr = www.c_str();
    fprintf(f,cstr);
    fprintf(f, "\n");
    fclose(f);
}

void DICTIONARY::docFile(char* fileName) {
	ifstream fi(fileName); 	             // tim tap tin
	string dong;
	if (fi.is_open()) {                      // mo tap tin, kiem tra tap tin co ton tai hay khong
		while (getline(fi, dong)) {
			if (dong == "") {
				continue;
			}
			Word w(dong);
			this->TUDIEN.Insert(w);	
		}
		fi.close();                          // dong tap tin
	}
}

void DICTIONARY::timTuGoiY(Word *a, string input, int pos, int &size){
	// Hien thi toi da 10 goi y
	size = 10;
	this->TUDIEN.findByInput(a,input);
	for(int i = 0; i<10 ;i++){
		if(a[i].getWord() !=""){
			cout<<" "<<a[i].getWord()<<endl;
		} else {
			size = i;
			break;
		}
	}
}

void DICTIONARY::veGoiY(int pos){
	this->gotoxy(20,pos+18);
	this->doiMau(15);
	cout<< char(17) << char(196) << char(196);    // in ra mui ten co dang <-- tren moi goi y tu
}

void DICTIONARY::xuLyTuDien() {
	Word currentWord;
	string input = "";                            // Khoi tao noi dung cua khung tim kiem
	int keyCode = 0;
	int pos = 0;                                  // vi tri cua tu hien tai, vi tri thanh sang (highlight)
	Word *tugoiy = new Word[10];
	int goiy = 1;                                 // so luong goi y tu tim duoc
	string test = "";
	while (true) {
		this->veGiaoDienChinh(input);                      // ve toan bo giao dien
		
		// Nhap tu vung
		if(input != "") {
			this->gotoxy(0,18);
			this->timTuGoiY(tugoiy,input,pos+6,goiy);
			this->veGoiY(pos);
		}
		
		// Nhap tuy chon (Enter/Tab/escape)
		gotoxy(1 + input.size(), 16);
		keyCode = getch();                                 // tam dung chuong trinh, nhan ky tu nhap vao		
		switch (keyCode) {
			case 8:         // BACKSPACE
				// xoa ky tu cuoi
				input = input.substr(0, input.size() - 1); 
				break;
			case 9:         // TAB
				// Them tu moi
				this->themTuMoi();
				break;
			case 13:        // ENTER
				// vao man hinh chi tiet tu
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
						if (k == 8) {  // BACKSPACE
							// xoa tu nay
							// xoaTu(tudien, tuHienTai);
							input = ""; pos = 0;
							break; 
						}
						if (k == 9) {  // TAB
							// sua tu nay
							this->suaTu(tugoiy[pos]);
							input = ""; pos = 0;
							break;
						}
						if (k == 27) { // ESCAPE
							input = ""; pos = 0;
							break; 
						}
					} while (true);
				}
				break;
			case 27:        // ESCAPE
				this->doiMau(14);
				this->gotoxy(3,21);
				cout<<"----------------------------------------------";
				this->gotoxy(2,22);
				cout << "         "; this->doiMau(12); cout << char(3) ; this->doiMau(14); cout << " Thanks for using our app! "; this->doiMau(12); cout << char(3) ; this->doiMau(14); cout << "\n  Hope you had a great experience with this product";
				this->gotoxy(3,24);
				cout<<"----------------------------------------------";
				this->gotoxy(2, 27);
				this->doiMau(9);
				exit(EXIT_SUCCESS);     // thoat chuong trinh
				break;
			case 224: {     // UP & DOWN
				int key = getch();
				if (key == 72)  pos--;  // UP
				if (key == 80) {        // DOWN
					if(pos<goiy-1) pos++;
				}
				if (pos < 0) pos = 0;
				break;
			}
			default:        // cac ki tu trong bang chu cai
				if (keyCode >= 97 && keyCode <= 122) { // 'a' <= keyCode <= 'z'
					input += char(keyCode);
				}
		}
		
	};
}

void DICTIONARY::xoaManHinh() {
	system("cls");
}

void DICTIONARY::kichThuocCuaSo(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void DICTIONARY::anThanhCuon(BOOL Show) {
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void DICTIONARY::voHieuHoaKichThuocCuaSo() {
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void DICTIONARY::doiMau(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}

void DICTIONARY::gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}



#endif
