#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 결과 행렬 초기화: arr1과 동일한 크기, 모든 원소 0
    vector<vector<int>> result(arr1.size(), vector<int>(arr1[0].size(),0));

    for (int i = 0; i < arr1.size(); i++) {           // 모든 행 순회
        for (int j = 0; j < arr1[i].size(); j++) {    // 각 행의 모든 열 순회
            result[i][j] = arr1[i][j] + arr2[i][j];   // 같은 위치 원소 덧셈
        }
    }
    return result;
}

int main() {
    vector<vector<int>> arr1 = { {1,2} };
    vector<vector<int>> arr2 = { {3,4} };
    auto result = solution(arr1, arr2);

    for (auto col : result) {
        for (auto row : col) {
            cout << row << " ";
        }
        cout << endl;
    }
    cout << endl;

}