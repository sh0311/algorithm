import java.io.*;
import java.util.*;



public class Main {



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m= Integer.parseInt(st.nextToken());
        HashMap<String,Integer> h= new HashMap<>();
        ArrayList<String> ar= new ArrayList<>();
        int cnt=0;

        for(int i=0;i<n;i++){
            st=new StringTokenizer((br.readLine()));
            h.put(st.nextToken(),1);
        }
        for(int i=0;i<m;i++){
            st=new StringTokenizer((br.readLine()));
            String now=st.nextToken();
            int num = h.getOrDefault(now, 0);
            if(num>=1){
                ar.add(now);
                cnt+=1;
            }

        }

        System.out.println(cnt);

        Collections.sort(ar);
        for(int i=0;i<ar.size();i++){
            System.out.println(ar.get(i));
        }


    }

}