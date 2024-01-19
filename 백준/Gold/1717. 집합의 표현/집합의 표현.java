import java.io.*;
import java.util.*;



public class Main {

    static int parent[];

    static int find(int x){
        if (parent[x]==x)
            return x;
        else{
            parent[x]=find(parent[x]);
            return parent[x];
        }
    }

    static boolean union(int b,int c){
        int pb=find(b);
        int pc=find(c);

        if (pb==pc)
            return false;
        if(pb<pc){
            parent[pc]=pb;
        }
        else{
            parent[pb]=pc;
        }
        return true;
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
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());

            if(a==0)
                union(b,c);

            else{
                if (find(b)==find(c)){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
            }
        }


    }

}