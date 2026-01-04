#include <iostream>

using namespace std;

void printRectangleStarPattern(int width, int height) {
    for (int row = 0; row < height; row++) {      // height개의 행 생성
        for (int col = 0; col < width; col++) {   // 각 행에 width개의 별
            cout << '*';                          // 별 한 개 출력
        }
        cout << endl;                             // 행 완료 후 개행
    }
}

int main(void) {
    int width = 5; 
    int height = 3;  

    printRectangleStarPattern(width, height);
}