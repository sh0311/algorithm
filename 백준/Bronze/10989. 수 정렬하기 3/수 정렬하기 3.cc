#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int count[10001]={0}; //배열 초기화하는 방법

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        count[num]+=1;

    }

    for(int i=1;i<10001;i++) {
        if (count[i]) {
            for (int j = 0; j < count[i]; j++)
                cout << i << '\n';
        }
    }


    return 0;
}
