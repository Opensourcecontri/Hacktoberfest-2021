# Generating Binary Numbers from 1 To N Using Queue

> **Explanation :**
* Since to generate binary number from 1 to N we need to the pattern follow by BN from 1 to N.

* The pattern is 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101...

* The pattern is first we have only number 1, then we will append 0 and 1 to 1 and write these two number after 1.
    * Example for 1 :
        * 1+0= 10
        * 1+1 = 11
    * Now we will write these two numbers i.t 10 and 11 after 1
    i.e 1 10 11.

    * Now we will come to 10 :
        * 10+0=100
        * 10+1=101
    * Now write 1 10 11 100 101.

    * Now come to 11 :
        * 11+0=110
        * 11+1=111
    
    * Now write 1 10 11 100 101 110 111.

    * And so on...


* In this way we will be able to convert decimal number to binary number from 1 to N.

> **Code Execution :**

* We will make a vector since size of vector can be increased during the run time. 

* And we will make a stack to insert the first decimal number to it later this decimal number we will append 0 and 1 to generate further binary numbers.
