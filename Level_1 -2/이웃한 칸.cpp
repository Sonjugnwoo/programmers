#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    // 1. 기준 칸의 색상 저장
    string color = board[h][w];

    // 2. 4방향 이동량 배열 (상 우 좌 하)
    int dh[] = { -1, 0, 0, 1 };
    int dw[] = { 0, 1,-1, 0 };

    // 3. 4방향 탐색
    for (int d = 0; d < 4; d++) {
        int nh = h + dh[d];  // 새 행 위치
        int nw = w + dw[d];  // 새 열 위치

        // 4. 범위 체크 (0 ≤ nh < 행수, 0 ≤ nw < 열수)
        if (nh >= 0 && nh < board.size() &&
            nw >= 0 && nw < board[0].size()) {

            // 5. 같은 색상인 경우 카운트 증가
            if (board[nh][nw] == color)
                answer++;
        }
    }
    return answer;
}

int main() {

    vector<vector<string>> board = { 
        {"blue", "red", "orange", "red"},
        {"red", "red", "blue", "orange"},
        {"blue", "orange", "red", "red"},
        {"orange", "orange", "red", "blue"}
    };

    int h = 1;
    int w = 1;

    auto result = solution(board,h,w);

    cout << result << endl;
}