#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>  RemoveAD(string str_arr) {
	vector<string> result;  // "ad"가 없는 문자열을 저장할 새 벡터
	
}

int main() {

	string str_arr = "i love you";


	auto result = RemoveAD(str_arr);

	for (auto p : result)
		cout << p << " ";
}