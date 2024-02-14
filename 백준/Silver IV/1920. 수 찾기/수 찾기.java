import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;




public class Main {
    public static int bn(int[] arr, int key) {
        int start = 0;
        int end = arr.length - 1;


        while (start <= end) {

            int mid = (start + end) / 2;    // 중간위치를 구한다.

            // key값이 중간 위치의 값보다 작을 경우
            if (key < arr[mid]) {
                end = mid - 1;
            }
            // key값이 중간 위치의 값보다 클 경우
            else if (key > arr[mid]) {
                start = mid + 1;
            }
            // key값과 중간 위치의 값이 같을 경우
            else {
                return 1;
            }
        }
        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());

       int N=Integer.parseInt(st.nextToken());
       int[] arr=new int[N];

       st= new StringTokenizer(br.readLine());
       for(int i=0;i<N;i++){
           arr[i]=Integer.parseInt(st.nextToken());
       }

       Arrays.sort(arr);

        st= new StringTokenizer(br.readLine());
       int M=Integer.parseInt(st.nextToken());

        st= new StringTokenizer(br.readLine());
        for(int i=0;i<M;i++){
            int q=Integer.parseInt(st.nextToken());
            System.out.println(bn(arr,q));
        }









    }
}
