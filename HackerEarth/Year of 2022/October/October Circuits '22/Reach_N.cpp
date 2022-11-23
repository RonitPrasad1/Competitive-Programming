//1 point

/*
    Competition: HackerEarth
	Problem: Reach N
    Author: Ron Prasad
    Date:10/7/2022
*/

// Header Files:
#include <iostream>
#include <array>
#include <cmath>

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
		
		int64_t *MinimumCost = new int64_t[n];
		
		int64_t Sum = 0;
		for (int64_t i = 0; i < n; ++i)
		{
		    std::cin >> MinimumCost[i];
		    
		    Sum += MinimumCost[i];
		}
		
		std::cout << Sum << '\n';
		
		// Clear Memory:
		delete[] MinimumCost;
	}

	return 0;
}
