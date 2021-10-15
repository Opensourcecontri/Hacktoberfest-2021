str1 = input("Enter any string to check that is palindrom or not: " )

temp = str1.lower()
print(temp)

str2 = temp[::-1]
print(str2)

if temp == str2:
    print("This string '",str1,"' is a palindrom.")
else:
    print("This string '",str1,"' is not a palindrom.")
    
