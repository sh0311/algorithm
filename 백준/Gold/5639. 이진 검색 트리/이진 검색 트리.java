import java.io.*;
import java.util.*;



public class Main {
    static ArrayList<Integer> tree=new ArrayList<>();
    static void post(int start, int end){
        if (start>end) return;
        int mid=end+1;
        for(int i=start+1;i<end+1;i++){
            if (tree.get(i)>tree.get(start)){
                mid=i;
                break;
            }
        }
        post(start+1,mid-1);
        post(mid,end);
        System.out.println(tree.get(start));
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;
        while(true){
            input=br.readLine();
            if(input==null||input.equals(""))
                break;
            tree.add(Integer.parseInt(input));
        }
        post(0,tree.size()-1);


    }
}