#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    int b[n];

    int s=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<>());

    for(int i=0;i<n;i++){
        s+=(a[i]*b[i]);
    }
    cout<<s<<'\n';

    return 0;
}

