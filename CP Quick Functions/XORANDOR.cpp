// Header Files:
#include <iostream>

template <typename DataType>
inline auto XOR (DataType x, DataType y) -> int64_t;

template <typename DataType>
inline auto OR (DataType x, DataType y) -> int64_t;

template <typename DataType>
inline auto AND (DataType x, DataType y) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    
    int64_t a = 15, b = 20;
    
    std::cout << "Xor is: " << XOR(a, b) << '\n';
    std::cout << "OR is: " << OR(a, b) << '\n';
    std::cout << "AND is: " << AND(a, b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto XOR (DataType x, DataType y) -> int64_t 
{
    return (x ^ y);
}

template <typename DataType>
inline auto OR (DataType x, DataType y) -> int64_t 
{
    return (x | y);
}

template <typename DataType>
inline auto AND (DataType x, DataType y) -> int64_t 
{
    return (x & y);
}
