
// Java Solution for two Sum problem
// Given an array of integers and an integer 'n', return indices of the two numbers such that they add up to the give number 'n'.
import java.io.*;
import java.util.HashSet;

class twoSum {
    static void printpairs(int arr[], int sum) {
        HashSet<Integer> s = new HashSet<Integer>();
        for (int i = 0; i < arr.length; ++i) {
            int temp = sum - arr[i];

            if (s.contains(temp)) {
                System.out.println("Pair with given sum " + sum + " is (" + arr[i] + ", " + temp + ")");
            }
            s.add(arr[i]);
        }
    }

    public static void main(String[] args) {
        int A[] = { 2, 7, 11, 15 };
        int n = 16;
        printpairs(A, n);
    }
}

// Time Complexity: O(n).
// As the whole array is needed to be traversed only once.
// -----------------------------//
// Auxiliary Space: O(n).
// A hash map has been used to store array elements.