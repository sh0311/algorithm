#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> zero;  // 빈 칸 좌표 저장
vector<vector<int>> sdoku(9, vector<int>(9));  // 9x9 스도쿠 보드

// 후보 숫자 찾기 함수: 가로, 세로, 3x3 네모에서 사용된 숫자 제외
vector<int> check(int i, int j) {
    vector<bool> isUsed(10, false);  // 1~9 사용 여부 체크
    vector<int> candidate;

    // 가로 탐색
    for (int k = 0; k < 9; k++) {
        if (sdoku[i][k] != 0) {
            isUsed[sdoku[i][k]] = true;
        }
    }

    // 세로 탐색
    for (int k = 0; k < 9; k++) {
        if (sdoku[k][j] != 0) {
            isUsed[sdoku[k][j]] = true;
        }
    }

    // 3x3 네모 탐색
    int start_x = (i / 3) * 3;
    int start_y = (j / 3) * 3;
    for (int x = start_x; x < start_x + 3; x++) {
        for (int y = start_y; y < start_y + 3; y++) {
            if (sdoku[x][y] != 0) {
                isUsed[sdoku[x][y]] = true;
            }
        }
    }

    // 사용되지 않은 숫자들을 후보로 추가
    for (int p = 1; p <= 9; p++) {
        if (!isUsed[p]) {
            candidate.push_back(p);
        }
    }

    return candidate;
}

// 백트래킹으로 스도쿠 풀이
bool solve(int idx) {
    if (idx == zero.size()) {
        return true;  // 모든 빈 칸을 채웠으면 성공
    }

    // 현재 빈 칸의 위치
    int i = zero[idx].first;
    int j = zero[idx].second;

    // 현재 칸에 넣을 수 있는 후보 숫자들 찾기
    vector<int> candidates = check(i, j);

    // 각 후보 숫자에 대해 시도
    for (int num : candidates) {
        sdoku[i][j] = num;  // 숫자 넣기

        // 다음 빈 칸으로 이동
        if (solve(idx + 1)) {
            return true;  // 성공하면 종료
        }

        sdoku[i][j] = 0;  // 실패 시 되돌리기 (백트래킹)
    }

    return false;  // 현재 경로로는 해결 불가
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 스도쿠 입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0) {
                zero.push_back({i, j});  // 빈 칸 저장
            }
        }
    }

    // 스도쿠 풀이 시작
    solve(0);

    // 결과 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sdoku[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
