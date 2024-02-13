import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());

        int N=Integer.parseInt(st.nextToken());
        int[] A=new int[N];
        int[] dp=new int [N];
        for(int i=0;i<N;i++){
            dp[i]=1;
        }

        st=new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            A[i]=Integer.parseInt(st.nextToken());
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(A[i]>A[j]){
                    dp[i]=Math.max(dp[i],dp[j]+1);
                }
            }
        }

        int max=dp[0];
        for(int i=0;i<N;i++){
            if(dp[i]>max)
                max=dp[i];
        }
        System.out.println(max);


    }
}
