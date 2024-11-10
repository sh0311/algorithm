#include <iostream>
#include <vector>


int check[3001]={0};

using namespace std;



int sol(int N, int c, vector<int>& belt, int k) {
    check[c]=1;
    int cnt=1;

        for(int i=0;i<k;i++) {
            if(belt[i]!=c) {
                check[belt[i]]++;
                if(check[belt[i]]==1) {
                    cnt++;
                }
                }
            }


        int tmp=cnt;
        for(int i=1;i<N;i++) {

            if(belt[i-1]!=c) {
                check[belt[i-1]]--;
                if(check[belt[i-1]]<=0)
                    tmp--;
            }


            int end=(i+k-1)%N;

            if(belt[end]!=c) {
                check[belt[end]]++;
                if(check[belt[end]]==1) {
                    tmp++;
                }
            }
            cnt=max(cnt, tmp);

        }
        return cnt;
    }



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, d, k, c;
    cin>>N>>d>>k>>c;

    vector<int> belt(N);

    for(int i=0;i<N;i++) {
        cin>>belt[i];
    }

    int res=sol(N,c, belt, k);

    cout<<res;

    return 0;

}
