#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 두 벡터의 내적(dot product)을 계산하는 함수
int calculateDotProduct(const vector<int>& a, const vector<int>& b) {
    int result = 0;

    // 두 벡터의 같은 인덱스 원소들을 곱해서 누적 합산
    for (size_t i = 0; i < a.size(); i++)
        result += a[i] * b[i];
    return result;
}

int main() {
    vector<int> a = { 1,2,3,4 };
    vector<int> b = { -3,-1,0,2 };

    auto result = calculateDotProduct(a,b);

    cout << result << endl;
}