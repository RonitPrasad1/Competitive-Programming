// Header Files:
#include <iostream>

template <typename DataType>
inline auto Combinations (DataType n, DataType r) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
     // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    constexpr static int64_t a = 15, b = 5;
    
    std::cout << Combinations(a, b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto Combinations (DataType n, DataType r) -> int64_t
{
    if (r == 0) 
        return 1;

    if (r > n / 2) 
        return Combinations(n, n - r); 

    int64_t Result = 1; 
    for (int64_t k = 1; k <= r; ++k)
    {
        Result = (Result * (n - k + 1));
        Result = (Result / k);
    }

    return Result;
}
