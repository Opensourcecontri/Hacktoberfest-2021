package main

import "fmt"

func isPalindrome(x int) bool {
	originalNumber := x

	if x < 0{
		return false
	}

	reversedNumber := x % 10
	x = x / 10

	if x > 0{
		for x > 0{
			reversedNumber = reversedNumber * 10 + x % 10
			x = x / 10
		}
	}

	return reversedNumber == originalNumber
}

func main() {
	number := 121
	fmt.Println(isPalindrome(number))
}
