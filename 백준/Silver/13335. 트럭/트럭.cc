/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <deque>

using namespace std;

bool check(int first, deque<int> &road, int w, int l){
    if(road.size()==w){
        road.pop_front();
        int sum=0;
        for(int i=0;i<road.size();i++){
            sum+=road[i];
        }
        if(sum+first<=l){
            return true;
        }
    }
    return false;
}

int sol(deque<int> cars, int w, int l){
    deque<int> road;
    int cnt=0;
    
    while(!cars.empty()){
        int first = cars.front();
        
        if(check(first, road, w, l)){
            cars.pop_front();
            road.push_back(first);
            cnt++;
        }
        else{
            cnt++;
            road.push_back(0);
            if(road.size()>w){
                road.pop_front();
            }
        }
    }
    return cnt;
}



int main()
{
    int n, w, l;
    cin>>n>>w>>l;
    
    deque<int> cars;
    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        cars.push_back(v);
    }
    
    int res=sol(cars, w, l);
    cout<<res;

    return 0;
}