/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    vector<int> result(n,0);
    stack<pair<int,int>> st;
    
    for(int i=0;i<n;i++){
        int height;
        cin>>height;
        
        if(!st.empty()){
            //stack 바로 위에있는 게 내꺼보다 큰지 확인
            if(st.top().second>height){
                result[i]=st.top().first;
                st.push({i+1, height});
                continue;
            }
            while(!st.empty()){
                // 종료조건
                if(st.top().second>height){
                    result[i]=st.top().first;
                    st.push({i+1, height});
                    break;
                }
                st.pop();
            }
            
        }
        //첫시작, 자기보다 큰 애 못 찾음
        if(st.empty()){
            result[i]=0;
            st.push({i+1,height});
        }
        
    }
    
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }

    return 0;
}