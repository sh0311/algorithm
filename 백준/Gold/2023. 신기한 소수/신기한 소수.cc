#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

bool isPrime(int x);
void DFS(int num, int len);
static int n;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);


}
void DFS(int num, int len){
    if(len>n){
        return;
    }
    if(len==n){
        if(isPrime(num))
            cout<<num<<'\n';
        return;
    }
    if(isPrime(num)){
        DFS(10*num+1,len+1);
        DFS(10*num+3,len+1);
        DFS(10*num+5,len+1);
        DFS(10*num+7,len+1);
        DFS(10*num+9,len+1);
    }


}
bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }

    }
    return true;
}