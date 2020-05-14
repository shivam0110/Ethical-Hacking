#include <windows.h>

using namespace std;

void hidewindow(){
    //Hide Console 
	HWND stealth;	
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0); //0 coz hiding this one and showing another window
}

void main(){
    hidewindow();
}