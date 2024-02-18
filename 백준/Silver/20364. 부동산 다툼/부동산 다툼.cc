#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<bool> visited(n+1,false);

    for(int i=0;i<q;i++){
        int num;
        cin>>num;
        int key=num;
        stack<int>st;
        bool canreach=true;
        while(key>1){
            st.push(key);
            key/=2;
        }
        while(!st.empty()){
            int targ=st.top();
            if(visited[targ]){
                cout<<targ<<'\n';
                canreach=false;
                break;
            }
            else
                st.pop();
        }
        if (canreach){
            cout<<0<<'\n';
            visited[num]=true;
        }


    }
    return 0;
}

