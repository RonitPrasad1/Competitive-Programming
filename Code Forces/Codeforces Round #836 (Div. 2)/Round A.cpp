//Accepted!

/*
    Competition: Codeforces Round #836 (Div. 2)
    Problem: "A: SSeeeeiinngg DDoouubbllee"
    Date: 11/25/2022
*/

// Header Files:
#include <iostream>
#include <string>
#include <algorithm>

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    
    int64_t t;
    std::cin >> t;
    
    std::string PalindromeString, HoldOriginal = " ";
    while (t--)
    {
        std::cin >> PalindromeString;
        
        HoldOriginal = PalindromeString;
        
        reverse(HoldOriginal.begin(), HoldOriginal.end());
        std::cout << PalindromeString << HoldOriginal << '\n';
    }
    
    return 0;
}
