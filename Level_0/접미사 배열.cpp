#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	// sort 함수 사용
using namespace std;

// 문자열의 모든 접미사(suffix)를 생성하고 사전순으로 정렬하는 함수
vector<string> SuffixArr(const string &my_string) {
	vector<string> result;

	// 각 인덱스부터 끝까지의 부분 문자열(접미사) 생성
	for (int i = 0; i < my_string.length(); i++)
		result.push_back( my_string.substr(i));		// substr(i): i번 인덱스부터 문자열 끝까지 추출
	
	// 모든 접미사를 사전순(알파벳순)으로 정렬
	sort(result.begin(), result.end());
	return result;
;}

int main() {
	string my_string = { "banana" };

	vector<string> str = SuffixArr(my_string);

	for (auto p : str)
		cout << p << endl;
}