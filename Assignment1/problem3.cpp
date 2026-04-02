#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "정수 5개 입력: ";

    for (int i = 0; i < 5; i++) {
        cin >> num;
        sum += num;
    }

    double avg = (double)sum / 5;

    cout << "총합: " << sum << endl;
    cout << "평균: " << avg << endl;

    return 0;
}

