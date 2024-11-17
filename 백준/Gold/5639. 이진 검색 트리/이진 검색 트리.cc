#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

void postOrder(int start, int end) {
    if (start > end) { // 구간이 비어 있으면 종료
        return;
    }
    if (start == end) { // 리프 노드인 경우 바로 출력
        cout << tree[start] << '\n';
        return;
    }

    int root = tree[start];
    int idx = start + 1;

    // 루트보다 큰 값을 찾음 (오른쪽 서브트리 시작점)
    while (idx <= end && tree[idx] <= root) {
        idx++;
    }

    // 왼쪽 서브트리
    postOrder(start + 1, idx - 1);
    // 오른쪽 서브트리
    postOrder(idx, end);
    // 루트 출력
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    while (cin >> num) {
        tree.push_back(num); // 입력 데이터를 벡터에 저장
    }

    postOrder(0, tree.size() - 1); // 전체 범위로 호출
    return 0;
}