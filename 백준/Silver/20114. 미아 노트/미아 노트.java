import java.io.*;
import java.util.*;

public class Main {

	static final int N_SIZE = 102, H_SIZE = 12;
	static String[] A = new String[H_SIZE];
	static char[] answer = new char[N_SIZE];
	static int N,H,W;
	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		for (int i=0; i<H; i++) {
			A[i] = br.readLine();
		}
		for (int i=0; i<N_SIZE; i++) {
			answer[i] = '?';
		}
		for (int i=0; i<H; i++) {
			for (int j=0; j<N*W; j++) {
				int c = j/W;
				if(answer[c] == '?')
					answer[c] = A[i].charAt(j);
				
			}
		}
		for (int i=0; i<N; i++)
			System.out.print(answer[i]);
	}
}
