import java.util.*;
class Solution {
    public static int HOUR = 43200, MINUTES = 3600, SEC = 60;
   
    public static int simulation(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer=0;
      int start = h1*3600+m1*60+s1;
        int end = h2*3600+m2*60+s2;
        
        
        for (int t = start; t <= end; t++) {
            int ch = t % 43200;
            int cm = t % 3600;
            int cs = t % 60;
            
            int ns = (t+1) % 60;
            int nm = (t+1) % 3600;
            // 1. 현재 시간의 초침 - 분침, 초침 - 시침이 겹치는 경우
            if ((ch == cs * 720) || (cm == cs * 60)){
                answer++;
            }
                if(t == end) return answer;
            // 2. 1초 사이에 초침 - 시침이 겹치는 경우
            if (((cs * 720) < ch)) {
                if ((((cs+1) * 720) > ch+1)){
                answer++; 
                // System.out.println(" t " + t + " cs 720" + cs*720 + "cs+1*720 " + (cs+1)*720);
                }
            } 
            if ((cs * 60 < cm && (ns * 60 > cm+1))) {
                answer++;
            }
            
        }
        
        return answer;
        
    }
    

    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = simulation(h1,m1,s1,h2,m2,s2);
        return answer;
    }
}