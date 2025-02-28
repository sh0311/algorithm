#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> med;
vector<vector<pair<int, int>>> dic;
vector<bool> visited;
int res=1e6;
vector<int> li;
int n;

void sol(int cnt){
    // 다 구매함 (복잡하니까 여기서 차례로 물약 사면서 가격 수정)
    if(cnt==n){
        vector<int> tmp=med;
        int val=0;
        
        for(int i=0;i<n;i++){
            int idx=li[i];
            val+=tmp[idx];
            
            for(int j=0;j<dic[idx].size();j++){
                int t=dic[idx][j].first;
                tmp[t]=tmp[t]-dic[idx][j].second<1?1:tmp[t]-dic[idx][j].second;
            }
        }
        
        res=min(res, val);
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // 구매
            visited[i]=true;
            li.push_back(i);
            sol(cnt+1);
            visited[i]=false;
            li.pop_back();
        }
    }
}


int main()
{
    cin>>n;
    
    med.resize(n+1);
    dic.resize(n+1,vector<pair<int, int>>());
    visited.resize(n+1, false);
    
    for(int i=1;i<=n;i++){
        cin>>med[i];
    }
    
    
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        
        for(int j=0;j<num;j++){
            int idx, discount;
            cin>>idx>>discount;
            dic[i].push_back({idx, discount});
        }
    }
    
    sol(0);
  
    cout<<res;
    
    return 0;
}