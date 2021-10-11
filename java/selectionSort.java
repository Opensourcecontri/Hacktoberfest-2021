public class SelectionSort {

    public static void main(String[] args) {

      int i,max,unsortedPartitionIndex;
       int[] arr={20,50,-44,6,-555,81,78,1,0,666,81};

        for(unsortedPartitionIndex=arr.length-1;unsortedPartitionIndex>0;unsortedPartitionIndex--){
            max=0;
            for(i=1;i<=unsortedPartitionIndex;i++){
                if(arr[i]>arr[max]){
                    max=i;
                }
            }
            swap(arr,max,unsortedPartitionIndex);
        }
        for(i=0;i<arr.length;i++)
            System.out.println(arr[i]);
    }

    public static void swap(int[] arr,int j,int uPI){
        if(j==uPI)
            return;

        int temp = arr[j];
        arr[j] = arr[uPI];
        arr[uPI] = temp;

    }
}
