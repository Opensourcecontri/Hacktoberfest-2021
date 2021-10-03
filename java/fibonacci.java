import java.util.Scanner;
import java.util.HashMap;
import java.math.BigInteger;

public class fibonacci{
public static HashMap<Integer,BigInteger> memo = new HashMap<>();

public static BigInteger getfibterm(int n){

	if (memo.containsKey(n)){
		return memo.get(n);
	}
	if (n<=2)
		return BigInteger.valueOf(1);
memo.put(n,getfibterm(n-1).add(getfibterm(n-2)));
return memo.get(n);
}
public static void main(String[] args) throws Exception{
Scanner input = new Scanner(System.in);
do{
System.out.print("Enter a number n to get the nth fibonacci number : ");
int n = input.nextInt();
try{
System.out.println(getfibterm(n));
}
catch(Exception e){
System.out.println("Value too large to show!!!");
}
System.out.println("If you want to exit enter -1");
if (input.nextInt()==-1)
break;
}while(true);

}
}

