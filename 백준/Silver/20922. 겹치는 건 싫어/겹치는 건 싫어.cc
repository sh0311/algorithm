#include <iostream>
#include <vector>


using namespace std;

int check[200000]={0};

int sol(vector<int>& v, int k) {
    int len=0;

    for(int i=0;i<v.size();i++) {
        if(check[v[i]]>=k) {
            break;
        }
        check[v[i]]++;
        len++;
    }

    int tmp=len;

    for(int i=1;i<v.size();i++) {
        if(i+len>v.size()) {
            return len;
        }

        check[v[i-1]]--;
        tmp--;

        for(int j=i+tmp;j<v.size();j++) {
            if(check[v[j]]>=k) {
                break;
            }else {
                check[v[j]]++;
                tmp++;
            }
        }
        len=max(len, tmp);


    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    int val=sol(v, k);
    cout<<val;

    return 0;

}
