//100 Points; no clue how because the problem is way more complicated, but this solution still passed - HackerEarth issue

/*
    Competition: HackerEarth
    Problem: Product Game
    Author: Ron Prasad
    Date: 12-2-2022 
*/

// Header Files:
#include <iostream>
#include <vector>
#include <algorithm>

constexpr static int64_t MOD = 1000000007;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    int64_t t, n, q, l, r;
    std::cin >> t;
    
    while (t--)
    {
        std::cin >> n;
        
        std::vector <int64_t> Product;
        std::vector <int64_t> Store;
        
        for (int64_t i = 0; i < n; ++i)
        {
            int64_t Element;
            std::cin >> Element;
            
            Product.push_back (Element);
        }
        
        int64_t CapitalPhiSummation = 1;
        
        std::cin >> q;
        for (int64_t Queries = 1; Queries <= q; ++Queries)
        {
            std::cin >> l >> r;
            
            for (int64_t i = l; i <= r; ++i)
            {
                CapitalPhiSummation = (CapitalPhiSummation * Product[i - 1]) % MOD;
            }
            
            Store.push_back (CapitalPhiSummation);
            
            CapitalPhiSummation = 1;
        }
        
        int64_t Max = *std::max_element(Store.begin(), Store.end());
        int64_t Min = *std::min_element(Store.begin(), Store.end());
        
        std::cout << (Max - Min) << '\n';
		
		// Clear Memory:
		Product.clear()
		Store.clear();
    }
    
    return 0;
}
