#include <iostream>
#include <string>

bool hasPath(const char* vMatrix, int vRow, int vCol, const std::string& vStr);
bool trySearch(const char* vMatrix, int vRows, int vCols, int vRow, int vCol, const std::string& vStr, int vPathLength, bool* vIsVis);
void test(const char* vMatrix, int vRow, int vCol, const std::string& vStr);

int main()
{
	{
		const char* Matrix = "ABTGCFCSJDEH";
		const char* Str = "BFCE";

		test(Matrix, 3, 4, Str);
	}

	{
		const char* Matrix = "ABCESFCSADEE";
		const char* Str = "SEE";

		test(Matrix, 3, 4, Str);
	}

	{
		const char* Matrix = "ABTGCFCSJDEH";
		const char* Str = "ABFB";

		test(Matrix, 3, 4, Str);
	}

	{
		const char* Matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
		const char* Str = "SLHECCEIDEJFGGFIE";

		test(Matrix, 5, 8, Str);
	}

	{
		const char* Matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
		const char* Str = "SGGFIECVAASABCEHJIGQEM";

		test(Matrix, 5, 8, Str);
	}

	{
		const char* Matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
		const char* Str = "SGGFIECVAASABCEEJIGOEM";

		test(Matrix, 5, 8, Str);
	}

	{
		const char* Matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
		const char* Str = "SGGFIECVAASABCEHJIGQEMS";

		test(Matrix, 5, 8, Str);
	}

	{
		const char* Matrix = "AAAAAAAAAAAA";
		const char* Str = "AAAAAAAAAAAA";

		test(Matrix, 3, 4, Str);
	}

	{
		const char* Matrix = "AAAAAAAAAAAA";
		const char* Str = "AAAAAAAAAAAAA";

		test(Matrix, 3, 4, Str);
	}

	{
		const char* Matrix = "A";
		const char* Str = "A";

		test(Matrix, 1, 1, Str);
	}

	{
		const char* Matrix = "A";
		const char* Str = "B";

		test(Matrix, 1, 1, Str);
	}

	return 0;
}

bool hasPath(const char * vMatrix, int vRow, int vCol, const std::string & vStr)
{
	if (!vMatrix || vRow <= 0 || vCol <= 0 || vStr.empty()) return false;

	bool* IsVisited = new bool[vRow * vCol];
	memset(IsVisited, 0, vRow * vCol);

	int PathLength = 0;

	for (int i = 0; i < vRow; ++i)
		for (int k = 0; k < vCol; ++k)
		{
			if (trySearch(vMatrix, vRow, vCol, i, k, vStr, PathLength, IsVisited)) return true;
		}

	delete[] IsVisited;

	return false;
}

bool trySearch(const char * vMatrix, int vRows, int vCols, int vRow, int vCol, const std::string & vStr, int vPathLength, bool * vIsVis)
{
	if (vStr.size() == vPathLength) return true;

	bool hasPath = false;
	if (vRow >= 0 && vRow < vRows && vCol >= 0 && vCol < vCols && vStr[vPathLength] == vMatrix[vRow * vCols + vCol] && !vIsVis[vRow * vCols + vCol])
	{
		++vPathLength;
		vIsVis[vRow * vCols + vCol] = true;

		hasPath = trySearch(vMatrix, vRows, vCols, vRow - 1, vCol, vStr, vPathLength, vIsVis) ||
			trySearch(vMatrix, vRows, vCols, vRow, vCol - 1, vStr, vPathLength, vIsVis) ||
			trySearch(vMatrix, vRows, vCols, vRow + 1, vCol, vStr, vPathLength, vIsVis) ||
			trySearch(vMatrix, vRows, vCols, vRow, vCol + 1, vStr, vPathLength, vIsVis);

		if (!hasPath)
		{
			--vPathLength;
			vIsVis[vRow * vCols + vCol] = false;
		}
	}

	return hasPath;
}

void test(const char * vMatrix, int vRow, int vCol, const std::string & vStr)
{
	if (vMatrix && vRow > 0 && vCol > 0)
	{
		std::cout << "The matrix is:\n";
		for (int i = 0; i < vRow; ++i)
		{
			for (int k = 0; k < vCol; ++k)
			{
				std::cout << vMatrix[vCol * i + k] << " ";
			}
			std::cout << std::endl;
		}
	}

	if (!vStr.empty())
	{
		std::cout << "The Str is: " << vStr << std::endl;
	}

	if (hasPath(vMatrix, vRow, vCol, vStr))
		std::cout << "The path exists." << std::endl;
	else
		std::cout << "The path does not exist." << std::endl;

	std::cout << std::endl;
}
