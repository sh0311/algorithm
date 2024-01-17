import java.io.*;
import java.util.*;



public class Main {


    public static void main(String[] args) throws NumberFormatException,IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num=Integer.parseInt(br.readLine());
        int[] arr= new int[num];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<num;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        int i=0;
        int j=arr.length-1;
        int mim=Integer.MAX_VALUE;
        int m1=0;
        int m2=0;

        while(i<j){
            int sum=arr[i]+arr[j];
            if (Math.abs(sum)<mim){
                mim=Math.abs(sum);
                m1=arr[i];
                m2=arr[j];
            }
            if (sum>0){
                j--;
            }
            else{
                i++;
            }

        }
        System.out.println(m1 + " " + m2);

    }

}