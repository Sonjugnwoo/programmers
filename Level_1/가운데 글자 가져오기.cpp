#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getMiddleCharacter(string str) {

    int mid = str.size() / 2;       // 전체 길이의 절반 위치 계산

    if (str.size() % 2 != 0)        // 홀수 길이
        return str.substr(mid, 1);
    else                            // 짝수 길이
        return str.substr(mid - 1, 2);
}

int main() {
    string str = "qwer";

    auto result = getMiddleCharacter(str);

    cout << result << endl;

}