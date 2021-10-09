//Golang Program to find LCM and GCD of two numbers
package main
import "fmt"

/* Function without return declaration*/
func lcm(temp1 int,temp2 int) { 
    var lcmnum int =1
    if(temp1>temp2)    {
        lcmnum=temp1
    }else{
        lcmnum=temp2
    }
    /* Use of For Loop as a While Loop*/
    for {        
        if(lcmnum%temp1==0 && lcmnum%temp2==0) {    // And operator
            /*  Print Statement with multiple variables   */
            fmt.Printf("LCM of %d and %d is %d",temp1,temp2,lcmnum)            
            break
        }
        lcmnum++
    }
    return // Return without any value
}

func gcd(temp1 int,temp2 int){
       var gcdnum int
    /* Use of And operator in For Loop */   
    for i := 1; i <=temp1 && i <=temp2 ; i++ {
            if(temp1%i==0 && temp2%i==0) {
                gcdnum=i
            } 
        }
        fmt.Printf("GCD of %d and %d is %d",temp1,temp2,gcdnum)
    return
}  


func main() {
    var n1,n2,action int
    fmt.Println("Enter two positive integers : ")
    fmt.Scanln(&n1)
    fmt.Scanln(&n2)

    fmt.Println("Enter 1 for LCM and 2 for GCD")
    fmt.Scanln(&action)
    /*  Use of Switch Case in Golang */    
    switch action {
        case 1:
            lcm(n1,n2)
        case 2:
            gcd(n1,n2)
    }
}