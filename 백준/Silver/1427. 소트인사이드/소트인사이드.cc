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

   string str;
   cin>>str;
    vector<int> v(str.size(),0);
   for(int i=0;i<str.size();i++){
       v[i]=stoi(str.substr(i,1));
   }

   for(int i=0;i<str.size();i++){
       int max_idx=max_element(v.begin(), v.end())-v.begin();
       int tmp=v[0];
       v[0]=v[max_idx];
       v[max_idx]=tmp;
       cout<<v[0];
       v.erase(v.begin());
   }




    return 0;
}

