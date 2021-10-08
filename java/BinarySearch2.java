//Find the first and last occurence of target element.

public class BinarySearch2 {
    public static void main(String[] args) {
        int[] arr = {5, 7, 7, 7, 7, 8, 8, 10};
        int target = 8;
        int[] result = findNum(arr, target);
        System.out.println(result);
        
    }
    static int[] findNum(int[] arr, int target)
    {
        boolean firstStartIndex = true;
        int[] ans = {-1, -1};
        ans[0] = search(arr, target,true);
        if(ans[0] != -1)
        {
            ans[1] = search(arr, target,false);
        }
        int res = search(arr, target, firstStartIndex);
        System.out.println(res);
        return ans;
    }
    static int search(int[] arr, int target, boolean firstStartIndex)
    {
        int ans = -1;
        int start = 0;
        int end = arr.length - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target > arr[mid])
            {
                start = mid + 1;
            }
            else if(target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                if(firstStartIndex == true)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return ans;
    }
}
