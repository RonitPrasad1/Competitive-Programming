//Accepted!

/*
    Competition: Codeforces Round #836 (Div. 2)
    Problem: "B: XOR = Average"
    Date: 11/25/2022
*/

// Header Files:
#include <iostream>

template <typename DataType>
inline auto XOR (DataType a, DataType b) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    
    int64_t t, n;
    std::cin >> t;
	
	while (t--)
	{
		std::cin >> n;

		if (n % 2 == 1)
		{
			for (int64_t i = 0; i < n; ++i)
			{
				std::cout << "1" << " ";
			}
			
			std::cout << '\n';
		}
		else
		{
			for (int64_t i = 0; i < (n - 2); ++i)
			{
				std::cout << "2" << " ";
			
			}
			
			std::cout << "1" << " " << "3" << '\n';
		}
	}
	
	return 0;
}

template <typename DataType>
inline auto XOR (DataType a, DataType b) -> int64_t
{
	return (a ^ b);
}
