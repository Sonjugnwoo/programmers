#include <iostream>
#include <string>
#include <vector>

using namespace std;

int parcelPickup(int n, int w, int num) {
    int answer = 0;
    // 1. 보드 높이 계산
    int h = (n + w - 1) / w; 

    // 2. h x w 크기 보드 초기화 (모든 칸 0)
    vector<vector<int>> board(h, vector<int>(w, 0));
   
    // 3. 지그재그 패턴으로 1~n 번호 채우기
    int idx = 1;
    for (int i = 0; i <h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                board[i][j] = idx++;
                if (idx > n)
                    break;
            }
        }
        else {
            for (int j =w-1; j>=0; j--) {
                board[i][j] = idx++;
                if (idx > n)
                    break;
            }
        }
    }
    // 4. num 위치 찾기 (첫 번째 발견 위치)
    int target_row = -1, target_col = -1;   
    for (int i = 0; i < h; i++) {
        bool flag = false;
        for (int j = 0; j < w; j++) {
            if (board[i][j] == num) {
                target_row = i;
                target_col = j;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    // 5. num 위치 열에서 아래로 연속 채워진 칸 수 계산
    for (int i = target_row; i < h; i++) {
        if (board[i][target_col] == 0)  // 0 만나면 중단
            break;
        answer++;
    }


    return answer;
}


int main() {
    int n = 6;
    int w = 5;
    int num = 4;

    auto result = parcelPickup(n, w, num);

    cout << result << endl;
}