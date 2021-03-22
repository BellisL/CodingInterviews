#pragma once
template<int N>
struct Sum_Solution_4
{
	enum 
	{
		Sum = N + Sum_Solution_4<N - 1>::Sum
	};
};

template<>
struct Sum_Solution_4<1>
{
	enum { Sum = 1 };
};