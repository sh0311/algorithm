#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    stack<int> st;

    int result[n];

    for(int i=0;i<n;i++){
        while(!st.empty()&&A[i]>A[st.top()]){
            result[st.top()]=A[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        result[st.top()]=-1;
        st.pop();
    }

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }


    return 0;
}

