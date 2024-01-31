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
    vector<int> input(n);
    for(int i=0;i<n;i++) {
        cin>>input[i];}
    int max=*max_element(input.begin(), input.end());

    vector<int> li(max+1);

        for(int i=2;i<=max;i++){
            li[i]=i;
        }
        for(int j=2;j*j<=max;j++){
            if(li[j]==j){
                for(int k=j*j;k<=max;k+=j){
                    if(li[k]==k)
                        li[k]=j;}
            }
        }

        for(int i=0;i<n;i++) {
            int num=input[i];
            while (num > 1) {
                cout << li[num] << " ";
                num /= li[num];
            }
            cout << '\n';
        }
    return 0;
}

