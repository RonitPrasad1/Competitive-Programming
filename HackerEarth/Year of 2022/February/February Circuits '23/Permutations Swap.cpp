// 100 points

/*
    Competition: HackerEarth
    Problem: Permutation Swaps
    Author: Ron Prasad
    Date: 02-22-2023
*/

// Header Files:
#include <iostream>
#include <set>

// Driver Function:
int main (int argc, const char** argv)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    int64_t t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        
        bool Flag = true;
        
        int64_t Migration = 0;
        
        std::set <int64_t> Counter; 
        for (int64_t idx = 1; idx <= n; ++idx)
        {
            int64_t Element;
            std::cin >> Element;
            
            Counter.insert(Element);
            
            if (((Element + Migration) >= idx) && (Counter.size() != n + 1))
            {
                Migration = ((Element + Migration) - idx);
            }
            else
            {
                Flag = false;
            }
        }
        
        if ((Flag == true) && Migration == 0)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }

    return 0;
}
