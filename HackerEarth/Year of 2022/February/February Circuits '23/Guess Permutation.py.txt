# 10 points

# Import permutations module:
import itertools

# Function:
def guessPermutations():
    n = int(input())
    
    arrayB = [int(x) for x in input().split()]
    manualArray = list(range(1, n + 2))
    
    # Check all possible permutations for matched condition and print it out, then break:
    for perm in itertools.permutations(manualArray):
        newlyConstructedArray = [perm[i + 1] - perm[i] for i in range(n)]
        if all(newlyConstructedArray[i] == arrayB[i] for i in range(n)):
            print(*perm)
            return
    
    # If no permutations were found:
    print("-1")


# Testcase input:
t = int(input())
while t > 0:
    # Functional calling:
    guessPermutations()
    t -= 1
