#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int getMaxPokemonKinds(vector<int> nums){
    int len = nums.size() / 2;  // 선택 가능한 최대 폰켓몬 수: 전체 길이의 절반

    // 벡터 정렬: 같은 종류의 폰켓몬을 인접하게 모은다.
    // 이는 나중에 unique()로 중복 제거할 때 필수 과정.
    sort(nums.begin(), nums.end());

    // erase–unique 패턴으로 중복 제거
    nums.erase(unique(nums.begin(), nums.end()), nums.end());


    return nums.size() > len ? len : nums.size();
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6 };

    auto result = getMaxPokemonKinds(nums);

    cout << result << endl;
}
