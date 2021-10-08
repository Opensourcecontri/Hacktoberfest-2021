def fibonacci(input): # method where it calculates fibonacci
    x = 0 
    y = 1 # two variables assigned with consecutive values
    
    if input < 0:
        print("Incorrect input") # if the input is less than 0, then fibonacci can't exist for it
         
    elif input == 0:
        return 0 # if it's 0, then fibonacci = 0
       
    
    elif input == 1:
        return 1 # similarly if it's 1, then fibonacci = 10
    else:
        for i in range(1, input): # does the calculation for fibonacci
            z = x + y
            x = y
            y = z
        return b
 
print(fibonacci(12)) # calls the progrand prints fibonacci till 12