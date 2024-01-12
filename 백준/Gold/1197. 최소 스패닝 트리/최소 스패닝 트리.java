import java.io.*;
import java.util.*;


public class Main {

    public static int find(int x,int[] parent){
        if (parent[x]==x)
            return parent[x];
        return find(parent[x],parent);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int V=Integer.parseInt(st.nextToken());
        int E=Integer.parseInt(st.nextToken());

        int[][] graph= new int[E][3];
        int[] parent = new int[V+1];

        for(int i=0;i<E;i++){
            st=new StringTokenizer(br.readLine());
            graph[i][0]=Integer.parseInt(st.nextToken());
            graph[i][1]=Integer.parseInt(st.nextToken());
            graph[i][2]=Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<V+1;i++){
            parent[i]=i;
        }

        Arrays.sort(graph, (o1,o2)->(o1[2]-o2[2]));

        int cnt=0;
        for(int i=0;i<E;i++){
            int p0=find(graph[i][0],parent);
            int p1=find(graph[i][1],parent);
            if (p0!=p1){
                if (p0>p1){
                    parent[p0]=p1;
                }
                else if (p0<p1){
                        parent[p1]=p0;
                }
                cnt+=graph[i][2];
            }
        }
        System.out.println(cnt);
    }

}