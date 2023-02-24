# 100 points

# Minimized Function:
def AlicesSweets():
    # Input format:
    n = int(input())
    sweetBoxA = list(map(int, input().split()))
    sweetBoxB = list(map(int, input().split()))
    sweetBoxC = list(map(int, input().split()))
    
    # Pre-sort the arrays for faster computation:
    sweetBoxA.sort()
    sweetBoxB.sort()
    sweetBoxC.sort()
    
    minDifference = float('inf')
    
    i = 0
    j = 0
    k = 0
    
    # Iterate over all possible combinations of sweets from the three boxes
    while (i < n and j < n and k < n):
        Difference = abs(sweetBoxA[i] - sweetBoxB[j]) + abs(sweetBoxB[j] - sweetBoxC[k]) + abs(sweetBoxC[k] - sweetBoxA[i])
        
        # Find the smallest form all combinations:
        if (Difference < minDifference):
            minDifference = Difference

        # Continue moving:
        if (sweetBoxA[i] <= sweetBoxB[j] and sweetBoxA[i] <= sweetBoxC[k]):
            i = (i + 1)
        elif (sweetBoxB[j] <= sweetBoxA[i] and sweetBoxB[j] <= sweetBoxC[k]):
            j = (j + 1)
        else:
            k = (k + 1)

    return minDifference

# Functional calling:
minimizedValue = AlicesSweets()
print(minimizedValue)
