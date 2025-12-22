#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ArrSort(vector<int> num_list) {
    vector<int> result;

    // 입력 벡터를 오름차순으로 정렬 
    sort(num_list.begin(), num_list.end());

    // 정렬된 벡터의 처음 5개 원소를 result에 추가
    for (int i = 0; i < 5; i++)
        result.push_back(num_list[i]);  // 인덱스 0~4까지 복사

    return result;
}

int main() {

    vector<int> num_list = { 12,4,15,46,38,14,1 };

    auto result = ArrSort(num_list);

    for (auto p : result)
        cout << p << " ";
}