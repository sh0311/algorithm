#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> v;

string quad(int N, int y, int x){
    char key=v[y][x];
    for(int i=y;i<y+N;i++){
        for(int j=x;j<x+N;j++){
            if(v[i][j]!=key){
                N=N/2;
                return'('+
                quad(N,y,x)+
                quad(N,y,x+N)+
                quad(N,y+N,x)+
                quad(N,y+N,x+N)+
                ')';
            }

        }}
        return string(1,key); //크기가 1이고 내용이 key인 문자열
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    v.resize(N,vector<char>(N));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>v[i][j];
        }

    cout<<quad(N,0,0);
    return 0;
}

