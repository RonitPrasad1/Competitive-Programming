//60 points

/*
    Competition: HackerEarth
    Problem: Equal Parity
    Author: Ron Prasad
    Date: 10/25/2022
*/

// Header Files:
#include <stdio.h>
#include <stdlib.h>

// Driver Function:
int main (int argc, const char** argv)
{
    int64_t T, N;
    scanf("%lld", &T);
	
    int64_t EvenCounter = 0, OddCounter = 0;
    while (T--)
    {
        scanf("%lld", &N);
        
        int64_t *EqualParity = (int64_t*)malloc(2 * N * sizeof(int64_t));
        for (int64_t i = 0; i < (2 * N); ++i)
        {
            
            if (EqualParity[i] % 2 == 0)
            {
                ++EvenCounter;
            }
            
            if (EqualParity[i] % 2 != 0)
            {
                ++OddCounter;
            }
        }
        
        //printf("\r\nEven Count are: %d", EvenCounter);
        //printf("\r\nOdd Count are: %d", OddCounter);
        
        if (EvenCounter >= N)
        {
            printf("\nYES");
        }
        else if (OddCounter == (N * 2))
        {
            printf("\nNO");
        }
        // else if (OddCounter > EvenCounter)
        // {
        //     printf("\nNO");
        // }
        else if ((OddCounter / 2) >= EvenCounter)
        {
            printf("\nYES");
        }
        else if (OddCounter <= N)
        {
            printf("\nYES");
        }
        // else if (OddCounter >= N && OddCounter >= EvenCounter)
        // {
        //     printf("\nNO");
        // }
        else if (EvenCounter == OddCounter)
        {
            printf("\nYES");
        }
        else if ((OddCounter / 2) <= EvenCounter)
        {
            printf("\nYES");
        }
        else if ((EvenCounter / 2) >= OddCounter)
        {
            printf("\nYES");
        }
        else if ((EvenCounter / 2) < OddCounter)
        {
            printf("\nYES");
        }
        else if ((EvenCounter / 2) == (OddCounter / 2))
        {
            printf("\nYES");
        }
        else
        {
            printf("\nNO");
        }
    }

    return 0;
}
