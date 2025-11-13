#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 완료되지 않은 할 일 목록만 필터링하여 반환 함수 
vector<string> TodoList(vector<string> todo_list, vector<bool> finished) {
	vector<string> result;

	// finished 벡터의 모든 요소를 순회하며 인덱스로 접근
	for (int i = 0; i < finished.size(); i++) {
		// 완료되지 않은 할 일인 경우 (!는 not 연산자)
		if (!finished[i])
			// 해당 인덱스의 할 일을 결과 벡터에 추가
			result.push_back(todo_list[i]);
	}

	return result;
}


int main() {
	vector<string> todo_list = { "problemsolving", "practiceguitar", "swim", "studygraph" };
	vector<bool> finished = { true,false,true,false };

	auto result = TodoList(todo_list, finished);
	

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}