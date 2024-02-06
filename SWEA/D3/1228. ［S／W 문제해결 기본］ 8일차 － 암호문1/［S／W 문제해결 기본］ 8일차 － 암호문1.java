
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	public static String solve() throws NumberFormatException, IOException {
		StringBuilder res= new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		final int MAX = 1000001;
		LinkedList<Integer> s= new LinkedList<>();
		
		st = new StringTokenizer(br.readLine()," ");
		for (int i=0; i<n; i++) {
			s.add(Integer.parseInt(st.nextToken()));
		}
		st = new StringTokenizer(br.readLine()," ");
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int cnt=0; cnt<m; cnt++) {
			String[] c = st.nextToken("I").split(" ");
			int x = Integer.parseInt(c[1]);
			int y = Integer.parseInt(c[2]);
			int index=3;
			for (int i=0; i<y; i++) {
				int val = Integer.parseInt(c[index+i]);
				s.add(x+i,val);
			}
		}
		int cnt=0;
		
		for(int i : s) {
			res.append(i).append(" ");
			if(++cnt == 10) return res.toString();
			
		}
		return res.toString();	
		
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		for (int test_case = 1; test_case <= 10; test_case++) {
			sb.append("#").append(test_case).append(" ").append(solve()).append("\n");
		}
		System.out.println(sb);
	}
}
