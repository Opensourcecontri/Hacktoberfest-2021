// Java solution for Anagram problem
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

public class anagram {
    public static boolean isAnagram(String s, String t) {
        int[] alphabet = new int[26];
        for (int i = 0; i < s.length(); i++)
            alphabet[s.charAt(i) - 'a']++;
        for (int i = 0; i < t.length(); i++)
            alphabet[t.charAt(i) - 'a']--;
        for (int i : alphabet)
            if (i != 0)
                return false;
        return true;
    }

    public static void main(String[] args) {
        String s = "anagram", t = "nagaram";
        System.out.println(isAnagram(s, t));
    }
}

// Time Complexity : O(n)
// Since both the strings are traversed once.
// ------------------------//
// Space Complexity : O(1)
// A fixed size of array is used, so constant space complexity.