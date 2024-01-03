
import java.util.*;



public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt();
        ArrayList<ArrayList<Integer>> graph= new ArrayList<>();
        for (int i=0;i<=N+1;i++){
            graph.add(new ArrayList<>());  //초기화
        }
        boolean[] visited=new boolean[N+1];


        int[] parent = new int[N+1];

        for(int i=1;i<N;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        Deque<Integer> deq=new LinkedList<>();
        deq.addFirst(1);
        visited[1]= true;
        while(!deq.isEmpty()) {
            int c = deq.remove();
            for (int i = 0; i < graph.get(c).size(); i++) {
                int tmp = graph.get(c).get(i);
                if (!visited[tmp]) {
                    deq.addLast(tmp);
                    visited[tmp] = true;
                    parent[tmp] = c;
                }
            }
        }

        for(int i=2;i<N+1;i++){
            System.out.println(parent[i]);

        }




    }
}