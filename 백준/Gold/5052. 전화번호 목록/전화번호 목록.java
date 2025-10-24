import java.io.*;
import java.util.*;

public class Main {

	static class Node {
		HashMap<Character, Node> child;
		boolean endOfWord;

		Node() {
			child = new HashMap<>();
			endOfWord = false;
		}
	}

	static class Trie {
		Node root;

		Trie() {
			root = new Node();
		}
	}

	static void insert(String str) {
		Node cur = trie.root;
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			cur.child.putIfAbsent(c, new Node());
			cur = cur.child.get(c);
		}
		cur.endOfWord = true;
	}

	static boolean search(String str) {
//		System.out.println("search start : " + str);
		Node cur = trie.root;
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (!cur.child.containsKey(c))
				return false;
			cur = cur.child.get(c);
		}
		return cur.endOfWord;
	}
	static boolean isPrefix(String str) {
		Node cur = trie.root;
		for (int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			if (!cur.child.containsKey(c))
				return false;
			cur = cur.child.get(c);
		}
		if(cur.endOfWord == false) return false;
		if(cur.endOfWord == true && cur.child.size() != 0) return false;
		return cur.endOfWord;
	}
	static int T, N, N_SIZE = 10002;
	static Trie trie;
	static String[] A;
	static void init() {
		trie = new Trie();
		A = new String[N_SIZE];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int tc = 0; tc < T; tc++) {
			init();
			boolean flag = true;
			N = Integer.parseInt(br.readLine());
			for (int i=0; i<N; i++) {
				String str = br.readLine();
				A[i] = str;
				insert(str);
//				System.out.println("search start : " + str + " result : " + search(str));

			}
			for (int i=0; i<N; i++) {
				if(!isPrefix(A[i])) {
//					System.out.println("search start : " + A[i] + " result : " + isPrefix(A[i]));
					flag = false; break;
				}
			}
			if(flag) System.out.println("YES"); else System.out.println("NO");
		}
	}
}
