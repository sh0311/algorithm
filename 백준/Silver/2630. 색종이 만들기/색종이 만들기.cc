/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int blue=0;
int white=0;

bool check(int i1, int i2, int j1, int j2){
    for(int i=i1;i<=i2;i++)
        for(int j=j1;j<=j2;j++){
            if(graph[i][j]!=graph[i1][j1]){
                return false;
            }
        }
    return true;
}

void sol(int i1, int i2, int j1, int j2){
    if(check(i1, i2, j1, j2)){
        if(graph[i1][j1]==1){
            blue++;
        }
        else if(graph[i1][j1]==0){
            white++;
        }
        return;
    }
    
    int midi=(i1+i2)/2;
    int midj=(j1+j2)/2;
    
    sol(i1,midi,j1,midj);
    sol(midi+1,i2,j1,midj);
    sol(i1,midi,midj+1,j2);
    sol(midi+1,i2,midj+1,j2);
}

int main()
{
    int n;
    cin>>n;
    graph.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    sol(0,n-1,0,n-1);
    
    cout<<white<<'\n'<<blue;

    return 0;
}