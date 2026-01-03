#include <iostream>
#include <string>
#include <vector>

using namespace std;

string evenOdd(int num) {
    // abs(num): 음수 처리 (ex: -3 → 3)
    return abs(num) % 2 == 1 ? "Odd" : "Even";
}

int main() {
    int num = 3;

    auto result = evenOdd(num);

    cout << result << endl;
}