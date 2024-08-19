#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int weight, firstL, L, A, consume, T, D;

    cin >> weight >> firstL >> T;
    cin >> D >> L >> A;

    int daesa=firstL;

    int firstWeight=weight;
    int secondWeight=weight;


    for (int i = 0; i < D; i++) {
        firstWeight+=L - (firstL + A);
        int weightChange = L - (daesa + A);
        secondWeight+=weightChange;

        if (abs(weightChange) > T) {
            daesa+=floor(weightChange/2.0);
        }
    }

    if(firstWeight<=0)
        cout<<"Danger Diet\n";
    else
        cout << firstWeight << " " << firstL<<'\n';


    if(secondWeight<=0||daesa<=0)
        cout<<"Danger Diet\n";
    else{
        cout<< secondWeight << " "<<daesa<<" ";
        if(firstL-daesa>0){
            cout<<"YOYO";
        }
        else
            cout<<"NO";
    }


}