import java.util.*;

public class arrayList {

public static int[] newArrayList(int[] array){
	int[] extendedArray = new int[array.length*2];
	for(int i = 0 ; i < array.length; i++){
		extendedArray[i] = array[i];
	}
	return extendedArray;
}
public static void displayArrayList(int[] array, int noOfEle){
	if (array.length==0)
		System.out.println("ArrayList is Empty !!!");
	else{
	System.out.println("The ArrayList contains : ");
	System.out.print("[");
	for(int i = 0; i<noOfEle;i++){
        System.out.print(array[i]+" ");
        }
	System.out.print("]\n");
	}
    }
public static void main(String[] args) {
	
	Scanner input = new Scanner(System.in);

	int choice,counter = 0;
	int[] arrayList = new int[1];
	int redefinitions = 0;
	int redefined = 1;

menu:
	do{
		System.out.println("Array List in java :\n"+ 
			"1. Insert Element \n"+
			"2. Display Element \n"+
			"3. Length of array \n"+
			"4. Exit \n");
		System.out.print("Enter choice : ");
		choice = input.nextInt();

		switch(choice){
			case 1:
				System.out.println("Enter element : ");
				int element = input.nextInt();
				if (arrayList.length==counter){
				 arrayList = newArrayList(arrayList);
				 redefinitions+=1;
				}
				System.out.println(counter+" "+arrayList.length);
				arrayList[counter] = element;
				counter+=1;
				break;
			case 2:
				displayArrayList(arrayList, counter);
				break;
			case 3:
				System.out.println("No of elements : "+counter+"\n"+"Length of array = No of redefinitions X 2 = "+arrayList.length);
				break;
			case 4:
				break menu;
			default:
				System.out.println("Invalid Choice");
				break;
		}
	}while(true);


}

}
