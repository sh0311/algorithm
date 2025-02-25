/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> egg;
vector<bool> broken;
int mx=0;
int cnt=0;



void sol(int up){
    
    if(up==n){
        mx=max(mx, cnt);
        return;
    }
    if(broken[up] || cnt==n-1){
        sol(up+1);
        return;
    }
    for(int i=0;i<n;i++){
        if(i==up || broken[i])
            continue;
            
        //내려치는 애 손상
        int nstrongup=egg[up].first-egg[i].second;
        //당하는 애 손상
        int nstrongdown=egg[i].first-egg[up].second;
        
        if(nstrongup<=0){
            broken[up]=true;
            cnt++;
        }
        if(nstrongdown<=0){
            broken[i]=true;
            cnt++;
        }
        
        egg[up].first=nstrongup;
        egg[i].first=nstrongdown;
        
        sol(up+1);
        
        if(egg[up].first<=0){
            broken[up]=false;
            cnt--;
        }
        if(egg[i].first<=0){
            broken[i]=false;
            cnt--;
        }
        
        egg[up].first+=egg[i].second;
        egg[i].first+=egg[up].second;
    }
    
}

int main()
{
    cin>>n;
    
    broken.resize(n, false);
    
    for(int i=0;i<n;i++){
        int strong, weight;
        cin>>strong>>weight;
        egg.push_back({strong, weight});
    }
    
    sol(0);

    cout<<mx;

    return 0;
}