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

    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    for(int i=0;i<n-1;i++){
    q.pop();
    int tmp=q.front();
    q.push(tmp);
    q.pop();}


    int res=q.front();

    cout<<res;







    return 0;
}

