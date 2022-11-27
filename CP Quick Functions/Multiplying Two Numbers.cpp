// Header Files:
#include <iostream>

template <typename DataType>
inline auto RussianPeasantAlgo (DataType x, DataType y) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    int64_t a, b;
    std::cin >> a >> b;
    
    int64_t Answer = (RussianPeasantAlgo(a, b));
    std::cout << Answer << '\n';
    
    return 0;
}

template <typename DataType>
inline auto RussianPeasantAlgo (DataType x, DataType y) -> int64_t
{
    int64_t Result = 0;
    while (y > 0)
    {
        if (y & 1)
            Result += x;
            
        x <<= 1;
        y >>= 1;
    }
    
    return Result;
}
