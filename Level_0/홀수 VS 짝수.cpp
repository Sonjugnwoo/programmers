#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 짝수 인덱스 합과 홀수 인덱스 합 중 더 큰 값을 반환
int OddEvenNumber(vector<int> num_list) {
	int odd = 0, even = 0; 
	
	// 벡터의 모든 요소를 순회
	for (int i = 0; i < num_list.size(); i++) {
		if (i % 2 == 0)
			// 짝수 인덱스
			even += num_list[i];
		else
			// 홀수 인덱스 
			odd += num_list[i];
	}
	
	return max(odd, even);
}

int main() {
	vector<int> num_list = { 4,2,6,1,7,6 };
	auto result = OddEvenNumber(num_list);

		cout << result << endl;

}