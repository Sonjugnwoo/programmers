#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> TransformByK(vector<int> arr, int k) {

    // 범위 기반 for문 + 참조(&p)로 원본 직접 수정
    for (auto& p : arr) {
        if (k % 2 == 1)      // k 홀수
            p *= k;          // 모든 원소에 k 곱하기
        else                 // k 짝수
            p += k;          // 모든 원소에 k 더하기

        return arr;
    }
}
int main() {
    vector<int> arr = { 1, 2, 3, 100, 99, 98 };
    int k = 3;

    auto result = TransformByK(arr, k);

    for (auto p : result)
        cout << p << " ";
    cout << endl;
}