import java.io.*;
import java.util.*;



public class Main {
    static class Node{
        int num;
        Node right, left;

        Node(int n){
            this.num=n;
        }

        void insert(int num){
            if(num>this.num){
                if (this.right==null){
                    Node inp=new Node(num);
                    this.right=inp;
                }
                else{
                    this.right.insert(num);
                }
            }
            else if(num<this.num){
                if (this.left==null){
                    Node inp=new Node(num);
                    this.left=inp;
                }
                else{
                    this.left.insert(num);
                }
            }


        }

    }

    static void post(Node root){
        if (root.left!=null)
            post(root.left);
        if (root.right!=null)
            post(root.right);
        System.out.println(root.num);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Node root=new Node(Integer.parseInt(br.readLine()));

        String input;
        while(true){
            input=br.readLine();
            if(input==null||input.equals(""))
                break;
            int inpu=Integer.parseInt(input);
            root.insert(inpu);
        }
        post(root);


    }
}