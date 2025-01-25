#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        stack<char> st;
        string state="YES";
        string input;
        cin>>input;


        for(int j=0;j<input.length();j++)
        {
            if(input[j]=='(')
                st.push(input[0]);
            else if(input[j]==')'){
                if(st.empty()){
                    state="NO";
                    break;}
                else
                    st.pop();
            }
        }

    if(st.empty())
        cout<<state<<'\n';
    else
        cout<<"NO"<<'\n';}
    return 0;
}

