#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Beverage {
public:
    virtual string getName() = 0;
    virtual int getPrice() = 0;
    virtual void make() = 0;

    virtual ~Beverage() {
    }
};

class Americano : public Beverage {
public:
    string getName() override {
        return "아메리카노";
    }

    int getPrice() override {
        return 4000;
    }

    void make() override {
        cout << "[아메리카노 제조]원두를 추출하고 물을 추가합니다." << endl;
    }
};

class Latte : public Beverage {
public:
    string getName() override {
        return "라떼";
    }

    int getPrice() override {
        return 5000;
    }

    void make() override {
        cout << "[라떼 제조]원두를 추출하고 우유를 추가합니다." << endl;
    }
};

class Ade : public Beverage {
public:
    string getName() override {
        return "에이드";
    }

    int getPrice() override {
        return 4000;
    }

    void make() override {
        cout << "[에이드 제조]탄산수와 시럽을 섞습니다." << endl;
    }
};

class Payment {
public:
    virtual void pay(int amount) = 0;

    virtual ~Payment() {
    }
};

class CardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "[카드 결제]" << amount << "원을 카드로 결제합니다." << endl;
    }
};

class CashPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "[현금 결제]" << amount << "원을 현금으로 결제합니다." << endl;
    }
};

class CafeOrder {
private:
    static int totalOrderCount;

public:
    static void completeOrder() {
        totalOrderCount++;
    }

    static int getTotalOrderCount() {
        return totalOrderCount;
    }
};

int CafeOrder::totalOrderCount = 0;

int main() {
    Americano americano;
    Latte latte;
    Ade ade;
    CardPayment cardPayment;
    CashPayment cashPayment;

    int beverageNumber;

    while (true) {
        cout << "===== 카페 주문 메뉴 =====" << endl;
        cout << "1. 아메리카노" << endl;
        cout << "2. 라떼" << endl;
        cout << "3. 에이드" << endl;
        cout << "0. 종료" << endl;
        cout << "음료 선택: ";
        cin >> beverageNumber;

        if (beverageNumber == 0) {
            cout << "총 주문 건수: " << CafeOrder::getTotalOrderCount() << endl;
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        Beverage* beverage = nullptr;

        switch (beverageNumber) {
            case 1:
                beverage = &americano;
                break;
            case 2:
                beverage = &latte;
                break;
            case 3:
                beverage = &ade;
                break;
            default:
                cout << "잘못된 음료 번호입니다." << endl;
                continue;
        }

        try {
            int quantity;
            cout << "수량 입력: ";
            cin >> quantity;

            if (quantity <= 0)
                throw quantity;

            int paymentMethod;
            cout << "결제 방식 선택 {1.카드, 2.현금}: ";
            cin >> paymentMethod;

            Payment* payment = nullptr;

            switch (paymentMethod) {
                case 1:
                    payment = &cardPayment;
                    break;
                case 2:
                    payment = &cashPayment;
                    break;
                default:
                    cout << "잘못된 결제 방식입니다." << endl;
                    continue;
            }

            int totalAmount = beverage->getPrice() * quantity;

            if (totalAmount > 100000)
                throw static_cast<float>(totalAmount - 100000);

            beverage->make();
            payment->pay(totalAmount);

            CafeOrder::completeOrder();

            cout << "주문 완료: " << beverage->getName() << " " << quantity << "잔" << endl;
            cout << "현재 총 주문 건수: " << CafeOrder::getTotalOrderCount() << endl;
        } catch (int quantity) {
            cout << "수량 오류: " << quantity << "은(는) 유효하지 않습니다." << endl;
        } catch (float excessAmount) {
            cout << "결제 오류: 주문 가능 금액을 초과했습니다. 초과 금액: ";
            cout << fixed << setprecision(0) << excessAmount << "원" << endl;
        } catch (...) {
            cout << "알 수 없는 오류가 발생했습니다." << endl;
        }
    }

    return 0;
}
