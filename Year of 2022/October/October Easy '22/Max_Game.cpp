//100 points

/*
    Competition: HackerEarth
    Problem: Max Game
    Author: Ron Prasad
    Date: 09/30/2022
*/

// Header Files:
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);

	int64_t t, n;
	std::cin >> t;
	
	std::vector <int64_t> Store;
	while (t--)
	{
		std::cin >> n;
        
        int64_t Power = 2;
		while (Power <= n)
		{
		    Store.push_back (Power);
		    
		    Power *= 2;
		}
		
		std::sort (Store.begin(), Store.end(), std::greater <int64_t> ());
		
        std::cout << Store[0] << '\n';
		
		//Clear Memory:
		Store.clear();
	}
    
	return 0;
}