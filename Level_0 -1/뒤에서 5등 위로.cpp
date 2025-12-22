#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 가장 작은 5개 숫자를 제외한 나머지 숫자들을 오름차순으로 반환하는 함수
vector<int> ArrSort(vector<int> num_list) {
    vector<int> result; 

    // 입력 벡터를 오름차순으로 정렬
    sort(num_list.begin(), num_list.end());

    // 인덱스 5부터 (가장 작은 5개 제외) 끝까지 result에 추가
    for (int i = 5; i < num_list.size(); i++)
        result.push_back(num_list[i]);  // 5번째 인덱스부터 모두 복사

    return result;  
}

int main() {

    vector<int> num_list = { 12, 4, 15, 46, 38, 1, 14, 56, 32, 10 };

    auto result = ArrSort(num_list);

    for (auto p : result)
        cout << p << " ";
}