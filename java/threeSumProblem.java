import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class threeSumProblem {

	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.println("Three sum problem Solver");
		System.out.println("Enter size of array : ");
		int n = input.nextInt();
		int[] nums = new int[n];
		System.out.println("Enter the element of the array : ");
		for(int iter = 0; iter<n; iter++){
		nums[iter] = input.nextInt();
		}
		System.out.println("The given array is :"+Arrays.toString(nums));
		List<List<Integer>> solution = threeSum(nums);
		if (solution.size()==0){
		System.out.println("There are no 3sum pairs in the given array ");
		}
		else{
		System.out.println("Solution : ");
		for(int iter =0;iter<solution.size();iter++){

			System.out.println(Arrays.toString(solution.get(iter).toArray()));
		}
		}


	}
    	public static List<List<Integer>> threeSum(int[] nums) {
        int leftPtr,rightPtr;
        List<List<Integer>> soln = new ArrayList<>();
        Arrays.sort(nums);
        for(int iter1 = 0;iter1<nums.length;iter1++){
            if (iter1!=0 && nums[iter1] == nums[iter1-1])
                continue;
            leftPtr = iter1 + 1;
            rightPtr = nums.length -1;
            while(leftPtr<rightPtr){
                int sumOf3 = nums[iter1]+nums[leftPtr]+nums[rightPtr];
                if (sumOf3==0){
                    soln.add(Arrays.asList(nums[iter1],nums[leftPtr],nums[rightPtr]));
                    leftPtr+=1;
                    while (leftPtr<rightPtr & nums[leftPtr]==nums[leftPtr-1]){
                            leftPtr+=1;
                    }
                    while (leftPtr<rightPtr & nums[rightPtr]==nums[rightPtr-1]){
                            rightPtr-=1;
                    }
                }
                else if(sumOf3<0)
                    leftPtr+=1;
                else
                    rightPtr-=1;
        }
        }
        return soln;
    }
}
