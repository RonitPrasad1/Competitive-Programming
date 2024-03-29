// 100 points

/*
    Competition: HackerEarth
    Problem: Special Subarray
    Author: Ron Prasad
    Date: 02-19-2023
*/

// Header Files:
#include <iostream>
#include <vector>

template <typename DataType>
inline auto subarrayXorSum (std::vector <int64_t>& Special, DataType n) -> int64_t;

// Driver Function:
int main (int argc, const char** argv)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);

    int64_t t;
    std::cin >> t;

    while (t--) 
    {
        int64_t n;
        std::cin >> n;
    
        std::vector<int64_t> Special (n);
        for (int64_t i = 0; i < n; ++i) 
        {
            std::cin >> Special[i];
        }
    
        int64_t Solution = subarrayXorSum(Special, n);
        
        std::cout << Solution << '\n';
    }
    
    return 0;
}

template <typename DataType>
inline auto subarrayXorSum (std::vector<int64_t>& Special, DataType n) -> int64_t
{
    int64_t LeftStart = 0, RightEnd = 0, specialSubArrayCounter = 0;
    
    int64_t xorSum = 0, Sum = 0;
    while (RightEnd < n) 
    {
        xorSum ^= Special[RightEnd];
        Sum += Special[RightEnd];
        
        while ((xorSum != Sum) && (LeftStart <= RightEnd))
        {
            // Reduce Window size from the left:
            xorSum ^= Special[LeftStart];
            Sum -= Special[LeftStart];
            
            ++LeftStart;
        }
        
        if (xorSum == Sum) 
        {
            specialSubArrayCounter += (RightEnd - LeftStart + 1);
        }
        
        ++RightEnd;
    }
    
    return specialSubArrayCounter;
}
