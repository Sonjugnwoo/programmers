#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	 // reverse() 함수 사용을 위한 헤더

using namespace std;

// 문자열의 특정 구간들을 순차적으로 뒤집는 함수
string Reverse(string my_string, vector<vector<int>> queries) {
	string str = my_string;	  // 원본 문자열을 복사
	
	// queries의 모든 행을 순회하며 각 구간을 뒤집음
	for (int i = 0; i < queries.size(); i++) {
		int curr = queries[i].size()-1;
		reverse(str.begin() + queries[i][0], str.begin() + queries[i][curr]+1);	// +1을 하는 이유: reverse()는 끝 반복자를 포함하지 않음
		//cout << str << endl; 디버깅  
	}

	return str;
}


int main() {
	string my_string = { "rermgorpsam" };
	vector<vector<int>> queries = { {2,3},{0,7},{5,9},{6,10 } };

	string str = Reverse(my_string, queries);

	cout << str << endl;
}