/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph;
int n;
int cnt=0;

bool check(int target){

    for(int i=0;i<target;i++){
        int sub=target-i;
        if(graph[i]==graph[target] || graph[i]-sub==graph[target] ||graph[i]+sub==graph[target]){
            return false;
        }
    }
    return true;
}


void sol(int now){
   
   if(now==n){
       cnt++;
       return;
   }
   
   for(int i=0;i<n;i++){
       graph[now]=i;
       
       if(check(now)){
           sol(now+1);
       }
       graph.pop_back();
   }
   
}

int main()
{
    cin>>n;

    graph.resize(n);
    sol(0);
    
    cout<<cnt;
    

    return 0;
}