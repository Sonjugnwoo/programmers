#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2차원 배열이 대칭행렬(대각선을 기준으로 좌우 대칭)인지 확인하는 함수
int checkSymmetry(vector<vector<int>> arr) {

    // 상삼각행렬 부분만 검사 (i < j인 부분만)
    // 대칭행렬 성질: arr[i][j] == arr[j][i] (모든 i,j에 대해)
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            // 대칭 조건 위배 발견 시 즉시 0 반환
            if (arr[i][j] != arr[j][i])
                return 0;

            return 1;
        }
    }
}
int main() {
    vector<vector<int>> arr = { {5, 192, 33},{192, 72, 95},{33, 95, 999} };

    auto result = checkSymmetry(arr);

    cout << result << endl;
}
