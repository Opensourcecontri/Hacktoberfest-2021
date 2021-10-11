def isPalindrome(string):
	return string == string[::-1]

checkWord = str(input("Enter the the word to check: "))
checkFlag = isPalindrome(checkWord)

if checkFlag:
	print("Is palindrome")
else:
	print("Not a palindrome")

