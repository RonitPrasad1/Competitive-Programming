//90 points

/*
    Competition: HackerEarth
    Problem: Lexicographic Smallest Array
    Author: Ron Prasad
    Date: 09/03/2022
*/

// Header Files:
#include <iostream>
#include <algorithm>

// Driver:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);
	
    int64_t n, k;
    std::cin >> n >> k;
    
    int64_t *LexicographicSmallestArray = new int64_t[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> LexicographicSmallestArray[i];
    }
    
    // Sort Array:
    std::sort (LexicographicSmallestArray, LexicographicSmallestArray + n);
    
    // Print:
    for (int64_t i = 0; i < n; ++i)
    {
        std::cout << LexicographicSmallestArray[i] << " ";
    }
    
    // Clear Memory:
    delete[] LexicographicSmallestArray;
    
    return 0;
}