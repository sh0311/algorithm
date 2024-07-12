#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> vec;
vector<bool> visited;
static void BFS(int start);
vector<int> dist;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());

    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int val;
        cin >> val;
        int start=0;
        int end=n-1;
        int status=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(A[mid]>val){
                end=mid-1;
            }
            else if (A[mid]<val){
                start=mid+1;
            }
            else{
                status=1;
                break;
            }
        }
        cout<<status<<'\n';

    }

    }

