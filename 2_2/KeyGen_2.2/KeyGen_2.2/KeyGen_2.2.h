
// KeyGen_2.2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CKeyGen22App:
// See KeyGen_2.2.cpp for the implementation of this class
//

class CKeyGen22App : public CWinApp
{
public:
	CKeyGen22App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CKeyGen22App theApp;
