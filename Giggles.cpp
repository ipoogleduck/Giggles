// Giggles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <Windows.h> // use < > for all system and library headers
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <ctime>
#include <fstream>
#include <atlstr.h>

using namespace std;

string closegiggles;
char letter;

int main()
{
	for (int n = 0; n < 5;) {
		CString str = "C:/Giggles/Giggles/giggle2.vbs";
		CString action = "open";
		ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
		Sleep(2000);

		//Check to close Giggles
		ifstream closegigglesreader("C:/Giggles/closegiggles.txt");
		if (!closegigglesreader) {

		}
		else {
			closegiggles = "";
			for (int i = 0; !closegigglesreader.eof(); i++) {
				closegigglesreader.get(letter);
				closegiggles += letter;
			}
			closegigglesreader.close();
			closegiggles.pop_back();

			if (closegiggles == "Close") {
				Sleep(5000);
				ofstream closegiggleswriter2("C:/Giggles/closegiggles.txt");
				if (!closegiggleswriter2) {
					cout << "Error opening file..." << endl;
				}
				else {
					closegiggleswriter2 << "  ";
					closegiggleswriter2.close();
				}
				return 0;
			}
			else if (closegiggles == "InstClose") {
				return 0;
			}
		}
	}
    return 0;
}

