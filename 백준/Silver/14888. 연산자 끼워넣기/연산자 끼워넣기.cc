#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
vector<int> number;
vector<int> op;   // +, -, *, /
int res;
int cnt;
int min_val=1000000000;
int max_val=-1000000000;

void dfs(int cnt, int res){
    if(cnt==n-1){
        min_val=min(min_val, res);
        max_val=max(max_val, res);
        return;
    }

    for(int i=0;i<4;i++){
        if(op[i]>0){
            op[i]--;

            switch(i){
                case 0:
                    dfs(cnt+1, res+number[cnt+1]); // 더하기
                    break;
                case 1:
                    dfs(cnt+1, res-number[cnt+1]); // 빼기
                    break;
                case 2:
                    dfs(cnt+1, res*number[cnt+1]); // 곱하기
                    break;
                case 3:
                    dfs(cnt+1, res/number[cnt+1]); // 나누기
                    break;
            }
            op[i]++;  //감소시킨 경우에만 증가시켜야 하므로 if문 안에서 증가시켜줘야 함
        }

    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    number.resize(n);
    op.resize(4);

    for(int i=0;i<n;i++){
        cin>>number[i];
    }

    for(int i=0;i<4;i++){
        cin>>op[i];
    }

    cnt=0;

    dfs(0,number[0]);

    cout<<max_val<<'\n'<<min_val;



    return 0;
}
