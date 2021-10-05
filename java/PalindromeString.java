public class PalindromeString {

    public static boolean isPalindrome(String s) {
        int i = 0, j = s.length()-1;
        for (; i<j; i++, j--){
            if (s.charAt(i)!=s.charAt(j)){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String palindrome = "otto";
        String notPalindrome = "gatto";
        System.out.println(isPalindrome(palindrome));
        System.out.println(isPalindrome(notPalindrome));
    }
}
