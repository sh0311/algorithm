#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

void cal(int n, stack<int>& st,vector<int>& vec, vector<int>& origin){
    for(int i=0;i<n;i++){
        while(!st.empty()&&origin[st.top()]<origin[i]){
            vec[st.top()]=origin[i];
            st.pop();
        }
        st.push(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    stack<int> st; //인덱스 저장
    vector<int>vec(n,-1);  //결과값 담는 벡터
    vector<int> origin(n); //초기값들 담는 벡터



    for(int i=0;i<n;i++){
        cin>>origin[i];
    }
    cal(n, st, vec, origin);

    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }

}




