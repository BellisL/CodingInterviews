#pragma once
#define N_CHAR (0x80 - 0x20)

struct SHuffCh
{
	SHuffCh(char vCh = '^', int vWeight = 0) : Ch(vCh), Weight(vWeight) {}
	bool operator<(const SHuffCh& vHC) { return Weight < vHC.Weight; }
	bool operator==(const SHuffCh& vHC) { return Weight == vHC.Weight; }

	char Ch;
	int Weight;
};