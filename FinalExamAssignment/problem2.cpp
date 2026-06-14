#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Monster {
private:
    string name;
    int level;
    char* quiz;

public:
    Monster(string name, int level, const char* quiz) {
        this->name = name;
        this->level = level;

        this->quiz = new char[strlen(quiz) + 1];
        strcpy(this->quiz, quiz);
    }

    Monster(const Monster& ref) {
        name = ref.name;
        level = ref.level;

        quiz = new char[strlen(ref.quiz) + 1];
        strcpy(quiz, ref.quiz);
    }

    ~Monster() {
        delete[] quiz;
    }

    void setQuiz(const char* newQuiz) {
        delete[] quiz;

        quiz = new char[strlen(newQuiz) + 1];
        strcpy(quiz, newQuiz);
    }

    void setLevel(int newLevel) {
        level = newLevel;
    }

    void printInfo() {
        cout << "이름: " << name << endl;
        cout << "레벨: " << level << endl;
        cout << "수수께끼: " << quiz << endl;
    }
};

int main() {
    Monster firstMonster(
        "수수께끼 몬스터",
        100,
        "아침에는 네 발, 점심에는 두 발, 저녁에는 세 발인 것은?");

    Monster secondMonster(firstMonster);

    secondMonster.setQuiz("문이 뒤집어지면 무엇이 될까?");
    secondMonster.setLevel(10);

    cout << "[첫 번째 몬스터]" << endl;
    firstMonster.printInfo();

    cout << "[두 번째 몬스터]" << endl;
    secondMonster.printInfo();

    return 0;
}
