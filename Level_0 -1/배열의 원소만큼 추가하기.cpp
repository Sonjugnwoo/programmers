#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 배열의 각 원소 값만큼 그 원소를 반복해서 결과 벡터에 추가하는 함수
vector<int> AddArrElem(vector<int> arr) {
    vector<int> result;  
    // 각 원소 arr[i] 값만큼 반복하여 arr[i] 값을 벡터 끝에 삽입
    // vector::insert는 "반복 횟수, 값" 형태로 여러 개 복사하여 삽입 가능
    for (int i = 0; i < arr.size(); i++) {
        // result.end() 위치에 arr[i] 값을 arr[i]번 삽입
        result.insert(result.end(), arr[i], arr[i]);
    }

    return result;
}
int main() {

    vector<int> arr = { 5,1,4 };

    auto result = AddArrElem(arr);

    for (auto p : result)
        cout << p << " ";
}