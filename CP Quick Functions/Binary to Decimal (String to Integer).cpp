// Header Files:
#include <iostream>

template <typename DataType>
inline auto binaryToDecimal (DataType n) -> int64_t;

constexpr static int64_t MOD = (int64_t)(1e9 + 7);

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    std::string a = "01010010101", b = "0101010101011101010";
    std::cout << "Value (A) in Decimal is: " << binaryToDecimal(a) << '\n';
    std::cout << "Value (B) in Decimal is: " << binaryToDecimal(b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto binaryToDecimal (DataType n) -> int64_t
{
    std::string Number = n;
    int64_t Value = 0, Base = 1;
    
    int64_t Length = (Number.length());
    for (int64_t i = (Length - 1); i >= 0; --i)
    {
        if (Number[i] == '1')
            Value += (Base % MOD) % MOD;
        Base = ((Base * 2) % MOD) % MOD;
    }
    
    return (Value % MOD);
}
