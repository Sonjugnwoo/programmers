#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int Test(vector<int> rank, vector<bool> attendance) {
	vector<int> attend;

    // 1단계: 참석자 인덱스만 수집 (attendance[i] == true인 i들)
    for (int i = 0; i < rank.size(); i++) {
        if (attendance[i])
            attend.push_back(i);  // i번째 사람이 참석하면 인덱스 저장
    }

    // 2단계: rank 기준 오름차순 정렬 (작은 rank = 높은 순위)
    // 람다: rank[a] < rank[b] → a가 b보다 높은 순위
    sort(attend.begin(), attend.end(), [&](int a, int b) {
        return rank[a] < rank[b];  // rank가 작은(높은 순위) 인덱스부터 정렬
    });

	int sum = (attend[0] * 10000) + (attend[1] * 100) + attend[2];

	return sum;
}


int main() {
	vector<int> rank = { 3,7,2,5,4,6,1 }; // 등수
	vector<bool> attendance = { false, true, true, true, true, false, false }; //참여 가능 여부 

	auto result = Test(rank, attendance);

	cout << result << endl;

}