#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int put;
        cin>>put;
        vec.insert(vec.begin(),put);
    }
    sort(vec.begin(),vec.end());

    for(int i:vec) cout<<i<<'\n';

    return 0;
}

