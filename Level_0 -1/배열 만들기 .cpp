#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> AddArr(vector<int> arr) {
    vector<int> result;
    // 입력 배열을 처음부터 끝까지 순회
    for (int i = 0; i < arr.size(); i++) {
        // 만약 결과 벡터가 비어있다면, 현재 원소를 바로 추가한다
        if (result.empty())
            result.push_back(arr[i]);
        // 그렇지 않고, 마지막에 추가된 원소가 지금 원소와 같다면
        // 스택 동작처럼 마지막 원소를 제거한다(pop_back)
        else if (result.back() == arr[i])
            result.pop_back();
        // 마지막 원소와 현재 원소가 다르면 현재 원소를 추가
        else
            result.push_back(arr[i]);
    }

    // 최종 결과 벡터가 비어있으면 -1을 추가 (예외 처리)
    if (result.empty())
        result.push_back(-1);
    return result;
}
int main() {

    vector<int> arr = { 0, 1, 1, 1, 0 };
    auto result = AddArr(arr);

    for (auto p : result)
        cout << p << " ";
}