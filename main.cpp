#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void checkInt(string type);

struct Pipe {
    string name;
    double length = 0;
    double diameter = 0;
    bool repairStatus = false;
    
    void readFromConsole() {
        cout << "Введите название трубы: " << endl;
        cin.ignore();
        getline(cin, name);
        checkInt("Введите количество цехов: ");
        
        
    }
    
    void writeToConsole() {
        cout << "Название трубы: " << name << endl;
        cout << "Длина трубы(в км): " << length << endl;
        cout << "Диаметр(в мм): " << diameter << endl;
        cout << "Ремонтный статус: " << (repairStatus ? "Да" : "Нет") << endl;
    }
     
    void editRepairStatus() {
    }
    
    void saveToFile() {
    }
    
    void loadFromFile() {
    }
};

struct CS {
    string name;
    double workshopNumber;
    double workshopNumberInWork;
    double efficiency;

    void readFromConsole() {
    }
    
    void writeToConsole() {
    }
    
    void editWorkshop() {
    }
    
    void startWorkshop() {
    }
    
    void stopWorkshop() {
    }
    
    void saveToFile() {
    }
    
    void loadFromFile() {
    }
};

void menuDisplay() {
    cout << " Меню:          " << endl;
    cout << " 1 - Добавить трубу         " << endl;
    cout << " 2 - Добавить КС            " << endl;
    cout << " 3 - Просмотр всех объектов " << endl;
    cout << " 4 - Редактировать трубу    " << endl;
    cout << " 5 - Редактировать КС       " << endl;
    cout << " 6 - Сохранить              " << endl;
    cout << " 7 - Загрузить              " << endl;
    cout << " 0 - Выход                  " << endl;
}

void checkInt(string type) {
    int numb;
    while (true) {
        cout << type << endl;
        cin >> numb;
        if (numb < 0) {
            cout << numb << endl;
            break;
        }
    }
}

int main() {
    Pipe pipe;
    CS cs;
    int command;
    
    while (true) {
        menuDisplay();
        cout << "Выберите команду: ";
        cin >> command;
        
        switch (command) {
        case 1:
            pipe.readFromConsole();
            break;
        case 2:
            cs.readFromConsole();
            break;
        case 3:
            pipe.writeToConsole();
            cs.writeToConsole();
            break;
        case 4:
            pipe.editRepairStatus();
            break;
        case 5:
            cs.editWorkshop();
            break;
        case 6: {

            break;
        }
        case 7: {

            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
            break;
        }
    }
}
