public class Solution{	
	
	public static int findUnique(int[] arr){
		
        int flag,num=0;
        
        for(int i=0;i<arr.length;i++)
        {    flag=0;
         
                  for(int j=0;j<arr.length;j++)
                    {
                      if(i==j)
                      continue;
                      if(arr[i]==arr[j])
                      {flag=1;
                      break;
                      }
                    }
         
            if(flag==0){
                num= arr[i];
            }
        }

		return num;
	}
    
}
