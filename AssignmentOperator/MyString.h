#pragma once
#include <iostream>

class CMyString
{
public:
	CMyString(const char* vStr = nullptr);
	CMyString(const CMyString& vStr);
	virtual ~CMyString();
	
	CMyString& operator=(const CMyString& vStr);
	void printStr() { std::cout << m_pStr << std::endl; }

private:
	char* m_pStr = nullptr;
};