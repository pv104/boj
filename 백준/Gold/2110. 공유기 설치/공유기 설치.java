import java.io.*;
import java.util.*;

public class Main {

	public static int N,C;
	public static ArrayList<Integer> a = new ArrayList<>();
	public static boolean chk(int d) {
		int cnt=1,cur=a.get(0);
		for (int i=1; i<N; i++) {
			if(cur+d<=a.get(i)) {
				cnt++;
				cur = a.get(i);
			}
		}
		return cnt >= C;
	}
	public static int solve() {
		int lo=a.get(1) - a.get(0), hi = a.get(N-1) - a.get(0);
		for (int i=1; i<N; i++) {
			if(lo > a.get(i) - a.get(i-1)) lo = a.get(i) - a.get(i-1);
		}
		while(lo <= hi) {
			int mid = (lo + hi) / 2;
//			System.out.println(" l h m " + lo + " " + hi + " " + mid);
			if(chk(mid)) {
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		return hi;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			a.add(Integer.parseInt(st.nextToken()));
		}
		a.sort(Comparator.naturalOrder());
		System.out.print(solve());
	}
}
