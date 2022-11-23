//100 Points

/*
    Competition: HackerEarth
    Problem: Candy in the box
    Author: Ron Prasad
    Date: 09/17/2022
*/

#include <iostream>
#include <cmath>

//Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);

	int64_t t, n, k;
	std::cin >> t;
	
	while (t--)
	{
	    std::cin >> n >> k;
	    
	    int64_t Total = (k % (2 * (n - 1)))
	    
        if (k <= n)
        {
            std::cout << k << '\n';
        }
        else if (Total == 0)
        {
            std::cout << "2" << '\n';
        }
        else
        {
            if (Total <= n)
            {
                std::cout << Total << '\n';
            }
            else
            {
                std::cout << (n - (Total - n)) << '\n';
            }
        }
	}
	
	return 0;
}
