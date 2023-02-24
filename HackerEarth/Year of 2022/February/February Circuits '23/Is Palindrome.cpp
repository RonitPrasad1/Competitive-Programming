// 100 points

/*
    Competition: HackerEarth
    Problem: Is Palindrome?
    Author: Ron Prasad
    Date: 02-24-2023
*/

// Header Files:
#include <iostream>
#include <string>
 
template <typename DataType>
inline auto isPalindrome (DataType str, int64_t l, int64_t r) -> bool;
 
// Driver Function:
int main (int argc, const char** argv)
{
    // FAST IO:
    std::ios::sync_with_stdio (NULL);
    std::cin.tie (nullptr);
    std::cout.tie (NULL);

    std::string givenMessage;
    std::cin >> givenMessage;    
    
    int64_t q;
    std::cin >> q;
    
    while (q--)
    {
        int64_t QueryNumber, l, r, substringLength;
        char ch;
        
        std::cin >> QueryNumber;
        
        if (QueryNumber == 1)
        {
            std::cin >> l >> r >> ch;
            substringLength = (r - l + 1);
            
            // Swaps ch with all other characters from (L, R):
            givenMessage.replace(l - 1, substringLength, substringLength, ch);
        }
        
        if (QueryNumber == 2)
        {
            std::cin >> l >> r;
            substringLength = (r - l + 1);
            
            // Find Substring from that given (L, R) for Query #2:
            std::string Substring = (givenMessage.substr(l - 1, substringLength));
            
            // Check if that Substring can be rearranged into a Palindrome:
            bool Solution = isPalindrome(Substring, 0, (substringLength - 1));
            
            std::cout << (Solution ? "Yes" : "No") << '\n';
        }
    }
    
    return 0;
}
 
// Bit Vector approach:
template <typename DataType>
inline auto isPalindrome (DataType str, int64_t l, int64_t r) -> bool
{
    int64_t BitVector = 0, Mask = 0;
    int64_t Length = (r - l + 1);
    for (int64_t i = 0; i < (Length / 2); ++i)
    {
        int64_t Temp = (int64_t)(str[i + l]);
        Mask = 1 << Temp;
        BitVector ^= Mask;
        
        Temp = (int64_t)(str[r - i]);
        Mask = 1 << Temp;
        BitVector ^= Mask;
    }
    
    if (Length % 2 != 0) 
    {
        int64_t middleIndex = (l + (Length / 2));
        int64_t Temp = (int64_t)(str[middleIndex]);
        
        Mask = 1 << Temp;
        BitVector ^= Mask;
    }
           
    return (BitVector & (BitVector - 1)) == 0;
}
