#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int start=*max_element(vec.begin(), vec.end());
    int end=accumulate(vec.begin(), vec.end(),0);
    int val;
    while(start<=end){
        int mid=(start+end)/2;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(sum+vec[i]>mid){
                count+=1;
                sum=0;
            }
            sum+=vec[i];
        }
        if(sum>0)
            count+=1;

        if(count>m){
            start=mid+1;
        }
        else{
            val=mid;
            end=mid-1;
        }
    }
    cout<<val;

    }

