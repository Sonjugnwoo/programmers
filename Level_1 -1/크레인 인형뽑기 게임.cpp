#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
// 크레인 인형뽑기 게임 로직을 구현하는 함수
int craneGame(vector<vector<int>> board, vector<int> moves) {
    int result = 0;
    stack<int> basket;    // 바구니(인형 저장소)

    for (auto m : moves) {   // 크레인 이동 순서대로 처리
        for (int i =0; i < board.size(); i++) {
            if (board[i][m - 1] == 0) // 해당 열이 비었으면 다음 행으로 이동
                continue;
            else {
                // 인형을 뽑아서 바구니에 넣음
                basket.push(board[i][m - 1]);
                board[i][m - 1] = 0; // 뽑힌 자리 비움
                break;               // 한 번 뽑았으면 다음 move로 넘어감          
        }

        // 바구니에 인형이 두 개 이상 있을 때만 비교
        if(basket.size() >=2){
            // 서로 다르면 다시 넣어줌 (순서 유지)
            int a = basket.top();
            basket.pop();
            int b = basket.top();
            basket.pop();

            if (a != b) {
                basket.push(b);
                basket.push(a);
            }
            else
                result += 2;      // 같으면 둘 다 제거되고 점수 +2
        }
    }


    return result;
}


int main() {
    vector<vector<int>> board = { 
        {0,0,0,0,0},{0,0,1,0,3},
        {0,2,5,0,1},{4,2,4,4,2},
        {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };


    auto result = craneGame(board, moves);

    cout << result << endl;

}