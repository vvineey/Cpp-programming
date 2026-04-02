#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "정수 입력: ";
    cin >> num;

    if (num > 0)
        cout << "입력한 값은 양수입니다." << endl;
    else if (num < 0)
        cout << "입력한 값은 음수입니다." << endl;
    else
        cout << "입력한 값은 0입니다." << endl;

    if (num % 2 == 0)
        cout << "입력한 값은 짝수입니다." << endl;
    else
        cout << "입력한 값은 홀수입니다." << endl;

    return 0;
}
