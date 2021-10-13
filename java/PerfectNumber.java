import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int i,sum=0;
		for(i=1;i<n;i++){
		    if(n%i==0)
		        sum=sum+i;
		}
		if(sum==n)
		    System.out.println(n+" is a perfect no");
		else
		    System.out.println(n+" is not a perfect no");
	}
}