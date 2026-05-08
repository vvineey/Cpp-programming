#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int scores[3];
    double average;

public:
    Student() {
        average = 0;
    }

    void setName(string studentName) {
        name = studentName;
    }

    void inputScores() {
        for (int i = 0; i < 3; i++) {
            while (true) {
                cout << "과목 " << i + 1 << " 점수: ";
                cin >> scores[i];

                if (scores[i] >= 0 && scores[i] <= 100)
                    break;

                cout << "유효하지 않은 점수입니다." << endl;
            }
        }
    }

    void calculateAverage() {
        int sum = 0;

        for (int i = 0; i < 3; i++)
            sum += scores[i];

        average = static_cast<double>(sum) / 3;
    }

    void printInfo() {
        cout << "이름: " << name << " | 점수: ";
        cout << scores[0] << ", " << scores[1] << ", " << scores[2];
        cout << " | 평균: " << fixed << setprecision(2) << average << endl;
    }

    string getName() {
        return name;
    }

    double getAverage() {
        return average;
    }
};

int main() {
    Student students[3];
    string name;

    for (int i = 0; i < 3; i++) {
        cout << "[학생 " << i + 1 << " 정보 입력]" << endl;
        cout << "이름: ";
        cin >> name;

        students[i].setName(name);
        students[i].inputScores();
        students[i].calculateAverage();
    }

    cout << "======= 성적 결과 =======" << endl;

    int bestIndex = 0;

    for (int i = 0; i < 3; i++) {
        students[i].printInfo();

        if (students[i].getAverage() > students[bestIndex].getAverage())
            bestIndex = i;
    }

    cout << "최고 평균 학생: " << students[bestIndex].getName();
    cout << " (" << fixed << setprecision(2) << students[bestIndex].getAverage() << ")" << endl;

    return 0;
}
