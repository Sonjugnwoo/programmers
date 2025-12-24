#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));    // n x n 0 배열 생성

    int num = 1;
    // ( 0, 0 ) 시작
    int col = 0;
    int row = 0; 

    for (int i = 0; i < n; i++) {
        // 1. 오른쪽
        while (row < n - i)
            result[col][row++] = num++;
        row--,col++;  // 방향 전환 준비
        // 2 . 아래
        while (col < n - i)
            result[col++][row] = num++;
        col--,row--;
        // 3. 왼쪽
        while (row >= 0 + i)
            result[col][row--] = num++;
        col--,row++;
        // 4. 위
        while (col > 0 + i)
            result[col--][row] = num++;
        col++,row++; // 다음 층 
    }

    return result;
}



int main() {
    int n = 4;

    auto result = solution(n);

    for (auto p : result)
        for (auto r : p)
            cout << r << " ";
    cout << endl;
    cout << endl;

}