import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int INF = 987654321,SIZE = 401;
    public static int V,E;
    public static int[][] arr = new int[SIZE][SIZE];
    public static int[][] dist = new int[SIZE][SIZE];
    public static void init() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                dist[i][j] = INF;
            }
        }
    }
    public static void input() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr[r][c] = Integer.parseInt(st.nextToken());
            dist[r][c] = arr[r][c];
        }
    }
    public static void floyd() {

        for(int m=1; m<=V; m++) {
            for (int s=1; s<=V; s++) {
                for (int e=1; e<=V; e++) {
                    if(dist[s][e] > dist[s][m]+dist[m][e]) {
                        dist[s][e] = dist[s][m]+dist[m][e];
                    }
                }
            }
        }
    }
    public static int solve() {
        int res = INF;
        for(int i=1; i<=V; i++) {
            for(int j=i+1; j<=V; j++) {
                if(i==j) continue;
                res = Math.min(res,dist[i][j]+dist[j][i]);
            }
        }
        if(res == INF) res = -1;
        return res;
    }
    public static void main(String[] args) throws Exception {
        init();
        input();
        floyd();
        System.out.println(solve());
    }
}