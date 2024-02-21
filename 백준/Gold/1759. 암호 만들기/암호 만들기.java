import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	static char arr[], dat[];
	static int l,c;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static void Combination(int cnt, int start)
	{
		if (cnt == l)
		{
			int c1 = 0, c2 = 0;
			for (int i = 0; i < l; i++)
			{
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
					c1++;
				else c2++;
			}
			if (c1 < 1 || c2 < 2) return;
			for (int i = 0; i < l; i++)
				sb.append(arr[i]);
			sb.append("\n");
			return;
		}
		for (int i = start; i < c; i++)
		{
			arr[cnt] = dat[i];
			Combination(cnt + 1, i + 1);
		}
	}
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int i = 0;
		dat = new char[c];
		arr = new char[l];
		while(st.hasMoreTokens()) {
			dat[i++] = st.nextToken().charAt(0);

		}
		Arrays.sort(dat);
		Combination(0,0);
		System.out.print(sb);
	}
}