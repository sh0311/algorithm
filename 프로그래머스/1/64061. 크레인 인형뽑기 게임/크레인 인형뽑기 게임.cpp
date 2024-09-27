#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    stack<int> st;
    
    int cnt=0;
    
    for(int i=0;i<moves.size();i++){
        
        int index=moves[i]-1;
        
        for(int j=0;j<board.size();j++){
            
                if(board[j][index]==0)
                    continue;
        
                int doll=board[j][index];
                board[j][index]=0;
                
                if(!st.empty() && st.top()==doll){
                    st.pop();
                    cnt+=2;
                }else{
                     st.push(doll);
                }
             break;
        }
                
        }
        
    
    return cnt;
}