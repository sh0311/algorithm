#include <string>
#include <vector>

#include <iostream>
#include <vector>

using namespace std;


    int backtracking(vector<bool>& columns, vector<bool>& diag_up, vector<bool>& diag_down, int n, int row){
        
        if(row==n)
            return 1;
        
        int answer=0;
        for(int i=0;i<n;++i){
            //놓을 수 있는지 체크
            if(columns[i] || diag_up[i+row] || diag_down[i-row+n-1]){
                 continue;
            }
              
            //퀸 놓기
            columns[i]=true;
            diag_up[i+row]=true; //같은 대각선 상에 위치하면 row+col이 일정하므로
            diag_down[i-row+n-1]=true; //같은 대각선 상에 위치하면 차가 일정해서 i-row, 근데 음수될수있어서 n-1 더해줌
            
            answer+=backtracking(columns, diag_up, diag_down, n, row+1);
            
            //퀸 원위치
            columns[i]=false;
            diag_up[i+row]=false;
            diag_down[i-row+n-1]=false;
            
        }
        return answer;
        
    }
 int solution(int n) {
        vector<bool> columns(n, false);
        vector<bool> diag_up(2*n-1, false);
        vector<bool> diag_down(2*n-1, false);
        
        return backtracking(columns,diag_up,diag_down,n,0);
    }
