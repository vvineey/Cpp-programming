#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string owner;
    int balance;

public:
    Account(string name) {
        owner = name;
        balance = 0;
    }

    void deposit(int money) {
        if (money <= 0)
            throw money;

        balance += money;
        cout << "입금 완료 (잔액: " << balance << "원)" << endl;
    }

    void withdraw(int money) {
        if (money > balance)
            throw static_cast<float>(money - balance);

        balance -= money;
        cout << "출금 완료 (잔액: " << balance << "원)" << endl;
    }

    int getBalance() {
        return balance;
    }

    void printBalance() {
        cout << "[잔액 조회] " << owner << "님의 잔액: " << balance << "원" << endl;
    }

    void printInfo() {
        cout << "[최종 계좌 정보]" << endl;
        cout << "소유자: " << owner << endl;
        cout << "잔액: " << balance << "원" << endl;
    }
};

int main() {
    string name;
    int choice, money;

    cout << "계좌 소유자 이름 입력: ";
    cin >> name;

    Account account(name);

    while (true) {
        cout << "===== 계좌 메뉴 =====" << endl;
        cout << "1. 입금" << endl;
        cout << "2. 출금" << endl;
        cout << "3. 잔액 조회" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴 선택: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "입금 금액: ";
                    cin >> money;
                    account.deposit(money);
                    break;
                case 2:
                    cout << "출금 금액: ";
                    cin >> money;
                    account.withdraw(money);
                    break;
                case 3:
                    account.printBalance();
                    break;
                case 4:
                    account.printInfo();
                    cout << "프로그램을 종료합니다." << endl;
                    return 0;
                default:
                    cout << "잘못된 선택입니다." << endl;
            }
        } catch (int) {
            cout << "입금 오류: 0보다 큰 금액을 입력하세요." << endl;
        } catch (float) {
            cout << "출금 오류: 잔액이 부족합니다. (현재 잔액: " << account.getBalance() << "원)" << endl;
        } catch (...) {
            cout << "알 수 없는 오류가 발생했습니다." << endl;
        }
    }

    return 0;
}
