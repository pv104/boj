import java.util.*;
import java.io.*;
class Solution {
    class Plan implements Comparable<Plan> {
        int start,playtime;
        String name;
        
        @Override
        public int compareTo(Plan o) {
            return Integer.compare(this.start,o.start);
        }
        Plan() {}
        Plan(String name, int start, int playtime) {
            this.name = name;
            this.start = start;
            this.playtime = playtime;
        }
    }
    public static PriorityQueue<Plan> pq;
    public static StringTokenizer st;
    public static Stack<Plan> s;
    // 1. start hh:mm -> int로 변경하기
    public void convertToInt(String[][] plans) {
        for(String[] plan : plans) {
            String name = plan[0];
            st = new StringTokenizer(plan[1], ":");
            int h = Integer.parseInt(st.nextToken()) * 60;
            int m = Integer.parseInt(st.nextToken());
            int start = h+m;
            int playtime = Integer.parseInt(plan[2]);
            Plan p = new Plan(name,start,playtime);
            pq.add(p);
        }
        return;
    }
    // 2. 모든 과제를 마칠때까지 수행하기
    public String[] solution(String[][] plans) {
        String[] answer = {};
        ArrayList<String> res = new ArrayList<>();
        pq = new PriorityQueue<>();
        s = new Stack<>();
        convertToInt(plans);
        
        Plan cur = pq.poll();
        
        for (int time = cur.start+1; ; time++) {
            if(cur.playtime == 0 && pq.isEmpty() && s.isEmpty()) break;
            if(cur.playtime > 0) {
                cur.playtime--;
            }
            
              if ((!pq.isEmpty()) && (pq.peek().start == time)) {
                  if(cur.playtime != 0) {
                      s.push(cur);
                  } else {
                      if(!res.contains(cur.name))
                  res.add(cur.name);
                  }
                  cur = pq.poll();
              } else {
                  if(cur.playtime == 0) {
                      if(!res.contains(cur.name))
                      res.add(cur.name);
                      if(!s.isEmpty()) {
                          cur = s.pop();
                      }
                  }
              }
                
            
        }
        
        return res.toArray(new String[0]);
    }
}