#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 2차원 벡터를 정사각형 크기로 변환하는 함수
vector<vector<int>> makeSquareMatrix(vector<vector<int>> arr) {
    // 정사각형 한 변의 길이 = 행 수와 열 수 중 큰 값
    int size = max(arr.size(), arr[0].size());

    // size x size 크기의 2D 벡터를 생성하고 모든 원소를 0으로 초기화
    vector<vector<int>> result(size, vector<int>(size, 0));

    // 원본 배열의 유효한 모든 원소를 result의 같은 위치로 복사
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            result[i][j] = arr[i][j];
        } 
    }

    return result;  // 0으로 채워진 정사각형 배열 반환
}

int main() {
    vector<vector<int>> arr = { {572, 22, 37} ,{287, 726, 384},{85, 137, 292},{487, 13, 876} }; // 테스트 케이스 1
    vector<vector<int>> arr_2 = { {57, 192, 534, 2} ,{9, 345, 192, 999} };  // 테스트 케이스 2
    vector<vector<int>> arr_3 = { {57, 192} ,{9, 345} };     // 테스트 케이스 3
    auto result = makeSquareMatrix(arr_3);

    for (auto p : result) {
        for (auto r : p)
            cout << r << " ";
        cout << endl;
    }

    cout << endl;

}