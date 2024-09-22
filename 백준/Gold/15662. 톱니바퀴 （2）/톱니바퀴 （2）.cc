#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 톱니바퀴 회전
void rotate_wheel(vector<int>& wheel, int direction) {
    if (direction == 1) { // 시계 방향 회전
        rotate(wheel.rbegin(), wheel.rbegin() + 1, wheel.rend());
    } else if (direction == -1) { // 반시계 방향 회전
        rotate(wheel.begin(), wheel.begin() + 1, wheel.end());
    }
}

// 모든 톱니바퀴의 회전을 처리
void process_rotation(vector<vector<int>>& wheels, int order, int direction, vector<bool>& visited) {
    int num = wheels.size();
    visited[order] = true;

    // 왼쪽 톱니바퀴가 회전할지 확인
    if (order > 0 && !visited[order - 1] && wheels[order][6] != wheels[order - 1][2]) {
        process_rotation(wheels, order - 1, -direction, visited);
    }

    // 오른쪽 톱니바퀴가 회전할지 확인
    if (order < num - 1 && !visited[order + 1] && wheels[order][2] != wheels[order + 1][6]) {
        process_rotation(wheels, order + 1, -direction, visited);
    }

    // 현재 톱니바퀴 회전
    rotate_wheel(wheels[order], direction);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    // 톱니바퀴 상태 입력 받기
    vector<vector<int>> wheels(T, vector<int>(8));
    for (int i = 0; i < T; i++) {
        string state;
        cin >> state;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = state[j] - '0';  // 상태를 숫자로 변환
        }
    }

    // 회전 횟수 입력 받기
    int K;
    cin >> K;

    while (K--) {
        int order, direction;
        cin >> order >> direction;
        order--;  // 톱니바퀴 번호는 1부터 시작하는데 vector인덱스는 0이므로 변경

        vector<bool> visited(T, false);  // 방문 여부 기록
        process_rotation(wheels, order, direction, visited);
    }
    
    int result = 0;
    for (int i = 0; i < T; i++) {
        if (wheels[i][0] == 1) {
            result++;
        }
    }

    cout << result << '\n';
    return 0;
}
