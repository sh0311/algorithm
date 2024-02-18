import java.io.*;
import java.util.*;

public class Main {




    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n=Integer.parseInt(st.nextToken());
        int q=Integer.parseInt(st.nextToken());

        boolean[] visited=new boolean[n+1];

        for(int i=0;i<q;i++){
            int key=Integer.parseInt(br.readLine());
            int num=key;
            Stack<Integer> stack=new Stack<>();
            boolean can=true;

            while(num>1){
                stack.push(num);
                num/=2;
            }
            while(!stack.isEmpty()){
                int targ=stack.pop();
                if(visited[targ]){
                    System.out.println(targ);
                    can=false;
                    break;
                }

            }
            if(can){
                System.out.println(0);
                visited[key]=true;
            }
        }

    }}
