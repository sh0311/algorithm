#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int tmp=b;
        b=a%b;
        a=tmp;
    }return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;


    for(int i=0;i<t;i++){
        int num;
        cin>>num;
        vector<int> li(num);
        for(int j=0;j<num;j++){
            cin>>li[j];
        }
        long long cnt=0;
        for(int j=0;j<num;j++)
            for(int k=j+1;k<num;k++){
                cnt+=gcd(li[j],li[k]);
            }
        cout<<cnt<<'\n';


    }



    return 0;
}