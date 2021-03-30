#include "HuffChar.h"
#include "BT.h"
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>

typedef std::unordered_map<char, std::string> HashTable;
typedef std::shared_ptr<SBT<SHuffCh>> HuffPtr;
typedef std::list<HuffPtr> HuffForest;

void statisticsCnt(const std::string& vStr, std::vector<char>& vSet);
void initForest(const std::vector<char>& vStatis, HuffForest& vForest);
HuffPtr generateHuffTree(HuffForest& vForest);
HuffPtr minInForest(HuffForest& vForest);
void generateTable(HashTable& vTable, HuffPtr vpHuffTree);
void generateCT(std::string& vCode, HashTable& vTable, HuffPtr vpHuffCh);

void encode(HashTable& vTable, const std::string& vStr, std::string& vCodeStr);
void decode(HashTable& vTable, HuffPtr vpHuffTree, std::string& vCode);
void test(const char* vpTestName, const std::string& vStr);

int main()
{
	test("Test1", std::string("aaabbbbccc"));
	//test("Test2", std::string("aaa"));
	test("Test3", std::string("aaabbbb"));
	test("Test4", std::string("aaabbbccc"));
	test("Test5", std::string("aaabbbcccddd"));
	test("Test6", std::string("aabbbbcccddddd"));
	test("Test7", std::string("(&^$(^%YTUFJHgljhg"));

	return 0;
}

void statisticsCnt(const std::string & vStr, std::vector<char>& vSet)
{
	vSet.resize(N_CHAR);

	for (const auto& Ch : vStr)
	{
		if (Ch >= 0x20)
			++vSet[Ch - 0x20];
	}
}

void initForest(const std::vector<char>& vStatis, HuffForest & vForest)
{
	for (int i = 0; i < vStatis.size(); ++i)
	{
		if (vStatis[i] > 0)
			vForest.push_back(std::make_shared<SBT<SHuffCh>>(SHuffCh(i + 0x20, vStatis[i])));
	}
}

HuffPtr generateHuffTree(HuffForest & vForest)
{
	while (vForest.size() > 1)
	{
		auto Ptr1 = minInForest(vForest);
		auto Ptr2 = minInForest(vForest);

		HuffPtr Ptr = std::make_shared<SBT<SHuffCh>>(SHuffCh('^', Ptr1->Value.Weight + Ptr2->Value.Weight), Ptr1, Ptr2);
		vForest.push_back(Ptr);
	}

	return *vForest.begin();
}

HuffPtr minInForest(HuffForest & vForest)
{
	HuffPtr pNode = nullptr;
	int minWeight = INT_MAX;
	HuffForest::iterator Iter2BeDelete;

	for (HuffForest::iterator Iter = vForest.begin(); Iter != vForest.end(); ++Iter)
	{
		if ((*Iter)->Value.Weight < minWeight)
		{
			minWeight = (*Iter)->Value.Weight;
			pNode = *Iter;
			Iter2BeDelete = Iter;
		}
	}
	vForest.erase(Iter2BeDelete);

	return pNode;
}

void generateTable(HashTable & vTable, HuffPtr vpHuffTree)
{
	std::string Str = "";
	generateCT(Str, vTable, vpHuffTree);
}

void generateCT(std::string & vCode, HashTable & vTable, HuffPtr vpHuffCh)
{
	if (vpHuffCh->isLeaf())
	{
		vTable[vpHuffCh->Value.Ch] = vCode;
		return;
	}

	if (vpHuffCh->hasLC())
	{
		vCode += '0';
		generateCT(vCode, vTable, vpHuffCh->pLeft);
		vCode.erase(vCode.find_last_of('0'));
	}

	if (vpHuffCh->hasRC())
	{
		vCode += '1';
		generateCT(vCode, vTable, vpHuffCh->pRight);
		vCode.erase(vCode.find_last_of('1'));
	}
}

void encode(HashTable & vTable, const std::string & vStr, std::string& vCodeStr)
{
	int Length = 0;
	for (int i = 0; i < vStr.size(); ++i)
	{
		std::string pChCode = vTable[vStr[i]];
		if (!pChCode.empty())
		{
			std::cout << vStr[i] << " " << pChCode << std::endl;
			vCodeStr += pChCode;
		}
		else
		{
			throw std::runtime_error("Code can not be found!");
		}
	}
}

void decode(HashTable & vTable, HuffPtr vpHuffTree, std::string& vCode)
{
	auto Ptr = vpHuffTree;
	for (int i = 0; i < vCode.size(); ++i)
	{
		Ptr = vCode[i] == '0' ? Ptr->pLeft : Ptr->pRight;
		if (Ptr->isLeaf())
		{
			std::cout << Ptr->Value.Ch << " ";
			Ptr = vpHuffTree;
		}
	}
}

void test(const char * vpTestName, const std::string & vStr)
{
	std::cout << vpTestName << std::endl;

	std::vector<char> Statis;
	statisticsCnt(vStr, Statis);
	HuffForest HuffForest;
	initForest(Statis, HuffForest);
	auto pHuffTree = generateHuffTree(HuffForest);
	HashTable HuffTable;
	generateTable(HuffTable, pHuffTree);
	
	try
	{
		std::string codeStr;
		encode(HuffTable, vStr, codeStr);
		std::cout << codeStr << std::endl;
		decode(HuffTable, pHuffTree, codeStr);
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n";
}
