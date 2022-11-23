//18 points

/*
    Competition: HackerEarth
    Problem: Arithmetic Sequence by Exactly One Move
    Author: Ron Prasad
    Date: 10/24/2022
*/

// Header Files:
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

template <typename DataType>
inline auto EdgeCase (std::vector <DataType> const &Vec) -> bool;

template <typename DataType>
inline auto ArithmeticChecker (std::vector <DataType> Ath, DataType SIZE) -> bool;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);

	int64_t t, n;
	std::cin >> t;
	
	while (t--)
	{
	    std::cin >> n;
	    
	    std::vector <int64_t> ArithmeticSequence(n);
	    std::map <int64_t, std::pair<int64_t, int64_t>> mPairs;
	    std::unordered_map <int64_t, int64_t> Hash;
	    
	    for (int64_t i = 0; i < n; ++i)
	    {
	        std::cin >> ArithmeticSequence[i];
	    }
	    
	    if (EdgeCase(ArithmeticSequence) == 1)
	    {
	        std::cout << "NO" << '\n';
	    }
	    else if (ArithmeticChecker(ArithmeticSequence, n))
	    {
	        std::cout << "YES" << '\n';
	    }
	   // else if (n == 4)
	   // {
	   //     //Case where you check both:
	   // }
	    else if (n % 2 == 0) //Even length of Array
	    {
	        int64_t Differences = 0;
	        
	        std::vector <int64_t> StoredDifferences;
            for (int64_t i = 0; i < n; i += 2)
            {
                mPairs.insert({i, std::pair (ArithmeticSequence[i], ArithmeticSequence[i + 1])});
	        }
	        
            for (const auto& Ele : mPairs)
            {
                Differences = std::abs(Ele.second.first - Ele.second.second);
                StoredDifferences.push_back (Differences);
                
                //std::cout << Differences << '\n';
            }
            
            int64_t NonDuplicateElement, NonDuplicateElementsIndex;
            for (int64_t i = 0; i < (n / 2 + 1); ++i)
            {
                ++Hash[StoredDifferences[i]];
            }
            
            for (int64_t i = 0; i < (Hash.size()); ++i)
            {
                if (Hash[StoredDifferences[i]] == 1)
                {
                    NonDuplicateElement = StoredDifferences[i];
                }
            }
            
            NonDuplicateElementsIndex = StoredDifferences[NonDuplicateElement];
			
            std::cout << (NonDuplicateElementsIndex * 2) << '\n';     
	    }
	    else if (n % 2 != 0)
	    {
	        int64_t Differences = 0;
	        
	        std::vector <int64_t> StoredDifferences;
	        for (int64_t i = 0; i < n; i += 2)
            {
                mPairs.insert({i, std::pair(ArithmeticSequence[i], ArithmeticSequence[i + 1])});
            }
            
            //std::cout << ArithmeticSequence[n - 2] << " " << ArithmeticSequence[n - 1];
            
            mPairs.erase(prev(mPairs.end()));
            
            // Manually Added [Second to Last & Last Piar]:
            mPairs.insert({(n / 2 + 2), std::pair(ArithmeticSequence[n - 2], ArithmeticSequence[n - 1])});
            
            for (const auto& Ele : mPairs)
            {
                Differences = std::abs(Ele.second.first - Ele.second.second);
                StoredDifferences.push_back (Differences);
                
                //std::cout << Differences << '\n';
            }
            
            int64_t NonDuplicateElement, NonDuplicateElementsIndex;
            for (int64_t i = 0; i < (n / 2 + 1); ++i)
            {
                ++Hash[StoredDifferences[i]];
            }
            
            for (int64_t i = 0; i < (Hash.size()); ++i)
            {
                if (Hash[StoredDifferences[i]] == 1)
                {
                    NonDuplicateElement = StoredDifferences[i];
                }
            }
            
            NonDuplicateElementsIndex = StoredDifferences[NonDuplicateElement];
			
            //std::cout << (NonDuplicateElementsIndex * 2) << '\n';
	    }

	    //std::cout << '\n';
	    
        // //Print Map of Pairs:
        //std::cout << "The Map of Pairs hold: " << '\n';
        // for (const auto& Ele : mPairs)
        // {
        //     std::cout << "Key (" << Ele.first << "): " << "[" << Ele.second.first << ", " << Ele.second.second << "]" << '\n';
        // }
        
        //Clearing Vector:
        ArithmeticSequence.clear();
	}
    
	return 0;
}

template <typename DataType>
inline auto EdgeCase (std::vector <DataType> const &Vec) -> bool
{
    if (Vec.size() == 0)
        return false;
    
    for (int64_t i = 0; i < (Vec.size()); ++i)
    {
        if (Vec[0] != Vec[i])
        {
            return false;
        }
    }
    
    return true;
}

template <typename DataType>
inline auto ArithmeticChecker (std::vector <DataType> Arithmetic, DataType SIZE) -> bool
{
    if (SIZE == 1)
        return true;
    
    // Sort:
    std::sort(Arithmetic.begin(), Arithmetic.end());
    
    // First Pair Diff:
    int64_t Difference = (Arithmetic[1] - Arithmetic[0]);
    
    for (int64_t i = 2; i < SIZE; ++i)
    {
        if (Arithmetic[i] - Arithmetic[i - 1] != Difference)
        {
            return false;
        }
    }
    
    return true;
}
