import java.io.*;
import java.util.*;
public class Main {

	static int N,K,T;
	static int[] freq,res;
	
	static String solve(String W) {
		freq = new int[26];
		res = new int[2];
		res[0] = Integer.MAX_VALUE;
		res[1] = Integer.MIN_VALUE;
		List<Integer>[] A = new ArrayList[26];
		for(int i=0; i<26; i++)
			A[i] = new ArrayList<>();
		// 1. 각 idx 뽑기
		for (int i=0; i<W.length(); i++) {
			char cur = W.charAt(i);
			A[cur - 'a'].add(i);
		}
		// 2. K개씩 확인하기 
		for (int i=0; i<26; i++) {
			if(A[i].size() < K) continue;
			for (int j=0; j<A[i].size() - K + 1; j++) {
				int st = A[i].get(j);
				int ed = A[i].get(j+K-1);
				res[0] = Math.min(res[0], ed - st + 1);
				res[1] = Math.max(res[1], ed - st + 1);
			}
		}
		StringBuilder sb = new StringBuilder();
		if(res[0] == Integer.MAX_VALUE && res[1] == Integer.MIN_VALUE)
			sb.append(-1).append("\n");
		else
		sb.append(res[0]).append(" ").append(res[1]).append("\n");
		return sb.toString();
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		T = Integer.parseInt(st.nextToken());
		String W;
		StringBuilder sb = new StringBuilder();
		for (int tc=0; tc<T; tc++) {
			W = br.readLine();
			K = Integer.parseInt(br.readLine());
			sb.append(solve(W));
		}
		System.out.println(sb);
    }
}
