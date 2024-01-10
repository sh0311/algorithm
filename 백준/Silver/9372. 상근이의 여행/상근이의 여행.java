import java.util.*;
import java.io.*;

public class Main {
    public static void main (String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(br.readLine());
        
        for (int i=0; i<T; i++) {
            
            Stack<Integer> stack = new Stack<>();
            
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            
            boolean[] visited = new boolean[N+1];
            List<Integer>[] link = new ArrayList[N+1];
            for (int j=1; j<=N; j++) link[j] = new ArrayList<>();
            
            
            for (int j=0; j<M; j++) {
                input = br.readLine().split(" ");
                int u = Integer.parseInt(input[0]);
                int v = Integer.parseInt(input[1]);
                link[u].add(v);
                link[v].add(u);
            }
            
            // 입력 끝
            
            // Last-in-First-out 인 스텍의 성질에 의해 출발 국가로부터 한쪽 방향으로 더 이상 방문할 국가가 없을 때까지 먼저 탐색한다.
            
            // 스텍에 시작 국가(어떠한 국가도 가능)를 넣는다.
            stack.push(1);
            int count = 0;
            
            while (!stack.isEmpty()) {
                
                // 현재 방문한 국가를 스텍에서 꺼내고 방문처리
                int now = stack.pop();
                
                visited[now] = true;
                
                for (int next : link[now]) {
                	// 현재 국가와의 비행 노선이 존재하는데 아직 방문하지 않은 국가라면 스텍에 넣는다.
                    if (!visited[next]) {
                        visited[next] = true;
                        count++;
                        stack.push(next);
                    }
                }
            }
            
            System.out.println(count);
        }
        
        br.close();
    }
}