/*
    Competition: Codeforces Round #835 (Div. 4)
    Problem: "A: Medium Number"
    Date: 11/22/2022
*/

// Header Files:
#include <iostream>
#include <vector>
#include <algorithm>

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
	
	int64_t t, a, b, c;
	std::cin >> t;

	while (t--)
	{
		std::vector <int64_t> Store;
		std::cin >> a >> b >> c;
		
		Store.push_back(a);
		Store.push_back(b);
		Store.push_back(c);
		
		std::sort (Store.begin(), Store.end());
		
		std::cout << Store[1] << '\n';
	}
	
	return 0;
}
