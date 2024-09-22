#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  // Для strtol


using namespace std;



struct Pipe {
    string name;
    double length = 0;
    double diameter = 0;
    bool repairStatus = false;
    
    void readFromConsole() {
        cout << "Введите название трубы: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Введите длину трубы(в км): ";
        cin >> length;
        
        cout << "Введите диаметр трубы(в мм): ";
        cin >> diameter;
        
        repairStatus = false;
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
    int workshopNumber;
    int workshopNumberInWork;
    int efficiency;

    void readFromConsole() {
        cout << "Введите название станции: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Введите количество цехов: ";
        cin >> workshopNumber;
        
        cout << "Введите количество цехов в работе: ";
        cin >> workshopNumberInWork;
        
        cout << "Введите Эффективность(в %): ";
        cin >> efficiency;
    }
    
    void writeToConsole() {
        cout << "Название трубы: " << name << endl;
        cout << "Количество цехов:" << workshopNumber << endl;
        cout << "Количество цехов в работе: " << workshopNumberInWork << endl;
        cout << "Эффективность(в %)" << efficiency << endl;
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
    cout << "                   " << endl;
}

bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

long numberOrNull(const string& command, const long& value){
    if (isNumber(command)) {
        long value = strtol(command.c_str(), NULL, 10);
    }
    return value;
}


int main() {
    Pipe pipe;
    CS cs;
    string command;
    long value = 0;
    
    while (true) {
        menuDisplay();
        cout << "Выберите команду: ";
        cin >> command;

        numberOrNull(command, value);
        
        switch (value) {
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
            pipe.saveToFile();
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
            continue;
        }
    }
}
