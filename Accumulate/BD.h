#pragma once
class CBase;
CBase* Array[2];

class CBase
{
public:
	virtual int sum(int vNum) { return 0; }
};

class CDerive : public CBase
{
public:
	virtual int sum(int vNum) { return Array[!!vNum]->sum(vNum - 1) + vNum; }
};