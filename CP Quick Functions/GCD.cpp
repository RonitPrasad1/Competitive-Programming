// Header Files:
#include <iostream>

template <typename DataType>
inline auto GCD (DataType x, DataType y) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);

    constexpr static int64_t a = 15, b = 5;
    
    std::cout << GCD(a, b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto GCD (DataType x, DataType y) -> int64_t
{
    int64_t Shift;
    
    if (x == 0)
        return y;
    
    if (y == 0)
        return x;
    
    Shift = __builtin_ctz(x | y);
    x >>= __builtin_ctz(x);
 
  do 
  {
      int64_t Move;
      y >>= __builtin_ctz(y);
      y = (y - x);
      Move = ((int64_t) y >> 31);
      x += (y & Move);
      y = ((y + Move) ^ Move);
      
  } while (y != 0);
  
  return (x << Shift);
}
