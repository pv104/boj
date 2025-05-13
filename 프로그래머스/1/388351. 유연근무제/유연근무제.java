class Solution {
    public int SIZE = 1002;
    public int[] arr = new int[SIZE];
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        
        int N = schedules.length;
        
        for (int i=0; i<N; i++) {
            int h = schedules[i] / 100 * 60;
            int m = schedules[i] % 100;
            schedules[i] = h + m;
            for (int j=0; j<7; j++) {
                h = timelogs[i][j] / 100 * 60;
                m = timelogs[i][j] % 100;
                timelogs[i][j] = h + m;
            }
        }
        for (int day = 0, realDay = startday; day < 7; day++, realDay++) {
            realDay %= 7;
            if(realDay == 6 || realDay == 0) continue;
            for (int user = 0; user < N; user++) {
                if (timelogs[user][day] <= schedules[user] + 10) {arr[user]++;
            }
                
        }
        for (int i=0; i<N; i++) {
            if(arr[i] == 5) {answer++;
                             
                            }
        }
        }
        return answer;
    }
}