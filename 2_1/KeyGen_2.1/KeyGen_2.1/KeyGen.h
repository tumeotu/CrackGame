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
	vector<unsigned long int> User;
	unsigned long int Serial1[2] = { 0x00 };
	unsigned long int Serial2[2] = { 0x00 };
	CString user;
	CString Key;
public:
	KeyGen();
	~KeyGen();

	void SetStr(const CString& a);
	CString GetUser();
	CString GetKey();
	CString DecToHex(unsigned long int n);
	CString USER();
	void Edit();

};

