// 10 points

/*
    Competition: HackerEarth
    Problem: Minimum Score
    Author: Ron Prasad
    Date: 02-19-2023
*/
 
// Header Files:
#include <iostream>
#include <vector>
// #include <set>
#include <numeric> 
#include <algorithm>
 
template <typename DataType>
inline auto Partition (std::vector <int64_t>, DataType n, DataType k) -> void;
 
// Driver Function:
int main (int argc, const char** argv)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    int64_t n, k;
    std::cin >> n >> k;
    
    std::vector <int64_t> MinimumScore (n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> MinimumScore[i]; // [1, 0, 0, 1, 0, 0]
    }
    
    // Functional calling:
    Partition (MinimumScore, n, k);
 
    return 0;
}
 
// Manipulated K-Continuous Subarray function:
template <typename DataType>
inline auto Partition (std::vector <int64_t> binaryArray, DataType n, DataType k) -> void
{
    std::vector <std::pair <int64_t, int64_t>> Subarrays; // Vector to store the subarrays
    
    // Divide the array into k Subarrays of size (n / k):
    int64_t subarraySize = (n / k);
    for (int64_t i = 0; i < n; i += subarraySize) 
    {
        Subarrays.push_back({i, i + subarraySize - 1});
    }
    
    // Increment as we go along if the size of (n % k) is even:
    if (n % k != 0) 
    {
        Subarrays.push_back({n - (n % k), n - 1});
    }
    
    std::vector <int64_t> subarrayScore (Subarrays.size());
    
    std::vector <int64_t> minimumValue;
    for (int64_t i = 0; i < (Subarrays.size()); ++i) 
    {
        int64_t Maximum = (binaryArray[Subarrays[i].first]);
        int64_t Minimum = (binaryArray[Subarrays[i].first]);
        
        for (int64_t j = (Subarrays[i].first + 1); j <= (Subarrays[i].second); ++j) 
        {
            Maximum = (std::max(Maximum, binaryArray[j]));
            Minimum = (std::min(Minimum, binaryArray[j]));
        }
        
        minimumValue.push_back(Maximum - Minimum);
        
        subarrayScore[i] = (Maximum - Minimum);
    }
 
    // Find the k Subarrays with the minimum score:
    std::vector <int64_t> indices (Subarrays.size());
    
    std::iota (indices.begin(), indices.end(), 0);
    
    std::partial_sort (indices.begin(), indices.begin() + k, indices.end(), 
    [&subarrayScore] (int64_t i, int64_t j) 
    {
        return (subarrayScore[i] < subarrayScore[j]);
    });
 
    // Output the starting and ending indices of the k Subarrays with the minimum score:
    std::vector <std::pair <int64_t, int64_t>> result;
    for (int64_t i = 0; i < k; ++i) 
    {
        result.push_back(Subarrays[indices[i]]);
    }
    
    // Remove all 0's from the solution container:
    minimumValue.erase(std::remove(minimumValue.begin(), minimumValue.end(), 0), minimumValue.end());
    
    // Sort for the smallest:
    std::sort (minimumValue.begin(), minimumValue.end());
    
    // Print the first (smallest):
    std::cout << minimumValue[0] << '\n';
    
    // Sort from Least -> Greatest:
    std::sort (result.begin(), result.end());
    
    // Print the Pair of Subarrays (First, Last):
    for (auto i : result) 
    {
        std::cout << (i.first + 1) << " " << (i.second + 1) << '\n';
    }
}
