import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] dp=new int[12];

            int n = Integer.parseInt(br.readLine());

            dp[1]=1;
            dp[2]=2;
            dp[3]=4;

            for(int i=4;i<12;i++){
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }

            for(int i=0;i<n;i++){
                int m=Integer.parseInt(br.readLine());
                System.out.println(dp[m]);
            }

            br.close();

    }
}
