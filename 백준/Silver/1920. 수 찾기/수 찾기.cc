#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bn(vector<int>& A,int target){
    int start=0;
    int end=A.size()-1;

    while(start<=end){
        int mid=(start+end)/2;
        if(target==A[mid])
            return 1;
        else if(target<A[mid])
            end=mid-1;
        else
            start=mid+1;
    }
    return 0;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int M;
    cin>>M;


    sort(A.begin(),A.end());

    for(int i=0;i<M;i++){
    int target;
    cin>>target;
    cout<<bn(A,target)<<'\n';}


    return 0;
}

