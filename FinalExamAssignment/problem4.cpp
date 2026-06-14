#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int hp;

public:
    Character(string name, int hp) {
        this->name = name;
        this->hp = hp;
    }

    virtual void attack() = 0;
    virtual void specialAttack() = 0;

    virtual void printInfo() {
        cout << "이름: " << name << " | HP: " << hp << endl;
    }

    virtual ~Character() {
    }
};

class Warrior : public Character {
public:
    Warrior() : Character("전사", 150) {
    }

    void attack() override {
        cout << "[전사] 검으로 공격합니다." << endl;
    }

    void specialAttack() override {
        cout << "[전사] 강력한 베기를 사용합니다." << endl;
    }
};

class Archer : public Character {
public:
    Archer() : Character("궁수", 100) {
    }

    void attack() override {
        cout << "[궁수] 화살을 발사합니다." << endl;
    }

    void specialAttack() override {
        cout << "[궁수] 연속 사격을 사용합니다." << endl;
    }
};

class Wizard : public Character {
public:
    Wizard() : Character("마법사", 80) {
    }

    void attack() override {
        cout << "[마법사] 마법탄을 발사합니다." << endl;
    }

    void specialAttack() override {
        cout << "[마법사] 광역 마법을 사용합니다." << endl;
    }
};

int main() {
    Character* characters[3];

    characters[0] = new Warrior();
    characters[1] = new Archer();
    characters[2] = new Wizard();

    cout << "===== 캐릭터 공격 테스트 =====" << endl;

    for (int i = 0; i < 3; i++) {
        characters[i]->printInfo();
        characters[i]->attack();
        characters[i]->specialAttack();
    }

    for (int i = 0; i < 3; i++)
        delete characters[i];

    cout << "모든 캐릭터 메모리를 해제했습니다." << endl;
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}
