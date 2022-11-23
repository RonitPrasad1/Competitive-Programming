//100 points

/*
    Problem: Good Pairs
    Competition: HackerEarth
    Author: Ron Prasad
    Date: 09/03/2022
*/

// Header Files:
#include <iostream>

//Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);

	int64_t t, Number;
	std::cin >> t;
	
	int64_t EvenCount = 0;
	int64_t OddCount = 0;

	while (t--)
	{
		std::cin >> Number;
		
		while (Number > 0)
		{
		    int64_t Digit = (Number % 10);
		    Number /= 10;
		    
		    if (Digit % 2 == 0)
		    {
			++EvenCount;
	            }
		    else
	            {
			++OddCount;
	            }
		}
		
		// Debug:
		// std::cout << EvenCount << '\n';
		// std::cout << OddCount << '\n';
		
		std::cout << (OddCount * EvenCount) << '\n';
		
		EvenCount = 0;
		OddCount = 0;
	}
    
	return 0;
}