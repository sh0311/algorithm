#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sum(string v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(isdigit(v[i]))
            sum+=v[i]- '0';
    }
    return sum;
}
bool cmp(const string& v1, const string& v2){
    int sum1=sum(v1);
    int sum2=sum(v2);

    if(v1.size()!=v2.size())
        return v1.size()<v2.size();
    else if(sum1!=sum2)
        return sum1<sum2;
    return v1<v2;
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<string> vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<vec[i]<<'\n';
    }
}

