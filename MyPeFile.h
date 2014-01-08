// MyPeFile.h: interface for the MyPeFile class.
//
//////////////////////////////////////////////////////////////////////
#include "SecName.h"
#if !defined(AFX_MYPEFILE_H__A25D0111_7EA6_47AF_80A3_B33B4159D2C5__INCLUDED_)
#define AFX_MYPEFILE_H__A25D0111_7EA6_47AF_80A3_B33B4159D2C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MyPeFile  
{
public:
	MyPeFile();
	virtual ~MyPeFile();
	IMAGE_DOS_HEADER dosHeader;
	IMAGE_NT_HEADERS ntHeader;
	int numSection;
	IMAGE_SECTION_HEADER secHeader;
	SecName secname[10];


};

#endif // !defined(AFX_MYPEFILE_H__A25D0111_7EA6_47AF_80A3_B33B4159D2C5__INCLUDED_)
