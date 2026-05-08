#include <iostream>
#include <bitset>
using namespace std;

int main() {
    const int READ = 1;
    const int WRITE = 2;
    const int EXECUTE = 4;
    const int DELETE = 8;

    int permission = 0;
    int input;

    cout << "권한 설정 (1:읽기, 2:쓰기, 4:실행, 8:삭제, 0:설정 완료)" << endl;

    while (true) {
        cout << "권한 입력: ";
        cin >> input;

        if (input == 0)
            break;

        if (input == READ || input == WRITE || input == EXECUTE || input == DELETE)
            permission |= input;
        else
            cout << "올바르지 않은 권한입니다." << endl;
    }

    bool hasRead = static_cast<bool>(permission & READ);
    bool hasWrite = static_cast<bool>(permission & WRITE);
    bool hasExecute = static_cast<bool>(permission & EXECUTE);
    bool hasDelete = static_cast<bool>(permission & DELETE);

    cout << boolalpha;
    cout << "[권한 판별 결과]" << endl;
    cout << "읽기 권한: " << hasRead << endl;
    cout << "쓰기 권한: " << hasWrite << endl;
    cout << "실행 권한: " << hasExecute << endl;
    cout << "삭제 권한: " << hasDelete << endl;
    cout << "권한 값: " << permission << " (" << bitset<8>(permission) << ")" << endl;

    return 0;
}
