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
    //string pipeText[3] =

    
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
        if (length > 0) {
            cout << " " << endl;
            cout << "Название трубы: " << name << endl;
            cout << "Длина трубы(в км): " << length << endl;
            cout << "Диаметр(в мм): " << diameter << endl;
            cout << "Ремонтный статус: " << (repairStatus ? "Да" : "Нет") << endl;
            cout << " " << endl;
        }
        else {
            cout << " " << endl;
            cout << "Труба не создана" << name << endl;;
            cout << " " << endl;
        }
    }
     
    void editRepairStatus() {
        if (name.length() > 0) {
            repairStatus == !repairStatus;
            cout << "Ремонтный статус изменен на:" << (repairStatus ? "Да" : "Нет") << endl;
        }
        else {
            cout << "Создайте трубу, объект не существует" << endl;
        }
    }
    
    void saveToFile() {
    }
    
    void loadFromFile() {
    };
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
        if (name.empty()) {
            cout << "КС не создана" << endl;
            cout << " " << endl;
        }
        else {
            cout << "Название станции: " << name << endl;
            cout << "Количество цехов:" << workshopNumber << endl;
            cout << "Количество цехов в работе: " << workshopNumberInWork << endl;
            cout << "Эффективность(в %)" << efficiency << endl;
            cout << " " << endl;
        }
    }
    
    void editWorkshop() {
        int command;
        cout << " 1 - Запустить цех  " << endl;
        cout << " 2 - Остановить цех " << endl;
        cout << " Выберете действие: ";

        cin >> command;
        switch (command) {
            case 1:
                if (workshopNumber > workshopNumberInWork) {
                    workshopNumberInWork++;
                    cout << "Еще один цех запущен" << endl;
                    cout << "Теперь в работе " << workshopNumberInWork << " из " << workshopNumber << " цехов " << endl;
                }
                else {
                    cout << "Все цехи запущены" << endl;
                }
                break;
            case 2:
                if (0 < workshopNumberInWork) {
                    workshopNumberInWork--;
                    cout << "Цех остановлен" << endl;
                    cout << "Теперь в работе " << workshopNumberInWork << " из " << workshopNumber << " цехов" << endl;
                }
                else {
                    cout << "Все цехи запущены" << endl;
                }
                break;
            default: // -1
                cout << "Неверный выбор, попробуйте снова." << endl;
        }
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

//int chechNumber(const int& a, const int& b)
//{
//    while (condition) {
//        statements
//    }
//    return 0;
//}

bool isNumber(const std::string& s)
{
    return  s.length() < 2 and !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

long numberOrDefault(const string& command){
    if (isNumber(command)) {
        return strtol(command.c_str(), NULL, 10);
    }
    //cout << "Ошибка";
    return -1;
}

int main() {
    Pipe pipe;
    CS cs;
    string command;
    long value;
    
    while (true) {
        menuDisplay();
        cout << "Выберите команду: ";
        //cin >> command;4
        //cin.ignore();
        cin.ignore();
        getline(cin, command);
        //cout << command << endl;

        value = numberOrDefault(command);
        //cout << value << endl;
        
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
            pipe.loadFromFile();
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default: // -1
            cout << "Неверный выбор, попробуйте снова." << endl;
            continue;
        }
    }
}
