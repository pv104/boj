
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		final int MAX = 1003;
		String s1 = br.readLine();
		String s2 = br.readLine();
		s1 = " " + s1;
		s2 = " " + s2;
		if(s1.length() < s2.length()) {
			String t = s1;
			s1 = s2;
			s2 = t;
		}

		int lcs[][] = new int[MAX][MAX];
		for (int i=1; i<s1.length(); i++) {
			for (int j=1; j<s2.length(); j++) {
				if((Character.isAlphabetic(s1.charAt(i))) 
						&& (s1.charAt(i) == s2.charAt(j))) {
					lcs[i][j] = Math.max(lcs[i-1][j-1]+1, Math.max(lcs[i-1][j],lcs[i][j-1]));
				}
				else {
					lcs[i][j] = Math.max(lcs[i-1][j],lcs[i][j-1]);
				}
			}
		}
		String s = lcs[s1.length()-1][s2.length()-1]+"";
		bw.write(s);
		bw.flush();
		bw.close();
		br.close();
	}
}
