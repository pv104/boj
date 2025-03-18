import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long K;
    static StringBuilder sb = new StringBuilder();
    static void input() throws Exception {
        K = Long.parseLong(br.readLine());
    }
    static String solve() {
        long sum=0,next=2,i=1;
        String str = "";
        while(sum + next < K) {
            sum += next;
            i++;
            next *= 2;
        }
//        System.out.println(" K : " + K + " SUM : " + sum + " NEXT : " + next + " i : " + i);
        long bin = K - sum - 1;
//        System.out.println(bin);
        sb.append(Long.toBinaryString(bin));
        while(sb.length() < i) {
            sb.insert(0, "0");
        }
        StringBuilder res = new StringBuilder();
        for(char c : sb.toString().toCharArray()) {
            if(c == '0') {
                res.append("4");
            }
            else res.append("7");
        }
        return res.toString();
    }

    public static void main(String[] args) throws Exception {
        input();
        System.out.println(solve());
    }
}