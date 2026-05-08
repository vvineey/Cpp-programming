#include <iostream>
using namespace std;

int main() {
    int start, end;
    int count = 0;

    do {
        cout << "시작 단 입력: ";
        cin >> start;

        cout << "끝 단 입력: ";
        cin >> end;

        if (start > end || start < 2 || end > 9)
            cout << "잘못된 입력입니다." << endl;
    } while (start > end || start < 2 || end > 9);

    for (int dan = start; dan <= end; dan++) {
        cout << "[" << dan << "단] (홀수 결과만, 50 초과 시 중단)" << endl;

        for (int i = 1; i <= 9; i++) {
            int result = dan * i;

            if (result > 50) {
                cout << "-> " << dan << "단 중단 (50 초과)" << endl;
                break;
            }

            if (result % 2 == 0)
                continue;

            cout << dan << " x " << i << " = " << result << endl;
            count++;
        }
    }

    cout << "출력된 곱셈 결과 총 개수: " << count << endl;

    return 0;
}
