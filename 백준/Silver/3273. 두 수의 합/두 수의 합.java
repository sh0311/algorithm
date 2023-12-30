import java.util.*;


public class Main {
    public static void main(String[] args) {
        int cnt=0;
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            int num=sc.nextInt();
            arr.add(num);
        }
        Collections.sort(arr);
        int x=sc.nextInt();
        int left=0;
        int right=arr.size()-1;
        while (left<right){
            int k=arr.get(left)+arr.get(right);
            if (k<x){
                left+=1;
            }
            else if (k>x){
                right-=1;
            }
            else{
                cnt+=1;
                left+=1;
            }
        }
        System.out.println(cnt);

    }
}