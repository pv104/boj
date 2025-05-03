import java.util.*;
class Solution {
    public static int SIZE = 1000002;
    public static ArrayList<Integer> board[] = new ArrayList[SIZE];
    public static int[] in = new int[SIZE];
    public static boolean[] visited = new boolean[SIZE];
    public static int DONUT = 1, STICK = 2,EIGHT = 3;
public static int findOut(int[][] edges) {
    for (int i=0; i<edges.length; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        board[a].add(b);
        in[b]++;
    }
    int maxOut = 0;
    int idx = 1;
    for (int i=1; i<SIZE; i++) {
        if(in[i] == 0 && maxOut < board[i].size()) {
            idx = i;
            maxOut = board[i].size();
        }
    }
    return idx;
}
public static int bfs(int start) {
    ArrayDeque <Integer> q = new ArrayDeque<>();
    
    int maxSize = 0;
    boolean isDonut = false;
    q.add(start);
    while(!q.isEmpty()) {
        int cur = q.poll();
        for(int i=0; i<board[cur].size(); i++) {
            int nxt = board[cur].get(i);
            if(visited[nxt]) continue;
            if(nxt == start && board[nxt].size() > 0) isDonut = true;
            maxSize = Math.max(maxSize,board[nxt].size());
            visited[nxt] = true;
            q.add(nxt);
       }
    }
    if(isDonut) {
        if(maxSize == 1) {
            return DONUT;
        }
        return EIGHT;
    } else return STICK;
}
    public int[] solution(int[][] edges) {
        
        int[] answer = new int[4];
        for (int i=0; i<SIZE; i++) 
        {
            visited[i] = false;
            board[i] = new ArrayList<>();
        }
        int creates = findOut(edges);
        for (int i=0; i<board[creates].size(); i++) {
            int t = bfs(board[creates].get(i));
            answer[t]++;
        }
        answer[0] = creates;
        return answer;
    }
}