#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    int M;
    cin>>M;

    cout<<0<<" "<<1<<'\n';

    for(int i=2;i<=M;i++){
        cout<<1<<" "<<i<<'\n';

    }

    if(N-M-1>0){
        for(int i=M;i<N-1;i++)
        cout<<i<<" "<<i+1<<'\n';
    }





    return 0;
}

