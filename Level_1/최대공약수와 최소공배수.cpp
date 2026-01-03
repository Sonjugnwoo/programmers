#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 두 정수 n, m의 최대공약수(GCD)를 구하는 함수
int Gcd(int n, int m) {
    int a = max(n, m); // 더 큰 값을 a에 저장
    int b = min(n, m); // 더 작은 값을 b에 저장

    // 유클리드 호제법으로 최대공약수 계산
    while (b != 0) {      // b가 0이 될 때까지 반복
        int temp = a % b; // a를 b로 나눈 나머지를 temp에 저장
        a = b;            // a에 b를 대입
        b = temp;         // b에 나머지(temp)를 대입
    }

    return a; // a가 최대공약수
}

// n과 m의 최대공약수(GCD)와 최소공배수(LCM)를 구해 벡터로 반환하는 함수
vector<int> GetGcdLcm(int n, int m) {
    vector<int> result; // GCD와 LCM을 담을 벡터

    int gcd = Gcd(n, m);   // n과 m의 최대공약수 계산
    result.push_back(gcd); // 벡터에 GCD 추가

    // 최소공배수(LCM) = (n * m) / gcd
    result.push_back(n / gcd * m); // 벡터에 LCM 추가

    return result; // [GCD, LCM]이 들어 있는 벡터 반환
}

int main() {
    int n = 49;
    int m = 539;

    auto result = GetGcdLcm(n, m);
    
    for (auto p : result)
        cout << p << " ";

    cout << endl;
}