import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Tuple implements Comparable<Tuple> {
        int y;
        int x;
        int c;

        public Tuple(int y, int x, int c) {
            this.y = y;
            this.x = x;
            this.c = c;
        }
        public Tuple() {
        }
        @Override
        public int compareTo(Tuple o) {
            if (this.c == o.c) {
                if(this.y == o.y) {
                    return this.x - o.x;
                }
                return this.y - o.y;
            }
            return this.c - o.c;
        }

    }
    static int SIZE = 10001;
    static int[] tree = new int[SIZE];
    // 찾기
    static int find(int x) {
        if (tree[x] == x) return x;
        return tree[x] = find(tree[x]);
    }
    // 합치기
    static boolean merge(int y,int x) {
        if (x == y) return false;
        tree[x] = y;
        return true;
    }
    static int N, M, T;
    @SuppressWarnings("unchecked")
    static PriorityQueue<Tuple> pq = new PriorityQueue<>();
    static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        int a,b,c;
        for (int i=1; i<=N; i++) {
            tree[i] = i;
        }
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            pq.add(new Tuple(a,b,c));
        }

    }
    static int solve() {

        int res=0;
        int size=1;
        while(size < N) {
            // n개가 될때까지 수행하기
            // 가중치가 가장 낮은 간선부터 빼면서 수행
            Tuple cur = pq.poll();
            int y = find(cur.y);
            int x = find(cur.x);
            int c = cur.c;

            // 연결 체크하기
            if (merge(y,x)) {
                size++;
                res += c;
            }
        }
        for (int i=0; i<N-1; i++) {
            res += (i * T);
        }
        return res;
    }
    public static void main(String[] args) throws Exception {
        input();
        System.out.println(solve());
    }
}