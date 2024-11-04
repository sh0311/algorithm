#include <iostream>
#include <vector>

using namespace std;



bool check(int k, vector<int>& v, int dist) {
    vector<bool> visited(dist+1, false);
    if((v[0]-k)>0) {
        return false;
    }

    visited[0]=true;
    visited[v[0]]=true;

    if (v[0] + k <= dist) {
        visited[v[0] + k] = true;
    }


    if((v[v.size()-1]+k)<dist) {
        return false;
    }
    visited[dist]=true;

    for(int i=1;i<v.size();i++) {
        visited[v[i]]=true;

        if(v[i]-k>v[i-1]+k) {
            return false;
        }
        
        if (v[i] - k >= 0) {
            visited[v[i] - k] = true;
        }
        if (v[i] + k <= dist) {
            visited[v[i] + k] = true;
        }
    }
    return true;
}


int binary(vector<int>& v, int dist) {
    int start=1;
    int end=dist;

    while(start<=end){
        int mid=(start+end)/2;
        if(check(mid,v, dist)) {
            end=mid-1;

        } else {
            start=mid+1;

        }
    }
    return start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int m;
    cin >> n >> m;

    vector<int> v(m);

    for(int i=0;i<m;i++) {
        cin>>v[i];
    }

    int val=binary(v,n);
    cout<<val;


    return 0;

}
