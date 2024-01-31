import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main{
    public static int arr[];
	   public static StringBuilder sb;
	    public static void main(String[] args) throws Exception {
	    	sb = new StringBuilder();
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			Scanner sc = new Scanner(System.in);
	  	   arr = new int[10];
	  	   int n = sc.nextInt();
	  	   int m = sc.nextInt();
	        Combination(0,1,n,m);
	        System.out.print(sb);
	        sc.close();
	    }
	    public static void Combination(int k,int start,int n,int m)
	    {
	        if (k == m)
	        {
	            for (int i = 0; i < m; i++)
	                sb.append(arr[i]).append(" ");
	            sb.append("\n");
	            return;
	        }

	        for (int i = start; i<=n; i++)
	        {
	            arr[k] = i;
	            Combination(k + 1,i + 1,n,m);
	         }
	    }
}	    