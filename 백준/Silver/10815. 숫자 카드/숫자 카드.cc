#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int target, vector<int>& card) {
    int start=0;
    int end=card.size()-1;

    while(start<=end){
        int mid=(start+end)/2;
        if(target==card[mid]) {
            return true;
        }
        if(target<card[mid]) {
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    return false;
}

void sol(vector<int>& card, vector<int>& candidate) {
    for(int i=0;i<candidate.size();i++) {
        if(check(candidate[i], card)) {
            cout<<1<<" ";
        }
        else {
            cout<<0<<" ";
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> card(n);
    for(int i=0;i<n;i++) {
        cin>>card[i];
    }
    sort(card.begin(), card.end());

    int m;
    cin >> m;

    vector<int> candidate(m);

    for(int i=0;i<m;i++) {
        cin>>candidate[i];
    }

    sol(card, candidate);


    return 0;

}
