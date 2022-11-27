/* Algorithm in a nutshell: [((x * y) / GCD(x, y))] */

// Header Files:
#include <iostream>

template <typename DataType>
inline auto LCM (DataType x, DataType y) -> int64_t;

template <typename DataType>
inline auto GCD (DataType x, DataType y) -> int64_t;

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    
    int64_t a = 15, b = 20;
    
    std::cout << LCM(a, b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto LCM (DataType x, DataType y) -> int64_t
{
    return static_cast <int64_t> (std::ceil(((x * y) / GCD(x, y))));
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
      y -= x;
      Move = ((int64_t) y >> 31);
      x += (y & Move);
      y = ((y + Move) ^ Move);
      
  } while (y != 0);
  
  return (x << Shift);
}
