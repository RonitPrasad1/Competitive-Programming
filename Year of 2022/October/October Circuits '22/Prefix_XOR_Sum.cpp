//20 points

/*
    Competition: HackerEarth
	Problem: Prefix Xor Sum
    Author: Ron Prasad
    Date: 10/25/2022
*/

// Header Files:
#include <iostream>
#include <array>

template <typename DataType>
inline std::size_t PrefixXorSum (DataType *PXS, DataType SIZE, DataType Left, DataType Right);

// Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
    // FAST IO:
	std::ios::sync_with_stdio (false);
	std::cin.tie (static_cast <std::ostream*>(0));

	int64_t N, Q, L, R;
	scanf("%lld %lld", &N, &Q);
	
    int64_t *XorSum = (int64_t*)malloc(N * sizeof(int64_t));
    for (int64_t i = 0; i < N; ++i)
    {
        scanf("%lld", &XorSum[i]);
    }

    while (Q--)
    {
        scanf("%lld %lld", &L, &R);
        
        printf("%lld\n", PrefixXorSum(XorSum, N, L - 1, R - 1));
    }
    
	return 0;
}

template <typename DataType>
inline std::size_t PrefixXorSum (DataType *PXS, DataType SIZE, DataType Left, DataType Right)
{
    std::size_t prevSum = 0, SecondPrevious = 0;
    if (Right > Left + 1)
    {
        SecondPrevious = PrefixXorSum(PXS, SIZE, Left, Right - 2);
        prevSum = SecondPrevious + (SecondPrevious ^ PXS[Right - 1]);

        return prevSum + ((prevSum - SecondPrevious) ^ PXS[Right]);
    }
    
    if (Right == Left + 1)
    {
        return PXS[Right - 1] + (PXS[Right - 1] ^ PXS[Right]);
    }
    
    if (Right == Left)
    {
        return (PXS[Right]);
    }
    
    return 0;
}