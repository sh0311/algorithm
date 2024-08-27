#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    while(true){
        string input;
        getline(cin, input);
        if(input==".")
            break;

        stack<char> st;
        string val="yes";

        for(int i=0;i<input.length();i++){
            if((input[i]=='(')||(input[i]=='[')){
                st.push(input[i]);
            }
            else if(input[i]==')'){
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }
                else{
                    val="no";
                    break;
                }
            }
            else if(input[i]==']'){
                if(!st.empty()&&st.top()=='['){
                    st.pop();
                }
                else{
                    val="no";
                    break;
                }
            }
        }
        if(st.empty()&&val=="yes"){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
    }
}




