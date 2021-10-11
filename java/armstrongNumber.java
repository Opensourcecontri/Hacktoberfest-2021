class AmstrongNumber{
    public static void main(String[] args) {
        int m=153;
        int cube=0;
        int num;
        int temp=m;
        while(temp>0){
            num=temp%10;
            cube+=num*num*num;
            temp/=10;
        }
        if(cube==m)
            System.out.println("Yes, Amstrong.");
        else
            System.out.println("Not Amstrong.");
    }
}
