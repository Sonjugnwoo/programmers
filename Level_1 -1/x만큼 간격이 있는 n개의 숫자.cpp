#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 등차수열 생성 함수
vector<long long> generateArithmeticSequence(int x, int n) {
    vector<long long> result;

    // 1부터 n까지 반복하며 i*x 계산
    for (int i = 1; i <=n; i++) 
        result.push_back(i * x);     // i번째 항 추가
    
    return result;
}

int main() {

    int x = 2;
    int n = 5;

    auto result = generateArithmeticSequence(x,n);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}