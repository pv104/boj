import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n,a,b;
	static final int VALUE = 1000000000;
	static ArrayList<Pair> input;
	static class Pair implements Comparable<Pair>{
		int x;
		int y;
		int index;
		boolean isStart; // true = start, false = end; 
		Pair(){}
		Pair(int x,boolean isStart) {
			this.x = x;
			this.isStart = isStart;
		}
		Pair(int x,int y) {
			this.x = x;
			this.y = y;
		}
		Pair(int x,int y,boolean isStart) {
			this.x = x;
			this.y = y;
			this.isStart = isStart;
		}
	
		@Override
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return (int) (this.x - o.x);
		}
	}
	static ArrayList<Pair> arr = new ArrayList<>();
	static void init() {
		
	}
	static void input() throws Exception {
		n = Integer.parseInt(br.readLine());
		input = new ArrayList<>();
		int startIdx = 0;
		int x1,y1;
		Pair bottomLeft = new Pair();
		bottomLeft.x = bottomLeft.y = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken()); // y가 행
			if(x1 < bottomLeft.x && y1 < 0) {
				bottomLeft.x = x1;
				bottomLeft.y = y1;
				startIdx = i;
			}
			input.add(new Pair(x1,y1));
		}

		Pair prev = new Pair();
		prev.x = bottomLeft.x;
		prev.y = bottomLeft.y;
		int size = input.size();
		for (int i = 0; i < size; i++) {
			Pair cur = input.get((i + startIdx) % size);
			if(prev.y < 0 && cur.y > 0) {
				prev.x = cur.x;
				prev.y = cur.y;
			}
			else if(prev.y > 0 && cur.y < 0) {
				int minX = Math.min(prev.x, cur.x);
				int maxX = Math.max(prev.x, cur.x);
				prev.x = cur.x;
				prev.y = cur.y;
				
				arr.add(new Pair(minX,true));
				arr.add(new Pair(maxX,false));
			}
			}

		Collections.sort(arr);
	
		}
	static void solve() {

		Stack <Integer> st = new Stack<>();

		int cnt=0;
		int size = arr.size();
		for (int i = 0; i < size; i++) {
			Pair pair = arr.get(i);
			if(pair.isStart) {
				st.push(cnt); 
			} 
			else {
			int cur = st.pop();
			if(st.empty()) a++;
			if(cur == cnt) b++;
			
			cnt++;
		}
		}
		
	}
	public static void main(String[] args) throws Exception {
		input();
		solve();
		System.out.print(a + " " + b);
	}
}