#pragma once
#include "MyString.h"

class CTestMyStr
{
public:
	CTestMyStr() = default;
	~CTestMyStr() = default;

	void test_Normal();
	void test_SelfAssignment();
	void test_ContinousAssignment();
};