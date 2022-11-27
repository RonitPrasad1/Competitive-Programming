// Header Files:
#include <iostream>

template <typename DataType>
inline auto Power (DataType x, DataType y, DataType MOD) -> int64_t;

constexpr static int64_t MOD = (1e9 + 7);

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(nullptr);

    constexpr static int64_t a = 5, b = 16;
    
    std::cout << Power(a, b, MOD) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto Power (DataType x, DataType y, DataType MOD) -> int64_t
{
    if (y == 0)
        return 1;
        
    int64_t pBE = (Power(x, (y / 2), MOD) % MOD);
    
    pBE = ((pBE * pBE) % MOD);
 
    return ((y % 2 == 0) ? pBE : (x * pBE) % MOD);
}
