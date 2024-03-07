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

    int n, m;
    cin >> n >> m;

    vector<long long> S(n, 0); // 벡터 크기 수정
    vector<long long> cnt(m, 0); // 벡터 크기 수정

    for(int i = 0; i < n; i++){ // 누적합 계산 시 0부터 시작
        long long temp;
        cin >> temp;
        if (i == 0) S[i] = temp;
        else S[i] = S[i - 1] + temp;
        cnt[S[i] % m]++;
    }

    long long answer = 0;

    for(int i = 0; i < m; i++){
        answer += (cnt[i] * (cnt[i] - 1)) / 2;
    }

    cout << answer + cnt[0];

    return 0;
}
