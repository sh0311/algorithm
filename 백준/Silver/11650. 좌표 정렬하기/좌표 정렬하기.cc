#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));

    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++){
            cin>>v[i][j];
        }
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) {
        for (int j = 0; j < 2; j++) {
            cout << v[i][j]<<" ";
        }
        cout<<'\n';
    }


    return 0;
}