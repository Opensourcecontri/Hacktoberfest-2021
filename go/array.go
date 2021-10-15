// create an array using the var keyword
// and accessing the elements of the
// array using their index value
package main

import "fmt"

func main() {

	// Creating an array of string type
	// Using var keyword
	var myarr [3]string

	// Elements are assigned using index
	myarr[0] = "SAHITYA"
	myarr[1] = "EDUHUB COMMUNITY"
	myarr[2] = "Founder"

	// Accessing the elements of the array
	// Using index value
	fmt.Println("Elements of Array:")
	fmt.Println("Element 1: ", myarr[0])
	fmt.Println("Element 2: ", myarr[1])
	fmt.Println("Element 3: ", myarr[2])
}
