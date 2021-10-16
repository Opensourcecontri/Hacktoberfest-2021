//https://www.codewars.com/kata/514b92a657cdc65150000006/train/java

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class Solution {

  public int solution(int number) {
    int sum = 0;
    for(int i = 0; i < number; i++){
      if(i % 3 == 0 || i % 5 == 0){
        sum += i;
      }
    }
    return(sum);
  }
}

public class SolutionTest {
    @Test
    public void test() {
      assertEquals(23, new Solution().solution(10));
      assertEquals(60, new Solution().solution(16));
    }
}