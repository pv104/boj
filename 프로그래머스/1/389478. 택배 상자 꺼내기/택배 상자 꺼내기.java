class Solution {
    public int SIZE = 102;
    public int[][] arr = new int[SIZE][SIZE];
    public int solution(int n, int w, int num) {
        int answer = 0; {
        int i=1,cnt=1;
        while(true) {
            // 1. 1 -> w
            for (int j=1; j<=w && cnt <= n; j++) {
                arr[i][j] = cnt++;
            }
            i++;
            if(cnt > n) break;
            // 2. w -> 1
            for (int j=w; j>=1 && cnt <= n; j--) {
                arr[i][j] = cnt++;
            }
            i++;
            if(cnt > n) break;
        }}
        int r=0,c=0;
        for (int i=1; i<SIZE; i++) {
            for (int j=1; j<=w; j++) {
                if(num == arr[i][j]) {
                    r = i; c = j; break;
                }
            }
        }
        for (int i=r; i<SIZE; i++) {
            if(arr[i][c] == 0) break;
            answer++;
        }
        return answer;
    }
}