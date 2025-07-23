import java.io.*;
import java.util.*;

public class Main {
	public static class Node {
		Node[] child = new Node[26];
		boolean isEnd, isUsed;
		Node root;

		void insert(String word) {
			if (root == null)
				root = new Node();
			Node cur = root;
			for (char c : word.toCharArray()) {
				int idx = c - 'A';
				if (cur.child[idx] == null)
					cur.child[idx] = new Node(); // 아직 이 접두사 없음
				cur = cur.child[idx];
			}
			cur.isEnd = true; // 여기가 마지막
		}

		boolean contains(String word) { // 완전일치검색

			if (root == null)
				root = new Node();
			Node cur = root;
			for (char c : word.toCharArray()) {
				int idx = c - 'A';
				if (cur.child[idx] == null)
					return false;
				cur = cur.child[idx];
			}
			return cur.isEnd; // 이걸로 끝나야(true 반환해야 true)
		}

		boolean hasPrefix(String prefix) { // 접두사검색
			if (root == null)
				root = new Node();
			Node cur = root;
			for (char c : prefix.toCharArray()) {
				int idx = c - 'A';
				if (cur.child[idx] == null)
					return false;
				cur = cur.child[idx];
			}
			return true; // 여기까지만 오면 됨(prefix까지만)
		}

		boolean checkIsUsed(String word) {
			if (root == null)
				root = new Node();
			Node cur = root;
			for (char c : word.toCharArray()) {
				int idx = c - 'A';
				if (cur.child[idx] == null)
					return false;
				cur = cur.child[idx];
			}
			return cur.isUsed;
		}

		void toggleIsUsed(String word) {
			if (root == null)
				root = new Node();
			Node cur = root;
			for (char c : word.toCharArray()) {
				int idx = c - 'A';
				cur = cur.child[idx];
			}
			cur.isUsed = !cur.isUsed;
		}
	}

	public static class R {
		int maxScore;
		String maxLenWord;
		int wordCount;
	}

	static final int[] dr = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc = { -1, 0, 1, -1, 1, -1, 0, 1 };
	static Node dictionary = new Node();
	static int N, B;
	static int[] scoreArr = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
	static char[][] A;
	static boolean[][] visited;
	static R res;
	static ArrayDeque<String> usedWord;
	// 트라이 써서 찾고, 4*4 완탐으로 결과 저장하기

	public static void rec(int r, int c, String word, int count) {

//		System.out.println(" r : " + r + " c : " + c + " word : " + word + " count : " + count +
//				" ms : " + res.maxScore + " mLW : " + res.maxLenWord + " mWC : " + res.wordCount);

		if (count > 8) {
			// 반복 끝
			return;
		}
		if (dictionary.contains(word)) {
			if (!dictionary.checkIsUsed(word)) {
				dictionary.toggleIsUsed(word);
		res.maxScore += scoreArr[word.length()];
		res.wordCount++;
		if (res.maxLenWord.length() == 0)
			res.maxLenWord = word;
		if (res.maxLenWord.length() == word.length()) {
			if (res.maxLenWord.compareTo(word) > 0)
				res.maxLenWord = word;
		} else if(res.maxLenWord.length() < word.length())
			res.maxLenWord = word;
		usedWord.add(word);
			}
		}
		for (int dir = 0; dir < 8; dir++) {

			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr < 0 || nc < 0 || nr > 3 || nc > 3)
				continue;
			if (word.length() < 8 && !visited[nr][nc]) {
				// 단어 있는지 확인
				StringBuilder sb = new StringBuilder();
				sb.append(word).append(A[nr][nc]);
				String newWord = sb.toString();
				// 단어 사용했는지 확인
				if (dictionary.contains(newWord)) {
					if (!dictionary.checkIsUsed(newWord)) {
						// 사용하는 경우
						visited[nr][nc] = true;
						rec(nr, nc, newWord, count + 1);
						visited[nr][nc] = false;
//						dictionary.toggleIsUsed(newWord);
					} else {
						visited[nr][nc] = true;
						rec(nr, nc, newWord, count + 1);
						visited[nr][nc] = false;
					}
				} else {
					// 단어 없음
					if (dictionary.hasPrefix(newWord)) {
						// 접두사라도 있으면
						visited[nr][nc] = true;
						rec(nr, nc, newWord, count + 1);
						visited[nr][nc] = false;
					}
				}
			}

		}

	}

	public static String run() {
		res = new R();
		usedWord = new ArrayDeque<>();
		res.maxLenWord = "";
		visited = new boolean[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				visited[i][j]= true;
				String word = String.valueOf(A[i][j]);
				// word = 1글자일때 처리
				if(dictionary.contains(word) && !dictionary.checkIsUsed(word)) {
					dictionary.toggleIsUsed(word);
					res.maxScore += scoreArr[word.length()];
					res.wordCount++;
					if(res.maxLenWord.length() == 0)
						res.maxLenWord = word;
				}
				rec(i, j, word, 1);
				visited[i][j] = false;
//				System.out.println(" i " + i + " j " + j + " 종료, res 값 -> " + res.maxScore + " " + res.maxLenWord + " "
//						+ res.wordCount);
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(res.maxScore).append(" ").append(res.maxLenWord).append(" ").append(res.wordCount);
		return sb.toString();
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br;
		br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("input.txt"));
//		PrintStream fileOut = new PrintStream(new FileOutputStream("output.txt"));

		// System.out을 파일로 리다이렉트
//        System.setOut(fileOut);
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			dictionary.insert(br.readLine());
		}
		br.readLine();
		B = Integer.parseInt(br.readLine());
		for (int tc = 0; tc < B; tc++) {
			A = new char[4][4];
			for (int r = 0; r < 4; r++) {
				String s = br.readLine();
				for (int c = 0; c < 4; c++) {
					A[r][c] = s.charAt(c);
				}
			}
			sb.append(run()).append("\n");
			br.readLine();
			while(!usedWord.isEmpty()) {
				dictionary.toggleIsUsed(usedWord.poll());
			}
		}
		System.out.print(sb.toString());
	}

}
