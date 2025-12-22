#include <iostream>

using namespace std;

// double 값을 int로 변환하는 함수 (소수점 버림)
int Integer(double flo) {
    return (int)flo;
}

int main() {
    double flo = 1.42;

    auto result = Integer(flo);

    cout << result << endl;
}