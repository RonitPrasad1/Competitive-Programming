// Header Files:
#include <iostream>

template <typename DataType>
inline auto TrailingZeros (DataType Number) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    /* 651 in Binary = 00000000000000000000001010001011 [22 Trailing Zeros] */
    int64_t DecimalNumber = 651; 
    
    std::cout << TrailingZeros(DecimalNumber) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto TrailingZeros (DataType Number) -> int64_t
{
    int64_t TotalBits = (sizeof(Number) * 8), Result = 0;
    
    while (!(Number & (1 << (TotalBits - 1))))
    {
        Number <<= 1;
        ++Result;
    }
    
    return Result;
}
