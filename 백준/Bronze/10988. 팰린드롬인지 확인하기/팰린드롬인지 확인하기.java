import java.util.*;


public class Main{
    public static void main(String[] args)throws Exception{
        Scanner sc= new Scanner(System.in);
        String word=sc.next();
        sc.close();
        int len=word.length();
        int half=len/2;
        int state=1;

        for(int i=0;i<half;i++){
            if(word.charAt(i)!=word.charAt(len-1-i)){
                state=0;
            }}

        System.out.println(state);}}