import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[] A = new int[26];
		for (int i=0; i<N; i++) {
			String s = br.readLine();
			A[s.charAt(0)-'a']++;
		}
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<26; i++) {
			if(A[i] >= 5) sb.append((char)(i+'a'));
		}
		if(sb.length() == 0) System.out.print("PREDAJA");
		else System.out.print(sb.toString());
	}
}
