import java.util.*;
class Solution {
    public long solution(int r1, int r2) {
        long R1 = r1;
        long R2 = r2;
        long answer = 0;
        for (long x = 1; x <= r2; x++) {
            long yMax = (long) Math.floor(Math.sqrt(R2*R2 - x*x));
            long yMin = 0;
            if (R1*R1 - x*x > 0) {
                yMin = (long) Math.ceil(Math.sqrt(R1*R1 - x*x));
            }
            answer += (yMax - yMin + 1);
        }
        answer *= 4; 
        return answer;
    }
}