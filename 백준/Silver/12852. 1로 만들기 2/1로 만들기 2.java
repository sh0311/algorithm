import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 0;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + 1;
            if(i%2 == 0){
                dp[i] = Math.min(dp[i], dp[i/2]+1);
            }
            if(i%3 == 0){
                dp[i] = Math.min(dp[i], dp[i/3]+1);
            }
        }
        System.out.println(dp[n]);
        StringBuilder sb = new StringBuilder();
        sb.append(n).append(" ");
        while(n>1){
            int min = dp[n-1];
            int temp = n-1;
            if(n%3 == 0 && dp[n/3] < min){
                min = dp[n/3];
                temp = n/3;
            }
            if(n%2 == 0 && dp[n/2] < min){
                min = dp[n/2];
                temp = n/2;
            }
            n = temp;
            sb.append(n).append(" ");

        }
        System.out.print(sb.toString().trim());
    }
}