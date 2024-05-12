#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void quickSort(vector<int> &v, int k, int start, int end);
void partition(vector<int> &v, int start, int end);
void swap(vector<int> &v,int i, int j);

static vector<int> v;
static vector<int> temp;
void merge(int start, int end);

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int count[10001]={0};

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        count[num]+=1;
    }
    for(int i=0;i<10001;i++){
        if(count[i]!=0){
           for(int j=0;j<count[i];j++){
               cout<<i<<'\n';
           }
        }
    }
    return 0;



}