#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i=0,n;
	printf("\nEnter the string:");
	gets(str);
	n=strlen(str)-1;
	while(i<=n/2)
	{
		if(str[i]==str[n])
		{
			i++;
			n--;
		}
		else
		break;
	}
	if(i==n)
	printf("\nThe string is palindrome");
	else
	printf("\nNot a palindrome");
	return 0;
}
