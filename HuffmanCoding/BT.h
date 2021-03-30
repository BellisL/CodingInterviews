#pragma once
#include <memory>

template<typename Type>
struct SBT
{
	SBT(Type vVar, std::shared_ptr<SBT<Type>> vpLeft = nullptr, std::shared_ptr<SBT<Type>> vpRight = nullptr) 
		: Value(vVar), pLeft(vpLeft), pRight(vpRight) {}

	bool isLeaf();
	bool hasLC();
	bool hasRC();

	Type Value;
	std::shared_ptr<SBT<Type>> pLeft = nullptr;
	std::shared_ptr<SBT<Type>> pRight = nullptr;
};

template<typename Type>
inline bool SBT<Type>::isLeaf()
{
	if (!pLeft && !pRight) return true;
	else return false;
}

template<typename Type>
inline bool SBT<Type>::hasLC()
{
	if (pLeft) return true;
	else return false;
}

template<typename Type>
inline bool SBT<Type>::hasRC()
{
	if (pRight) return true;
	else return false;
}
