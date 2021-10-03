class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
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
