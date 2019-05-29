'''
    Question :
    
    This problem was asked by Amazon.
    
    There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
    
    Given N, write a function that returns the number of unique ways you can climb the staircase.
    
    The order of the steps matters.
    
    For example, if N is 4, then there are 5 unique ways:
    
    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2
    
    What if, instead of being able to climb 1 or 2 steps at a time,
    
    you could climb any number from a set of positive integers X?
    
    For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
    
'''

'''
   
   This is dynamic programming way of solving the above problem.
   
   Recursive way is similar to Fibonacci recursion.
   
'''

dp = [0]*100


def countWays(n, steps):
    dp[0] = dp[1] = 1
    for i in range(2,n+1):
        for j in steps:
            if j<=i:
                dp[i] += dp[i-j]

    return dp[n]


n = int(input())
steps = [int(x) for x in input().split()]
print(countWays(n, steps))
