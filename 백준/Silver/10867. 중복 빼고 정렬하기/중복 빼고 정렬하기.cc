#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int num;

    map<int, int> l;
    for(int i=0;i<n;i++){
        cin>>num;
        l.insert(pair<int, int>(num,1));}

    map<int, int>::iterator it;

    for(it=l.begin();it!=l.end();++it){
        cout<<it->first<<'\n';
    }

    return 0;
}

