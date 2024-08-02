#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>
#include <sstream>

using namespace std;
vector<string> split(string input, char delimiter);
int mySum(string a);

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    vector<string> res=split(s, '-');
    int sum=0;
    for(int i=0;i<res.size();i++){
        if(i==0){
            sum+=mySum(res[i]);
        }
        else{
            sum-=mySum(res[i]);
        }
    }
    cout<<sum;
}
vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splitdata;
    while(getline(mystream, splitdata,delimiter)){
        result.push_back(splitdata);
    }
    return result;
}

int mySum(string a){
    int sum=0;
    vector<string> temp=split(a,'+');
    for(int i=0;i<temp.size();i++){
        sum+=stoi(temp[i]);
    }
    return sum;
}



