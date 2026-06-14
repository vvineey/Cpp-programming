#include <iostream>
#include <string>
using namespace std;

class Engine {
public:
    virtual string describeEngine() {
        return "일반 엔진";
    }

    virtual string drive() {
        return "자동차가 주행합니다.";
    }

    virtual ~Engine() {
    }
};

class GasolineEngine : public Engine {
public:
    string describeEngine() override {
        return "가솔린 엔진";
    }

    string drive() override {
        return "자동차가 가솔린을 연소하여 주행합니다.";
    }
};

class DieselEngine : public Engine {
public:
    string describeEngine() override {
        return "디젤 엔진";
    }

    string drive() override {
        return "자동차가 디젤 연료를 연소하여 주행합니다.";
    }
};

class ElectricEngine : public Engine {
public:
    string describeEngine() override {
        return "전기 엔진";
    }

    string drive() override {
        return "자동차가 배터리 전력으로 모터를 구동하여 주행합니다.";
    }
};

class Car {
private:
    Engine* engine;

public:
    Car(Engine* engine) {
        this->engine = engine;
    }

    void describeCar() {
        cout << "자동차에 장착된 엔진: " << engine->describeEngine() << endl;
    }

    void driveCar() {
        cout << engine->drive() << endl;
    }

    void changeEngine(Engine* newEngine) {
        engine = newEngine;
    }
};

int main() {
    GasolineEngine gasolineEngine;
    DieselEngine dieselEngine;
    ElectricEngine electricEngine;

    Car car(&gasolineEngine);
    int engineNumber;

    while (true) {
        cout << "엔진 번호를 입력하세요 {1.가솔린, 2.디젤, 3.전기, 0.종료}: ";
        cin >> engineNumber;

        switch (engineNumber) {
            case 1:
                car.changeEngine(&gasolineEngine);
                break;
            case 2:
                car.changeEngine(&dieselEngine);
                break;
            case 3:
                car.changeEngine(&electricEngine);
                break;
            case 0:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            default:
                cout << "잘못된 엔진 번호입니다." << endl;
                continue;
        }

        car.describeCar();
        car.driveCar();
    }

    return 0;
}
