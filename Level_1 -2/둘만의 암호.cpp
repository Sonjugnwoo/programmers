#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string caesarCipherWithSkip(string s, string skip, int index) {
    string answer = "";

    // 각 문자마다 index칸 이동 (skip 건너뛰기)
    for (auto ch : s) {
        int cnt = 0;  // 이동한 칸 수

        // index번만큼 이동하면서 skip 체크
        for (int i = 0; i < index; i++) {
            // 알파벳 순환: z → a
            if (ch == 'z') ch = 'a';
            else ch++;

            // skip에 있으면 이동 취소하고 재시도
            if (skip.find(ch) != string::npos) {
                i--;  // 카운터 되돌리기 (실제 이동 안한 것처럼)
            }
        }
        answer += ch;
    }

    return answer;
}


int main() {

    int index = 6;
    string s = "zzzzzz";
    string skip = "abcdefghijklmnopqrstuvwxy";

    auto result = caesarCipherWithSkip(s,skip,index);

    cout << result << endl;
}