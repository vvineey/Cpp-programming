#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay(int amount) = 0;

    virtual ~Payment() {
    }
};

class CardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "[카드 결제]" << endl;
        cout << amount << "원을 카드로 결제합니다." << endl;
    }
};

class CashPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "[현금 결제]" << endl;
        cout << amount << "원을 현금으로 결제합니다." << endl;
    }
};

class MobilePayment : public Payment {
public:
    void pay(int amount) override {
        cout << "[모바일 결제]" << endl;
        cout << amount << "원을 모바일 간편 결제로 결제합니다." << endl;
    }
};

int main() {
    int paymentMethod;
    int amount;

    while (true) {
        cout << "결제 방식을 선택하세요 {1.카드, 2.현금, 3.모바일, 0.종료}: ";
        cin >> paymentMethod;

        if (paymentMethod == 0) {
            cout << endl;
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        Payment* payment = nullptr;

        switch (paymentMethod) {
            case 1:
                payment = new CardPayment();
                break;
            case 2:
                payment = new CashPayment();
                break;
            case 3:
                payment = new MobilePayment();
                break;
            default:
                cout << "잘못된 결제 방식입니다." << endl;
                continue;
        }

        cout << "결제 금액 입력: ";
        cin >> amount;
        cout << endl;

        try {
            if (amount <= 0)
                throw amount;

            payment->pay(amount);
        } catch (int) {
            cout << "결제 오류: 결제 금액은 0보다 커야 합니다." << endl;
        }

        delete payment;
        cout << endl;
    }

    return 0;
}
