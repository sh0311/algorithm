import java.io.*;
import java.util.*;



public class Main {

    static int[] parent;
    static int find(int x){
        if (parent[x]==x)
            return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b){
        int pa=find(a);
        int pb=find(b);

        if (pa==pb)
            return;
        if (pa<pb)
            parent[pb]=pa;
        else parent[pa]=pb;
        return;
    }



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        parent=new int[n+1];
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        int num=0;
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());

            if (find(a)==find(b)){
                num=i+1;
                break;
            }
            union(a,b);

        }
        System.out.println(num);


    }

}