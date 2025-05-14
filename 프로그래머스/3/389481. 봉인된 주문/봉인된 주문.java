import java.util.*;

class Solution {
    public long[] longBans;
    public long convertToLong(String ban) {
        long sqrtNum = 1;
        long k = 0;
        long alpha = 0;
        for (int i=0, j=ban.length()-1; i<ban.length(); i++, j--) {
            alpha = ban.charAt(j) - 'a' + 1;
            k += alpha * sqrtNum;
            sqrtNum *= 26;
        }
        return k;
    }
    public String solve(long n) {
        String answer = "";
        StringBuilder sb = new StringBuilder("");
        int cnt=0;
        long lo = 1, hi = n + longBans.length;   
        while (lo < hi) {
            long mid = (lo + hi) >>> 1;
            int idx = Arrays.binarySearch(longBans, mid);
            idx = (idx >= 0) ? idx + 1        
                          : -(idx + 1);  
            long removed = idx;
            if (mid - removed >= n) hi = mid;    
            else                     lo = mid+1; 
        }
        long m = lo;                             
       
        while(m > 0) {
            m--;
            char c =  (char) ((m % 26) + 'a') ;
            sb.append(c);
            m/=26;
        }
        return sb.reverse().toString();
    }
    public String solution(long n, String[] bans) {
        String answer = "";
        longBans = new long[bans.length];
        int i=0;
        for (String ban : bans) {
            longBans[i++] = convertToLong(ban);
        }
        Arrays.sort(longBans);
        return answer = solve(n);
    }
}