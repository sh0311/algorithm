#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

string add(string a, string b){
    int lenA=a.length();
    int lenB=b.length();

    int maxlen=max(lenA, lenB);

    a=string(maxlen-lenA,'0')+a;
    b=string(maxlen-lenB,'0')+b;

    string res;
    int carry=0;
    for(int i=maxlen-1;i>=0;i--){
        int val=(a[i]-'0')+(b[i]-'0')+carry;
        res+=val%10+'0';
        carry=val/10;

    }
    if(carry>0){
        res+=carry+'0';
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;

    string res=add(a,b);

    cout<<res;
}




