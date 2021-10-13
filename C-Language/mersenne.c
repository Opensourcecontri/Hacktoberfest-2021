//source: https://www.w3resource.com/c-programming-exercises/numbers/c-numbers-exercise-33.php

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>


void GenAllPrim(int n1, bool prarr1[])
{
    for (int i=0; i<=n1; i++)
        prarr1[i] = true;
 
    for (int p=2; p*p<=n1; p++)
    {
        if (prarr1[p] == true)
        {
            for (int i=p*2; i<=n1; i += p)
                prarr1[i] = false;
        }
    }
}
void chkMerPrime(int nm)
{
    bool prarr1[nm+1];
    GenAllPrim(nm,prarr1);
    for (int j=2; ((1<<j)-1) <= nm; j++)
    {
        long long num = (1<<j) - 1;
        if (prarr1[num])
            printf(" %lli ",num);
    }
}
int main()
{
    int n ;
	printf("\n\n Generate Mersenne primes within a range of numbers:\n");
	printf("--------------------------------------------------------\n");
	printf(" Input a upper limit [range from 1 to upper limit]: ");
    scanf("%d",&n);	
    printf(" Mersenne prime numbers are: \n");
    chkMerPrime(n);
    printf("\n\n");
}