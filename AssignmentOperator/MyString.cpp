#include "MyString.h"
#include <cstring>

//*****************************************************************************************
//FUNCTION:
CMyString::CMyString(const char * vStr)
{
	if (!vStr)
	{
		m_pStr = new char[1];
		m_pStr[0] = '\0';
	}
	else
	{
		size_t Length = strlen(vStr);
		m_pStr = new char[Length + 1];
		strcpy_s(m_pStr, Length + 1, vStr);
	}
}

//*****************************************************************************************
//FUNCTION: 这里一定是创建新的对象，不必像拷贝赋值函数那样考虑
CMyString::CMyString(const CMyString & vStr)
{
	size_t Length = strlen(vStr.m_pStr);
	m_pStr = new char[Length + 1];
	strcpy_s(m_pStr, Length + 1, vStr.m_pStr);
}

//*****************************************************************************************
//FUNCTION:
CMyString & CMyString::operator=(const CMyString & vStr)
{
	//1、初级写法：未考虑内存安全
	if (this == &vStr)
		return *this;

	delete[] m_pStr;
	m_pStr = nullptr;
	size_t Length = strlen(vStr.m_pStr);
	m_pStr = new char[Length + 1];	//可能会出现内存分配失败，而此时m_pStr已经删除，左侧实例失效，程序崩溃
	strcpy_s(m_pStr, Length + 1, vStr.m_pStr);

	//2、高级写法
	/*if (this != &vStr)
	{
		CMyString TempStr(vStr);

		char* pTemp = TempStr.m_pStr;
		TempStr.m_pStr = m_pStr;
		m_pStr = pTemp;
	}*/

	return *this;
}

//*****************************************************************************************
//FUNCTION:
CMyString::~CMyString()
{
	delete[] m_pStr;
	m_pStr = nullptr;
}
