#include <string>
#include <vector>
#include <stack>

using namespace std;

//균형잡힌 문자열의 마지막 index +1
int balance(string p){
    int cnt=0;
    
    for(int i=0;i<p.length();i++){
        if(p[i]=='('){
            cnt+=1;
        }
        else{
            cnt-=1;
        }
        if(cnt==0){
            return i;
        }  
    }
    return -1;
    
}
bool right(string u){
    stack<char> st;
    for(int i=0;i<u.length();i++){
        if(u[i]=='('){
            st.push(u[i]);
        }else{
            if(st.empty())
                return false;
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}
string change(string u){
    int last=u.length()-1;
    string tmp=u.substr(1,last-1);
    
    string res="";
    for(int i=0;i<tmp.length();i++){
        if(tmp[i]=='('){
            res+=")";
        }else{
            res+="(";
        }
    }
    return res;
}

string sol(string p){
    string target="";
    
    if(p.empty()){
        return "";
    }
    
    int idx=balance(p);
    string u=p.substr(0,idx+1);
    string v=p.substr(idx+1);
    
    if(right(u)){
        target=u+sol(v);       
    }
    else{
        target+="(";
        target+=sol(v);
        target+=")";
        target+=change(u);
    }
    return target;
    
    
    
}
string solution(string p) {
    string res=sol(p);
    return res;
}