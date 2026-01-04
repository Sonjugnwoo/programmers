#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 절댓값 배열과 부호 배열을 받아 실제 값들의 합계를 계산하는 함수
int countPrimeTripletSums(vector<int> nums) {
    vector<int> add_nums;

    // i,j,k 조합의 합 계산
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum_num = nums[i] + nums[j] + nums[k];
                add_nums.push_back(sum_num);
            }
        }
    }


    int count = 0;
    bool flag = false;
    for (auto num : add_nums) {
        if (num <= 1) continue;         // 1 이하는 소수 아님
        flag = true;                    // 소수라고 가정
        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                flag = false;     // 합성수 발견
                break;
            }
        }
        if (flag)   count++;      // 소수면 카운트 증가
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,7,6,4 };

    auto result = countPrimeTripletSums(nums);

    cout << result << endl;
}