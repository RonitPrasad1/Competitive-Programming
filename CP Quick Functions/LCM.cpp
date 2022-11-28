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
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);
    
    std::cout << "Enter the numbers for (a) and (b): " << '\n';
    
    int64_t a, b;
    std::cin >> a >> b;
    
    if (LCM(a, b) != -1)
    {
        std::cout << LCM(a, b) << '\n';
        
        std::exit(0);
    }
    else
    {
        std::cout << "Cannot use these numbers, retry!" << '\n';
    }
    
    return 0;
}

template <typename DataType>
inline auto LCM (DataType x, DataType y) -> int64_t
{
    if ((x != 0) && (y != 0))
    {
        return (static_cast <int64_t> (((x * y) / GCD(x, y))));
    }
    
    return -1;
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
