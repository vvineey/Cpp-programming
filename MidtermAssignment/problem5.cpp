#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(string vehicleName, int speed) {
        name = vehicleName;
        maxSpeed = speed;
        currentSpeed = 0;
    }

    virtual void accelerate() {
        cout << "[" << name << "] 기본 가속" << endl;
    }

    void stop() {
        currentSpeed = 0;
        cout << name << " 정지" << endl;
    }

    void printInfo() {
        cout << "-> " << name << " | 최대 속도: " << maxSpeed;
        cout << " | 현재 속도: " << currentSpeed << endl;
    }

    virtual ~Vehicle() {
    }
};

class Car : public Vehicle {
public:
    Car() : Vehicle("자동차", 200) {
    }

    void accelerate() override {
        if (currentSpeed >= maxSpeed) {
            cout << "[자동차] 엔진 가속: 최대 속도 도달 (" << currentSpeed << ")" << endl;
            return;
        }

        currentSpeed += 20;

        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;

        cout << "[자동차] 엔진 가속: 현재 속도 " << currentSpeed << endl;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle() : Vehicle("자전거", 30) {
    }

    void accelerate() override {
        if (currentSpeed >= maxSpeed) {
            cout << "[자전거] 페달 가속: 최대 속도 도달 (" << currentSpeed << ")" << endl;
            return;
        }

        currentSpeed += 5;

        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;

        cout << "[자전거] 페달 가속: 현재 속도 " << currentSpeed << endl;
    }
};

class Airplane : public Vehicle {
public:
    Airplane() : Vehicle("비행기", 900) {
    }

    void accelerate() override {
        if (currentSpeed >= maxSpeed) {
            cout << "[비행기] 엔진 풀파워 가속: 최대 속도 도달 (" << currentSpeed << ")" << endl;
            return;
        }

        currentSpeed += 100;

        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;

        cout << "[비행기] 엔진 풀파워 가속: 현재 속도 " << currentSpeed << endl;
    }
};

int main() {
    Vehicle* vehicles[3];

    vehicles[0] = new Car();
    vehicles[1] = new Bicycle();
    vehicles[2] = new Airplane();

    cout << "===== 탈것 가속 테스트 =====" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            vehicles[i]->accelerate();

        vehicles[i]->printInfo();
    }

    cout << "===== 가속 추가 테스트 =====" << endl;

    for (int i = 0; i < 4; i++)
        vehicles[1]->accelerate();

    vehicles[1]->printInfo();

    for (int i = 0; i < 3; i++)
        delete vehicles[i];

    cout << "메모리 해제 완료" << endl;
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}
