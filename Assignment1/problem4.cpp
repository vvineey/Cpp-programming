#include <iostream>
using namespace std;

int main() {
    int start, choice, value;

    while (true) {
        cout << "시작 값 입력: ";
        cin >> start;

        cout << "===== 메뉴 =====" << endl;
        cout << "1. 덧셈" << endl;
        cout << "2. 뺄셈" << endl;
        cout << "3. 곱셈" << endl;
        cout << "4. 나눗셈" << endl;
        cout << "5. 종료" << endl;

        cout << "메뉴 선택: ";
        cin >> choice;

        if (choice == 5) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        cout << "계산할 값 입력: ";
        cin >> value;

        try {
            switch (choice) {
                case 1:
                    cout << "결과: " << start + value << endl;
                    break;
                case 2:
                    cout << "결과: " << start - value << endl;
                    break;
                case 3:
                    cout << "결과: " << start * value << endl;
                    break;
                case 4:
                    if (value == 0)
                        throw "0으로 나눌 수 없습니다.";
                    cout << "결과: " << start / value << endl;
                    break;
                default:
                    cout << "잘못된 선택입니다." << endl;
            }
        } catch (const char* msg) {
            cout << "예외 발생: " << msg << endl;
        }
    }

    return 0;
}
