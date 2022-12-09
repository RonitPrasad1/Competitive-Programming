//43 points

/*
    Competition: HackerEarth
    Problem: ASME to SAME
    Author: Ron Prasad
    Date: 11-18-2022 
*/

// Header Files:
#include <iostream>
#include <set>
#include <string>
 
template <typename DataType>
inline auto isEqual (DataType S1, DataType S2)-> bool;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
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
        
        std::string Given;
        std::string True;
        
        std::cin >> Given;
        std::cin >> True;   
        
        if (isEqual(Given, True))
        {
            std::cout << "Yes" << '\n';
        }
        else
        {
            std::cout << "No" << '\n';
        }
    }

    return 0;
}

template <typename DataType>
inline auto isEqual (DataType S1, DataType S2)-> bool
{
    int64_t Length1 = S1.length();
    int64_t Length2 = S2.length();

    if (Length1 != Length2)
        return false;

    if (S1 == S2)
    {
       std::set <char> ASME(S1.begin(), S1.end());

       if (ASME.size() < S1.length())
       {
           return true;
       }
       
       return false;   
    }

    int64_t Previous = -1, Current = -1, Counter = 0;
    for (int64_t i = 0; i < Length1; ++i)
    {
        if (S1[i] != S2[i])
        {
            Counter++;
 
            if (Counter > 2)
                return false;
                
            Previous = Current;
            Current = i;
        }
    }
    
    return ((Counter == 2 && S1[Previous] == S2[Current] && S1[Current] == S2[Previous]));
}
