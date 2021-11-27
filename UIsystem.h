#ifndef UISYSTEM_H
#define UISYSTEM_H

#include <windows.h>
#include <conio.h>

void xoaManHinh();                                  // Xoa man hinh
void gotoxy(short x, short y);                      // Dat con tro tai toa do (x,y)
void doiMau(short x);                               // Ham thay doi textcolor va backgroundcolor
void kichThuocCuaSo(SHORT width, SHORT height);     // Thay doi kich thuoc cua so
void anThanhCuon(BOOL Show);                        // Ham an thanh scroll bar
void voHieuHoaKichThuocCuaSo();                     // Ham vo hieu hoa thay doi kich thuoc man hinh

void xoaManHinh() {
	system("cls");
}

void gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void doiMau(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
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

#endif
