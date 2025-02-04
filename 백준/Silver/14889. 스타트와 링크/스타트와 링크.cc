/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> s;
vector<int> start;
int cnt=0;
int n;
int visited[21]={false};
//불가능한 최댓밗
int sub=1000;

void count(){
    vector<int> link;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            link.push_back(i);
        }
    }
    //스타트 연산
    int ssum=0;
    for(int i=0;i<n/2;i++){
        for(int j=i+1;j<n/2;j++){
            ssum+=s[start[i]][start[j]]+s[start[j]][start[i]];
        }
    }
    //링크 연산
    
    int lsum=0;
    for(int i=0;i<n/2;i++){
        for(int j=i+1;j<n/2;j++){
            lsum+=s[link[i]][link[j]]+s[link[j]][link[i]];
        }
    }
    //차이 구하기
    sub=min(sub,abs(ssum-lsum));
}


void dfs(int k, int cnt){
    //탈출조건
    if(cnt==n/2){
        count();
        return;
    }
    for(int i=k;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            start.push_back(i);
        }
        dfs(i+1, cnt+1);
        start.pop_back();
        visited[i]=false;
    }
}



int main()
{
    cin>>n;
    
    s.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }
    
    dfs(0,0);
    cout<<sub;

    return 0;
}