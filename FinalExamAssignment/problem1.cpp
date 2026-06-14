#include <climits>
#include <iostream>
using namespace std;

int main() {
    unsigned int firstNumber;
    unsigned int secondNumber;

    cout << "첫 번째 숫자를 입력하세요: ";
    cin >> firstNumber;

    cout << "두 번째 숫자를 입력하세요: ";
    cin >> secondNumber;
    cout << endl;

    try {
        unsigned long long result =
            static_cast<unsigned long long>(firstNumber) * secondNumber;

        if (result > UINT_MAX)
            throw UINT_MAX;

        cout << firstNumber << " * " << secondNumber << " = " << result << " 입니다." << endl;
    } catch (unsigned int max) {
        cout << "결과값이 unsigned int의 최대값을 벗어납니다." << endl;
    }

    return 0;
}
