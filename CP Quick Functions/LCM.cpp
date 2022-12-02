/* Algorithm in a nutshell: [((x * y) / GCD(x, y))] */

// Header Files:
#include <iostream>
#include <string>

template <typename DataType>
inline auto LCM (DataType x, DataType y) -> std::string;

template <typename DataType>
inline auto GCD (DataType x, DataType y) -> int64_t;

template <typename DataType>
inline auto RussianPeasantAlgo (DataType x, DataType y) -> int64_t;

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
    
    std::cout << LCM(a, b) << '\n';
    
    return 0;
}

template <typename DataType>
inline auto LCM (DataType x, DataType y) -> std::string
{
    std::string largeNumber = " "; 
    
    largeNumber = (std::to_string(((RussianPeasantAlgo(x, y) / GCD(x, y)))));
        
    return largeNumber;
}

template <typename DataType>
inline auto GCD (DataType x, DataType y) -> int64_t
{
    int64_t Shift = 0;
    
    if (x == 0)
    {
        return y;
    }
    
    if (y == 0)
    {
        return x;
    }
    
    Shift = __builtin_ctz(x | y);
    x >>= __builtin_ctz(x);
 
  do 
  {
      int64_t Move = 0;
      
      y >>= __builtin_ctz(y);
      y -= x;
      Move = ((int64_t) y >> 31);
      x += (y & Move);
      y = ((y + Move) ^ Move);
      
  } while (y != 0);
  
  return (x << Shift);
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
