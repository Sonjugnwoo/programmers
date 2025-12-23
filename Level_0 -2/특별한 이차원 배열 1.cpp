#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n x n 단위행렬 생성: 대각선 1, 나머지 0
vector<vector<int>> CreateIdentityMatrix(int n) {
    // n x n 크기의 2차원 벡터를 0으로 초기화
    vector<vector<int>> result(n, vector<int>(n, 0));

    // 모든 행(i)과 열(j)에 대해 순회
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 대각선 요소(i == j)만 1로 설정 (0++ = 1)
            if (i == j) {
                result[i][j]++;
                continue;  // 나머지 열 건너뛰기 (불필요하지만 무해)
            }
            // i != j인 경우: 0 유지 (초기화값)
        }
    }
    return result;
}

int main() {
    int n = 3;

    auto result = CreateIdentityMatrix(n);

    for (auto p : result)
        for (auto r : p)
            cout << r << " ";
     cout << endl;
    cout << endl;

}