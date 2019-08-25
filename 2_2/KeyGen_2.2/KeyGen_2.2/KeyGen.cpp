#include "stdafx.h"
#include "KeyGen.h"


KeyGen::KeyGen()
{
	Key = "";
}


KeyGen::~KeyGen()
{
	Key.Delete(0, Key.GetLength() - 1);
}

void KeyGen::SetStr(CString a)
{
	string temp;
	string user = ConVertCStringToString(a);
	int n=user.length();
	// đưa string user vào mãng hex USER
	for (int i = 0; i < n; i++)
	{
		temp = ConverCharToHec(user[i]);
		USER.push_back(temp);
	}
	USER.push_back("00");
}



string KeyGen::ConverCharToHec(int a)
{
	string res;
	int temp1 = a % 16; // số 2
	a = a / 16;
	int temp2 = a % 16; // số 1
						// đưa số 1 vào string
	if (temp2 >= 10)
	{
		switch (temp2)
		{
		case 10:
			res += "A";
			break;
		case 11:
			res += "B";
			break;
		case 12:
			res += "C";
			break;
		case 13:
			res += "D";
			break;
		case 14:
			res += "E";
			break;
		case 15:
			res += "F";
			break;
		}
	}
	else
	{
		char temp = temp2 + 48;
		res += temp;
	}
	// đưa vào string
	if (temp1 >= 10)
	{
		switch (temp1)
		{
		case 10:
			res += "A";
			break;
		case 11:
			res += "B";
			break;
		case 12:
			res += "C";
			break;
		case 13:
			res += "D";
			break;
		case 14:
			res += "E";
			break;
		case 15:
			res += "F";
			break;
		}
	}
	else
	{
		char temp = temp1 + 48;
		res += temp;
	}

	return res;
}

int KeyGen::ConverHecToDec(string a)
{
	int res = 0;

	char temp2 = a[0];
	int hec = 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		char temp1 = a[i];

		switch (temp1)
		{
		case 'A':
			res = res + 10 * hec;
			break;
		case 'B':
			res = res + 11 * hec;
			break;
		case 'C':
			res = res + 12 * hec;
			break;
		case 'D':
			res = res + 13 * hec;
			break;
		case 'E':
			res = res + 14 * hec;
			break;
		case 'F':
			res = res + 15 * hec;
			break;
		default:
			int so = (a[i] - 48) * hec;
			res = res + so;
			break;
		}
		hec = hec * 16;
	}

	return res;
}

bool KeyGen::CheckUser(CString a)
{
	if (a.GetLength() < 4)
		return false;
	else
		return true;
}

void KeyGen::Crack1()
{
	int i = 0, j = 0;
	int n = USER.size() - 1;
	do
	{
		CL = USER[i + 1];
		BL = CL;
		int temp1 = ConverHecToDec(BL);
		int temp2 = ConverHecToDec(Data[j]);
		int c = temp1 ^ temp2;
		//char res = c;
		BL = ConverCharToHec(c);
		j++;
		USER[i + 1] = BL;
		Data[j - 1] = CL;
		if (j == 5)
		{
			j = 0;
		}
		i++;
	} while (i < n);
}

void KeyGen::Crack2()
{
	int i = 0, j = 0, n, m = USER.size();
	do
	{
		BL = Data[5 + j];
		n = m;
		n = n - i;
		n--;
		AL = USER[n];
		int temp1 = ConverHecToDec(BL);
		int temp2 = ConverHecToDec(AL);
		int c = temp1 ^ temp2;
		BL = ConverCharToHec(c);
		j++;
		USER[n] = BL;
		Data[4 + j] = AL;
		if (j == 5)
		{
			j = 0;
		}
		i++;
	} while (i < (m - 1));

}

void KeyGen::Crack3()
{
	int i = 0, j = 0, n = USER.size();
	do
	{
		AL = USER[1 + i];
		CL = Data[10 + j];
		int temp1 = ConverHecToDec(CL);
		int temp2 = ConverHecToDec(AL);
		int c = temp1 ^ temp2;
		CL = ConverCharToHec(c);
		j++;
		USER[1 + i] = CL;
		Data[9 + j] = AL;
		if (j == 5)
		{
			j = 0;
		}
		i++;
	} while (i < (n - 1));
}

void KeyGen::Crack4()
{
	int i = 0, j = 0, n = USER.size(), m;
	do
	{
		BL = Data[15 + j];
		m = n;
		m = m - i;
		m--;
		AL = USER[m];
		int temp1 = ConverHecToDec(BL);
		int temp2 = ConverHecToDec(AL);
		int c = temp1 ^ temp2;
		BL = ConverCharToHec(c);
		j++;
		USER[m] = BL;
		Data[14 + j] = AL;
		if (j == 5)
		{
			j = 0;
		}
		i++;

	} while (i < (n - 1));
}

void KeyGen::Crack5()
{
	// mang pass.
	int i, j = 0, n = USER.size();
	do
	{
		i = j;
		i = i & 3;
		BL = EAX[i];

		CL = USER[1 + j];
		int temp1 = ConverHecToDec(BL);
		int temp2 = ConverHecToDec(CL);
		int c = temp1 + temp2;
		BL = ConverCharToHec(c);
		j++;
		EAX[i] = BL;
	} while (j < (n - 1));
}	


CString KeyGen::GetKey()
{

	KeyGen::Crack1();
	KeyGen::Crack2();
	KeyGen::Crack3();
	KeyGen::Crack4();
	KeyGen::Crack5();

	string key = "";
	string key1 = "";
	for (int i = 3; i >= 0; i--)
	{
		key += EAX[i];
	}
	char KiTu;
	unsigned long int deckey = ConverHecToDec(key);
	int du = 0;
	do
	{
		du = deckey % 10;
		deckey = deckey / 10;
		du = du + 48;
		KiTu = du;
		key1 += KiTu;
	} while (deckey != 0);
	string KeyGen = "";
	for (int i = key1.length() - 1; i >= 0; i--)
	{
		KeyGen += key1[i];
	}
	Key = ConVertStringToCString(KeyGen);
	return Key;
}

string KeyGen::ConVertCStringToString(CString a)
{
	string Dest;
	int n = a.GetLength();
	for (int i = 0;i < n;i++)
	{
		Dest.insert(i, 1, a[i]);
	}
	return Dest;
}
CString KeyGen::ConVertStringToCString(string a)
{
	CString Dest;
	int n = a.length();
	for (int i = 0;i < n;i++)
	{
		Dest.Insert(i, char(a[i]));
	}
	return Dest;
}