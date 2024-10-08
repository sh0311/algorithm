#include <iostream>
#include <vector>

using namespace std;

// 4가지 방향만 확인 (가로, 세로, 대각선 두 방향)
int dx[] = {1, 1, 1, 0};  // 가로, 대각선, 세로
int dy[] = {0, 1, -1, 1}; // 가로, 대각선, 세로

bool isFive(vector<vector<int>>& omok, int x, int y, int dirX, int dirY, int target) {
    int count = 1;

    // 현재 돌 기준으로 4번 더 진행해서 5개의 돌이 연속되었는지 확인
    for (int i = 1; i < 5; i++) {
        int newX = x + dirX * i;
        int newY = y + dirY * i;

        if (newX < 0 || newX >= 19 || newY < 0 || newY >= 19 || omok[newX][newY] != target)
            break;
        count++;
    }

    // 5개가 연속된 상태에서 6개 이상의 돌이 있는지 확인
    if (count == 5) {
        // 이전 돌이 같은 색이면 무효 (6목 방지)
        int prevX = x - dirX;
        int prevY = y - dirY;
        if (prevX >= 0 && prevX < 19 && prevY >= 0 && prevY < 19 && omok[prevX][prevY] == target)
            return false;

        // 이후 돌이 같은 색이면 무효 (6목 방지)
        int nextX = x + dirX * 5;
        int nextY = y + dirY * 5;
        if (nextX >= 0 && nextX < 19 && nextY >= 0 && nextY < 19 && omok[nextX][nextY] == target)
            return false;

        return true;  // 정확히 5개의 돌만 연속된 경우
    }
    return false;
}

pair<int, int> solve(vector<vector<int>>& omok) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (omok[i][j] != 0) {  // 바둑알이 있을 때만 체크
                int target = omok[i][j];
                for (int k = 0; k < 4; k++) {
                    if (isFive(omok, i, j, dx[k], dy[k], target)) {
                        cout << target << '\n';  // 승리한 돌 출력 (1 또는 2)
                        // 좌표 반환 (가장 왼쪽/위쪽 돌 기준으로 반환)
                        if (dx[k] == 1 && dy[k] == -1) {
                            return make_pair(i + 4, j - 4);
                        }
                        return make_pair(i, j);
                    }

                }
            }
        }
    }
    return make_pair(-1, -1);  // 승부가 결정되지 않음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> omok(19, vector<int>(19));

    // 바둑판 상태 입력
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> omok[i][j];
        }
    }

    pair<int, int> res = solve(omok);
    if (res.first == -1 && res.second == -1) {
        cout << 0;  // 승부가 나지 않음
    } else {
        cout << res.first + 1 << " " << res.second + 1;  // 1-based 좌표 출력
    }

    return 0;
}
