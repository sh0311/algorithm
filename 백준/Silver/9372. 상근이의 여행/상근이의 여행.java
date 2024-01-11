import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {

            Stack<Integer> stack=new Stack<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
            for (int j = 0; j < N + 1; j++) {
                graph.add(new ArrayList<>());
            }

            boolean[] visited = new boolean[N + 1];


            for (int j = 0; j < M; j++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b= Integer.parseInt(st.nextToken());
                graph.get(a).add(b);
                graph.get(b).add(a);
            }

            stack.push(1);
            visited[1]=true;
            int count=0;
            while(!stack.isEmpty()){
                int nex=stack.pop();
                for(int next:graph.get(nex)){
                    if(!visited[next]){
                        visited[next]=true;
                        count+=1;
                        stack.push(next);
                    }
                }
            }
            System.out.println(count);

        }
        br.close();
    }

}