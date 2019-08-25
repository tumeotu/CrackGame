#pragma once
#include<iostream>
#include<windows.h>
#include<stdio.h> 
#include <atlstr.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


class KeyGen
{
private:

	string Data[20] = { "AA", "89", "C4", "FE", "46", 
						"78", "F0", "D0", "03", "E7",
						"F7", "FD", "F4", "E7", "B9",
						"B5", "1B", "C9", "50", "73" };


	string EAX[4] = { "00" };
	vector<string> USER;
	string CL, BL, AL;

	CString Key;
public:
	KeyGen();
	~KeyGen();

	bool CheckUser(CString a);

	void SetStr(CString a);
	CString GetUser();

	string ConverCharToHec(int a);
	int ConverHecToDec(string a);

	CString GetKey();

	void Crack1();
	void Crack2();
	void Crack3();
	void Crack4();
	void Crack5();
	string ConVertCStringToString(CString a);
	CString ConVertStringToCString(string a);

};

