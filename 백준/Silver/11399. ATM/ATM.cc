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


    for(int i=1;i<n;i++){
        int idx=i;
        int value=v[idx];
        for(int j=0;j<i;j++){
            if(v[j]>value){
                idx=j;
                for(int k=i-1;k>=idx;k--)
                    v[k+1]=v[k];
                v[idx]=value;
                break;
            }

        }
        }
        vector<int> s(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                s[i]+=v[j];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=s[i];
        }
        cout<<sum;



    return 0;
}

