//90 points

/*
    Competition: HackerEarth
	Problem: Minimum Cost
    Author: Ron Prasad
    Date: 10/7/2022
*/

// Header Files:
#include <iostream>
#include <array>

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
		
		for (int64_t i = 0; i < n; ++i)
		{
		    std::cin >> MinimumCost[i];
		}
		
		if (n == n)
		{
		    std::cout << (n * n) << '\n';
		}
		else
		{
		    std::cout << (2 * (n * n) - 1) << '\n';
		}
		
		delete[] MinimumCost;
	}

	return 0;
}