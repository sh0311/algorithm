#include <iostream>
#include <vector>


using namespace std;

int count(vector<char> &line, int k){
    int cnt=0;

    vector<bool> visited(line.size(), false);

    for(int i=0;i<line.size();i++){
        if(line[i]=='P'){
            for(int j=i-k;j<=i+k;j++){
                if(line[j]=='H' && visited[j]==false){
                    cnt+=1;
                    visited[j]=true;
                    break;
                }
            }
        }


    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<char> line(n);

    for(int i=0;i<n;i++){
        char s;
        cin>>s;
        line[i]=s;
    }

    int res=count(line,k);

    cout<<res;

    return 0;
}

