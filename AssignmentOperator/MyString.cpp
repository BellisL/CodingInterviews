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
//FUNCTION: ����һ���Ǵ����µĶ��󣬲����񿽱���ֵ������������
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
	//1������д����δ�����ڴ氲ȫ
	if (this == &vStr)
		return *this;

	delete[] m_pStr;
	m_pStr = nullptr;
	size_t Length = strlen(vStr.m_pStr);
	m_pStr = new char[Length + 1];	//���ܻ�����ڴ����ʧ�ܣ�����ʱm_pStr�Ѿ�ɾ�������ʵ��ʧЧ���������
	strcpy_s(m_pStr, Length + 1, vStr.m_pStr);

	//2���߼�д��
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
