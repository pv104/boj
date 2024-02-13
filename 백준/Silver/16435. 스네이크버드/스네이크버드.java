import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws Exception{
		int n,l;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		int fr[] = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			fr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(fr);
		int start = l;
		int idx=0;
		for (int i : fr) {
			if(start >= i) ++start;
			else break;
		}
		System.out.print(start);
	}
}