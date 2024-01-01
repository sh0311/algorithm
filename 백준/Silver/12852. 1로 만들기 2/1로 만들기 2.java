import java.util.*;



public class Main {

    public static void main(String[] args) {
       Scanner sc= new Scanner(System.in);
       int N=sc.nextInt();
       int [] dp=new int[N+1];

       dp[0]=dp[1]=0;

       for(int i=2;i<N+1;i++) {
           dp[i] = dp[i - 1] + 1;
           if (i % 2 == 0)
               dp[i] = Math.min(dp[i], dp[i / 2] + 1);
           if (i % 3 == 0)
               dp[i] = Math.min(dp[i], dp[i / 3] + 1);
       }

       System.out.println(dp[N]);

       ArrayList<Integer> res= new ArrayList<Integer>();
       int temp=dp[N];
       res.add(N);


       while(temp>0) {
           if (N==1){
               res.add(N);
               break;
           }
           if (N % 6 == 0) {
               if (dp[N / 3] == temp - 1) {
                   N = N / 3;

               }
                else if (dp[N / 2] == temp - 1) {
                   N = N / 2;
               }else if (dp[N - 1] == temp - 1) {
                   N = N - 1;}
               temp = dp[N];
               res.add(N);
           } else if (N % 2 == 0) {
               if (dp[N / 2] == temp - 1) {
                   N = N / 2;
               } else if (dp[N - 1] == temp - 1) {
                   N = N - 1;
               }
               temp = dp[N];
               res.add(N);
           } else if (N % 3 == 0) {
               if (dp[N / 3] == temp - 1) {
                   N = N / 3;
               } else if (dp[N - 1] == temp - 1) {
                   N = N - 1;
               }

               temp = dp[N];
               res.add(N);
           } else {
               N = N - 1;
               temp = dp[N];
               res.add(N);
           }
       }

       for( int r : res){
           System.out.print(r+ " ");
       }

    }
}