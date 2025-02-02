/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int> &li, int s){
    int l=0, r=0, ans=100000, tmp=0, sum=0;
    bool flag=false;
    while(r<li.size()){
        sum+=li[r];
        tmp++;
        while(sum>=s){
            flag=true;
            ans=min(ans, tmp);
            sum-=li[l];
            tmp--;
            l++;
        }
        r++;
    }
    if(!flag){
        return 0;
    }else{
        return ans;
    }
    
}

int main()
{
    int n,s;
    cin>>n>>s;
    
    vector<int> li(n);
    for(int i=0;i<n;i++){
        cin>>li[i];
    }
    
    int res=sol(li,s);
    cout<<res;
    
    return 0;
}