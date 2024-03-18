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

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int cnt=0;

    for(int i=0;i<n;i++){
        int start=0;
        int end=n-1;
        int k=v[i];
        while(start<end){
            if(v[start]+v[end]>k){
                end-=1;
            }
            else if(v[start]+v[end]<k){
                start+=1;
            }
            else{
                if(start!=i&&end!=i){
                    cnt+=1;
                    break;
                }
                else if(start==i){
                    start+=1;
                }
                else if(end==i){
                    end-=1;
                }

            }
        }

    }cout<<cnt;

    return 0;
}
