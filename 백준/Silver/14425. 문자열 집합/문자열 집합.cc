#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    string input;

    string target;

    int cnt=0;

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin>>input;
        s.insert(input);
    }

    for(int i=0;i<m;i++){
        cin>>target;
        auto it=s.find(target);
        if(it!=s.end()){
            cnt+=1;
        }
    }

    cout<<cnt;
}