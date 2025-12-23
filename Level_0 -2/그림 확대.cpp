#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 그림 확대: 각 픽셀을 가로k배, 세로k배 반복
vector<string> EnlargePicture(vector<string> picture, int k) {
    vector<string> result;
    string temp = "";

    // 1. 각 원본 줄(picture[i]) 처리
    for (auto p : picture) {
        // 2. 가로 확대: 각 문자 k번 반복
        for (auto ch : p) {
            for (int i = 0; i < k; i++)
                temp += ch;   // '.' → '....', 'x' → 'xxxx'
        }
        // 3. 세로 확대: 확대된 줄을 k번 추가
        for (int i = 0; i < k; i++)
            result.push_back(temp);
        temp.clear();  // 다음 줄 준비
    }
    return result;
}

int main() {
    vector<string> picture = { ".xx...xx.", "x..x.x..x", "x...x...x", ".x.....x.", "..x...x..", "...x.x...", "....x...." };
    int k = 2;

    auto result = EnlargePicture(picture, k);

    for (auto p : result)
        cout << p << endl;
    cout << endl;
}