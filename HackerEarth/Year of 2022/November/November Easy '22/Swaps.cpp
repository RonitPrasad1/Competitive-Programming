//100 points

/*
    Competition: HackerEarth
    Problem: Swaps
    Author: Ron Prasad
    Date: 11/04/2022
*/

// Header Files:
#include <iostream>
#include <vector>
#include <algorithm>

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
	std::ios::sync_with_stdio (false);
	std::cin.tie (static_cast <std::ostream*> (0));

	int64_t t, n;
	std::cin >> t;
	
	while (t--)
	{
		std::cin >> n;
		std::vector <int64_t> Swaps (n, 0);
		
		for (int64_t i = 0; i < n; ++i)
		{
		    std::cin >> Swaps[i];
		}
		
		// Sorting:
        std::sort (Swaps.begin(), Swaps.end());
    
        for (auto i : Swaps)
        {
            std::cout << i << " ";
        }
        
        std::cout << '\n';
        
        Swaps.clear();
	}
    
	return 0;
}
