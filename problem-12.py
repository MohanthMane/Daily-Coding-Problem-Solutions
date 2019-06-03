'''
    Question:
    
    This problem was asked by Google.
    
    The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
    
    Hint: The basic equation of a circle is x2 + y2 = r2.
    
'''

'''
    Idea :
    
    Generate random points in 1x1 square (1000000 in this case).
    
    Area of circle inscribed in square divided by the area of square times 4 gives us the value of PI.
    
    (Radius = 1/2), (Side = 1).

    i.e; 4*(Circle Area) / (Square Area) = PI
    
'''
    

import random

def piEstimator():
    
    totalPoints = 1000000
    
    circlePoints = squarePoints = 0
    
    for i in range(totalPoints):
        x = random.uniform(-1.0,1.0)
        y = random.uniform(-1.0,1.0)
        
        if x*x + y*y <= 1.0:
            circlePoints += 1
        
        squarePoints += 1
    
    print(round(circlePoints/squarePoints,3) * 4)

piEstimator()
