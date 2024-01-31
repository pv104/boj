
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main{
public static boolean isused[];
	   public static int arr[];
	   public static StringBuilder sb;
	    public static void main(String[] args) throws Exception {
	    	sb = new StringBuilder();
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			Scanner sc = new Scanner(System.in);
	  	 isused = new boolean[10];
	  	   arr = new int[10];
	  	   int n = sc.nextInt();
	  	   int m = sc.nextInt();
	        Permutation(0,n,m);
	        System.out.print(sb);
	        sc.close();
	    }
	    public static void Permutation(int k,int n,int m) {
		       if(k == m) {
		            for (int i = 0; i < m; i++)
		            sb.append(arr[i]).append(" ");
		            sb.append("\n");
		            return;
		        }
		        for (int i = 1; i <= n; i++)
		        {
		        if (isused[i]) continue;
		        isused[i] = true;
		        arr[k] = i;
		        Permutation(k + 1,n,m);
		        isused[i] = false;
		        }
		        return;
		    }
}