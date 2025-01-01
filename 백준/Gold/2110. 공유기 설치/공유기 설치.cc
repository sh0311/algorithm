#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt(int mid, vector<int> &v) {

    int num=1;
    int before=v[0];

    for(int i=1;i<v.size();i++) {
        if(v[i]-before>=mid) {
            num++;
            before=v[i];
        }
    }
    return num;
}

int sol(vector<int> &v, int c) {

    int start=1;
    int end=v[v.size()-1]-v[0];
    int tmp;

    while(start<=end) {
        int mid=(start+end)/2;
        int num=cnt(mid,v);

        if(num<c) {
            end=mid-1;
        }else {
            start=mid+1;
            tmp=mid;
        }
    }

    return tmp;
}


int main() {

    int n,c;
    cin>>n>>c;

    vector<int> house(n);
    for(int i=0;i<n;i++) {
        cin>>house[i];
    }

    sort(house.begin(), house.end());

    if(c==2) {
        cout<<house[n-1]-house[0];
    }else {
        int res=sol(house,c);
        cout<<res;
    }

    return 0;
}
