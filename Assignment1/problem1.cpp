#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "첫 번째 정수 입력: ";
    cin >> num1;

    cout << "두 번째 정수 입력: ";
    cin >> num2;

    cout << "합: " << num1 + num2 << endl;
    cout << "차: " << num1 - num2 << endl;
    cout << "곱: " << num1 * num2 << endl;

    if (num2 != 0) {
        cout << "몫: " << num1 / num2 << endl;
        cout << "나머지: " << num1 % num2 << endl;
    } else {
        cout << "0으로 나눌 수 없습니다." << endl;
    }

    return 0;
}