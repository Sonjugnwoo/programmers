#include <iostream>
#include <string>


using namespace std;
// 문자열에서 패턴(pat)의 마지막 등장 위치를 찾아, 그 위치 이후의 모든 문자를 삭제
string SearchString(string &my_string, string pat) {
	
	// rfind: 문자열 끝에서부터 역방향으로 pat을 검색
	// 반환값: pat이 마지막으로 등장하는 위치의 인덱스 (찾지 못하면 string::npos)
	auto pos = my_string.rfind(pat);

	// string::npos는 문자열을 찾지 못했을 때 반환되는 특수 값
	if (pos != string::npos)
		// pos + pat.size() 위치부터 끝까지 삭제
		// 즉, 찾은 패턴(pat) 바로 다음 위치부터 문자열 끝까지 모두 제거
		my_string.erase(pos + pat.size());

	return my_string;  // 수정된 문자열 반환
}

int main() {
	
	string my_string = "AAAAaaaa";

	string pat = "a";

	auto result = SearchString(my_string, pat);

	cout << result << endl;
}