#include "stdafx.h"
#include "KeyGen.h"


KeyGen::KeyGen()
{
	user = "";
	Key = "";
}


KeyGen::~KeyGen()
{
	user.Delete(0, user.GetLength() - 1);
	Key.Delete(0, Key.GetLength() - 1);
}

void KeyGen::SetStr(const CString& a)
{
	user = a;
}
CString KeyGen::GetUser()
{
	return user;
}
CString KeyGen::GetKey()
{
	return Key;
}


// xu li user
CString KeyGen::DecToHex(unsigned long int n)
{
	CString hexaDeciNum;

	// counter for hexadecimal number array 
	int i = 0;
	while (n != 0)
	{
		// temporary variable to store remainder 
		int temp = 0;

		// storing remainder in temp variable. 
		temp = n % 16;

		// check if temp < 10 
		if (temp < 10)
		{
			hexaDeciNum.Insert(0, temp + 48);
			i++;
		}
		else
		{
			hexaDeciNum.Insert(0, temp + 55);
			i++;
		}
		n = n / 16;
	}
	while (hexaDeciNum.GetLength() != 8)
		hexaDeciNum.Insert(0, 48);
	return hexaDeciNum;
}

CString KeyGen::USER()
{
	int sum = 0, n = user.GetLength();
	for (int i = 0; i < n; i++)
	{
		sum += (int)user[i];
	}
	User.push_back(sum);
	int _3 = sum - 1;
	_3 = _3 * 3;
	User.push_back(_3);
	unsigned long int EAX = 0x12345678;
	for (int i = 0; i <= n; i++)
	{
		EAX = EAX ^ user[i];
		EAX = (EAX << 5) | (EAX >> (sizeof(unsigned long int) * 8 - 5));
	}
	unsigned long int Va = EAX;
	EAX = EAX % 0x7A69;
	User.push_back(EAX);

	Va = Va / 0x7A69;
	Va = Va & 0x0FFF;
	User.push_back(Va);



	//Ham 4011269
	Serial1[0] = User[0] + User[2];
	Serial1[1] = User[1] + User[3];


	//Ham 40128A
	Serial2[0] = User[0] * User[2] - User[1] * User[3];
	Serial2[1] = User[0] * User[3] + User[1] * User[2];

	Key += DecToHex(Serial1[0]);
	Key += '-';
	Key += DecToHex(Serial1[1]);
	Key += '-';
	Key += DecToHex(Serial2[0]);
	Key += '-';
	Key += DecToHex(Serial2[1]);
	return Key;
}