#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
private:
    string name;
    int price;

public:
    MenuItem(string itemName, int itemPrice) {
        name = itemName;
        price = itemPrice;
    }

    string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }

    virtual string getType() {
        return "메뉴";
    }

    virtual void printInfo(int index) {
        cout << index << ". [" << getType() << "] " << name << " - " << price << "원" << endl;
    }

    virtual ~MenuItem() {
    }
};

class Drink : public MenuItem {
public:
    Drink(string name, int price) : MenuItem(name, price) {
    }

    string getType() override {
        return "음료";
    }
};

class Dessert : public MenuItem {
public:
    Dessert(string name, int price) : MenuItem(name, price) {
    }

    string getType() override {
        return "디저트";
    }
};

class CafeManager {
private:
    vector<MenuItem*> menus;
    vector<string> orderHistory;
    int balance;

public:
    CafeManager(int money) {
        balance = money;
    }

    void addMenu() {
        int type, price;
        string name;

        cout << "메뉴 종류 선택 (1:음료, 2:디저트): ";
        cin >> type;

        cout << "메뉴 이름: ";
        cin >> name;

        cout << "가격: ";
        cin >> price;

        if (type == 1)
            menus.push_back(new Drink(name, price));
        else if (type == 2)
            menus.push_back(new Dessert(name, price));
        else
            cout << "잘못된 메뉴 종류입니다." << endl;

        if (type == 1 || type == 2)
            cout << "메뉴 등록 완료" << endl;
    }

    void showMenus() {
        cout << "===== 메뉴 목록 =====" << endl;

        if (menus.empty()) {
            cout << "등록된 메뉴가 없습니다." << endl;
            return;
        }

        for (int i = 0; i < static_cast<int>(menus.size()); i++)
            menus[i]->printInfo(i + 1);
    }

    void orderMenu() {
        int number, quantity;

        showMenus();

        if (menus.empty())
            return;

        cout << "주문할 메뉴 번호: ";
        cin >> number;

        if (number < 1 || number > static_cast<int>(menus.size())) {
            cout << "잘못된 메뉴 번호입니다." << endl;
            return;
        }

        cout << "주문 수량: ";
        cin >> quantity;

        if (quantity <= 0)
            throw quantity;

        MenuItem* selected = menus[number - 1];
        int total = selected->getPrice() * quantity;

        if (total > balance)
            throw static_cast<float>(total - balance);

        balance -= total;

        string record = selected->getName() + " " + to_string(quantity) + "개 - " + to_string(total) + "원";
        orderHistory.push_back(record);

        double unitPrice = static_cast<double>(total) / quantity;

        cout << "주문 완료: " << record << endl;
        cout << "개당 가격: " << fixed << setprecision(2) << unitPrice << "원" << endl;
        cout << "남은 잔액: " << balance << "원" << endl;
    }

    void showOrders() {
        cout << "===== 주문 내역 =====" << endl;

        if (orderHistory.empty()) {
            cout << "주문 내역이 없습니다." << endl;
            return;
        }

        for (int i = 0; i < static_cast<int>(orderHistory.size()); i++)
            cout << i + 1 << ". " << orderHistory[i] << endl;

        cout << "현재 잔액: " << balance << "원" << endl;
    }

    void deleteMenus() {
        for (int i = 0; i < static_cast<int>(menus.size()); i++)
            delete menus[i];

        menus.clear();
    }
};

int main() {
    int balance;
    int choice;

    cout << "초기 잔액 입력: ";
    cin >> balance;

    CafeManager cafe(balance);

    while (true) {
        cout << "===== 카페 주문 관리 =====" << endl;
        cout << "1. 메뉴 등록" << endl;
        cout << "2. 메뉴 목록 조회" << endl;
        cout << "3. 주문" << endl;
        cout << "4. 주문 내역 조회" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴 선택: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cafe.addMenu();
                    break;
                case 2:
                    cafe.showMenus();
                    break;
                case 3:
                    cafe.orderMenu();
                    break;
                case 4:
                    cafe.showOrders();
                    break;
                case 5:
                    cafe.deleteMenus();
                    cout << "프로그램을 종료합니다." << endl;
                    return 0;
                default:
                    cout << "잘못된 선택입니다." << endl;
            }
        } catch (int count) {
            cout << "수량 오류: " << count << "은(는) 유효하지 않습니다." << endl;
        } catch (float shortage) {
            cout << "결제 오류: " << fixed << setprecision(0) << shortage << "원이 부족합니다." << endl;
        } catch (...) {
            cout << "알 수 없는 오류가 발생했습니다." << endl;
        }
    }

    return 0;
}
