import java.util.*;
class Solution {
    public class Pair implements Comparable<Pair> {
        int s;
        int e;
        public Pair() {}
        public Pair(int s,int e) {
            this.s = s;
            this.e = e;
        }
        @Override
        public int compareTo(Pair o1) {
            if(this.s == o1.s)
                return this.e - o1.e;
            return this.s - o1.s;
        }
    }
    
    public int solution(int[][] targets) {
        int answer = 0;
        int x = -1;
        PriorityQueue<Pair>pq = new PriorityQueue<>();
        
        for (int[] arr : targets) {
            pq.add(new Pair(arr[0],arr[1]));
        }
        
        int s = pq.peek().s;
        int e = pq.peek().e;
        pq.poll();
        answer = 1;
       while(!pq.isEmpty()) {
           Pair p = pq.poll();
           if(p.s >= e) 
           {answer++; // 미사일 추가
            s = p.s;
            e = p.e;
           }else // 그대로 사용
           {s = Math.max(p.s,s);
           e = Math.min(p.e,e);
           }
           
        // System.out.println(" x : " + x + " s : " + p.s + " e : " + p.e + " answer : " + answer);
        }
        return answer;
    }
}