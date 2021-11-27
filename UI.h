#ifndef UI_H
#define UI_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "UIsystem.h"
#include "Word.h"
#define CR_KTK 50

void giaoDienMoUngDung();                           // Giao dien mo ung dung
void veGiaoDienChinh(string input);                 // Giao dien tim tu vung
void veGiaoDienChiTietTu(Word m);                   // Giao dien chi tiet tu vung
void veLoiKhongTimThayTu();                         // Ham tra ve giao dien khong tim thay tu
void veGoiY(int pos);

void giaoDienMoUngDung(){
	gotoxy(0,9);
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
	cout << "            <<<<<<<<<<<<<<<<<<<<<<<<<<<<<:"  << endl << endl << endl;
	cout << "   ------  ENGLISH - VIETNAMESE DICTIONARY  ------";
	
	gotoxy(0,40);
	cout << "                         from " << endl;
	cout << "                       ITF - Inc" << endl;
	
	Sleep(3000);
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
	cout << " " << char(254) << " Tab      : Them tu moi" << endl;
	cout << " Loi! Khong co tu nay" << endl;
}

void veGoiY(int pos){
	gotoxy(20,pos+18);
	cout<<"<--";
}
#endif
