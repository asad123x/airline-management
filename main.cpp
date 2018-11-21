#include<iostream>
#include "defination.cpp"


int main() 
{
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time

    CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
    GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
    font.dwFontSize.X = 10;
    font.dwFontSize.Y = 12;
    SetCurrentConsoleFontEx(outcon, false, &font);
    CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 25;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // L"Consolas"   Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    SetConsoleTextAttribute(outcon, 0x0d);
    
    Box( "WELCOME TO PAKISTAN AIRLINE",15);
	Box( "PRESS ANY KEY TO CONTINUE...",18);
	gotoxy(33, 32);
	getch();
  	Request();
  
}
