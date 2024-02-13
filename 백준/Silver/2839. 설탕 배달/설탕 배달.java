import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		int n = Integer.parseInt(br.readLine());
		int cnt=0;
		if(n == 4 || n == 7) System.out.print(-1);
		else {
			while(n % 5 != 0) {
				++cnt;
				n-=3;
			}
			System.out.print(cnt + (n/5));
		}
	}
}