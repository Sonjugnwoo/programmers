#include <iostream>
#include <string>

using namespace std;

string createWatermelonString(int n) {
    string result = "";

    // 1부터 n까지 반복
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0)  // 홀수 번째일 때 (1,3,5...)
            result += "수"; // "수" 추가
        else             // 짝수 번째일 때 (2,4,6...)
            result += "박"; // "박" 추가
    }
    return result;
}

int main() {
    int n = 4;

    auto result = createWatermelonString(n);

    cout << result << endl;
}