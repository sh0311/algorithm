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

int sol(int a, int b){
    queue<pair<long long, int>> q;
    q.push({a,0});
    
    int ans=-2;
    
    while(!q.empty()){
        long long node=q.front().first;
        int depth=q.front().second;
        
        if(node==b){
            ans=depth;
            break;
        }
        else if(node>b){
            q.pop();
            continue;
        }

        q.pop();
        
        q.push({node*2,depth+1});
        q.push({node*10+1,depth+1});
    }
    
    return ans+1;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    int res=sol(a,b);
    cout<<res;
    

    return 0;
}