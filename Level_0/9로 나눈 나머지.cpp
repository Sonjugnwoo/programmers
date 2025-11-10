// 수학 원리: 어떤 수를 9로 나눈 나머지는 각 자릿수의 합을 9로 나눈 나머지와 같다
// (10 ≡ 1 (mod 9) 이므로)
#include <iostream>
#include <string>
#include <vector>

// 벡터에 저장된 문자열 숫자를 9로 나눈 나머지를 계산하는 함수
int Division(std::vector<std::string> &number) {
	int result = 0; 
    // 벡터의 모든 문자열을 순회 (일반적으로 첫 번째 요소만 사용)
    for (std::string str : number) {
        // 문자열의 각 문자(자릿수)를 순회
        for (char c : str)
            // c - '0': ASCII 문자를 실제 숫자로 변환 
            // (result + digit) % 9: 덧셈의 모듈러 분배 법칙 적용
            // 중간 계산마다 % 9를 취해 오버플로우 방지
            result = (result + (c - '0')) % 9;
    }
    // 최종 계산된 나머지를 반환
    return result;
}


int main() {
	std::vector<std::string> number = {"123"};
	
	std::cout << Division(number) << std::endl;
}