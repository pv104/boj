import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int SIZE = 11;
    static int N, M, K;
    static int res;
    static int[][] A = new int[SIZE][SIZE];
    static int[][] board = new int[SIZE][SIZE];
    static int[][] summerTree = new int[SIZE][SIZE];
    static int[][] treeSize = new int[SIZE][SIZE];
    static int[][] treeCounts = new int[SIZE][SIZE];
    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    @SuppressWarnings("unchecked")
    static ArrayDeque<Pair>[][] tree = new ArrayDeque [SIZE][SIZE];
    @SuppressWarnings("unchecked")
    static ArrayDeque<Pair>[][] springTree = new ArrayDeque [SIZE][SIZE];
    @SuppressWarnings("unchecked")
    static PriorityQueue<Pair>[][] input = new PriorityQueue [SIZE][SIZE];


    static class Pair implements Comparable <Pair> {
        int age;
        int count;
        public Pair(int age,int count) {
            this.age = age;
            this.count = count;
        }
        @Override
        public int compareTo(Pair p) {
            if(age == p.age) {
                return count - p.count;
            }
            return age - p.age;
        }
    }
    static void spring() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int size = tree[i][j].size();
                while (size > 0) {
                    --size;
                    Pair cur = tree[i][j].pollFirst();
                    int age = cur.age;
                    int count = cur.count;
                    int sum = age * count;
                    if (board[i][j] == 0) {
                        summerTree[i][j] += ((age >> 1) * count);
                        continue;
                    }
                    if (sum >= board[i][j]) {
                        if (sum == board[i][j]) {
                            board[i][j] = 0;
                        } else {
                            count = board[i][j] / age;
                            board[i][j] %= age;
                            summerTree[i][j] += ((age >> 1) * (cur.count - count));
                        }
                    } else {
                        board[i][j] -= sum;
                    }
                    if (++age % 5 == 0) {
                        treeCounts[i][j] += count;
                    }
                        res += count;
                        tree[i][j].addLast(new Pair(age, count));
                }
            }
        }
    }

    static void summer() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] += summerTree[i][j];
                summerTree[i][j] = 0;
            }
        }
    }

    static void fall() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 8; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    treeSize[ny][nx] += treeCounts[i][j];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += treeSize[i][j];
                tree[i][j].addFirst(new Pair(1, treeSize[i][j]));
                treeSize[i][j] = treeCounts[i][j] = 0;
            }
        }
    }

    static void winter() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] += A[i][j];
            }
        }
    }
    static void input() throws Exception {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                tree[i][j] = new ArrayDeque<>();
                springTree[i][j] = new ArrayDeque<>();
                input[i][j] = new PriorityQueue<>();
                board[i][j] = 5;
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }


        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            --r;
            --c;
            input[r][c].add(new Pair(a, 1));
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                tree[i][j].addAll(input[i][j]);
            }
        }
    }

    static int solve() {
        for (int i = 0; i < K; i++) {
            res = 0;
            spring();
            summer();
            fall();
            winter();
        }
        return res;
    }

    public static void main(String[] args) throws Exception {
        input();
        System.out.print(solve());
    }
}