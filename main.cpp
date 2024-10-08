#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  // Для strtol
#include <sstream>  // Для stringstream
#include <limits>   // Для numeric_limits

using namespace std;

int inputIntInRange(const string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            if (value >= minValue && value <= maxValue) {
                return value;
            } else {
                cout << "Ошибка: введите число от " << minValue << " до " << maxValue << "." << endl;
            }
        } else {
            cout << "Ошибка: введите корректное целое число." << endl;
        }
    }
}

double inputDoubleInRange(const string& prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            if (value >= minValue && value <= maxValue) {
                return value;
            } else {
                cout << "Ошибка: введите число от " << minValue << " до " << maxValue << "." << endl;
            }
        } else {
            cout << "Ошибка: введите корректное число." << endl;
        }
    }
}

struct Pipe {
    string name;
    double length = 0;
    double diameter = 0;
    bool repairStatus = false;

    
    void readFromConsole() {
        cout << "Введите название трубы: ";
        getline(cin, name);
        length = inputDoubleInRange("Введите длину трубы (в км): ", 0.1, 10000);
        diameter = inputDoubleInRange("Введите диаметр трубы (в мм): ", 10, 10000);
        
        repairStatus = false;
    }
    
    void writeToConsole() {
        if (length > 0) {
            cout << " " << endl;
            cout << "Название трубы: " << name << endl;
            cout << "Длина трубы(в км): " << length << endl;
            cout << "Диаметр(в мм): " << diameter << endl;
            cout << "Ремонтный статус: " << (repairStatus ? "Да" : "Нет") << endl << endl;
        }
        else {
            cout << " " << endl;
            cout << "Труба не создана" << name << endl << endl;
        }
    }
     
    void editRepairStatus() {
        if (name.length() > 0) {
            repairStatus = !repairStatus;
            cout << "Ремонтный статус изменен на: " << (repairStatus ? "Да" : "Нет") << endl;
        }
        else {
            cout << "Создайте трубу, объект не существует" << endl;
        }
    }
    
};

struct CS {
    string name;
    int workshopNumber;
    int workshopNumberInWork;
    int efficiency;

    void readFromConsole() {
        cout << "Введите название станции: ";
        getline(cin, name);
        
        workshopNumber = inputIntInRange("Введите количество цехов: ", 1, 1000);
        workshopNumberInWork = inputIntInRange("Введите количество цехов в работе: ", 0, workshopNumber);
        efficiency = inputIntInRange("Введите эффективность (в %): ", 0.01, 100);
    }
    
    void writeToConsole() {
        if (name.empty()) {
            cout << "КС не создана" << endl << endl;
        }
        else {
            cout << "Название станции: " << name << endl;
            cout << "Количество цехов:" << workshopNumber << endl;
            cout << "Количество цехов в работе: " << workshopNumberInWork << endl;
            cout << "Эффективность(в %)" << efficiency << endl << endl;
        }
    }
    
    void editWorkshop() {
        int command;
        cout << " 1 - Запустить цех  " << endl;
        cout << " 2 - Остановить цех " << endl;

        command = inputIntInRange("Выберете действие:", 1, 2);
        
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
                    cout << "Все цехи остановлены" << endl;
                }
                break;
            default: // -1
                cout << "Неверный выбор, попробуйте снова." << endl;
        }
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
    cout << " 0 - Выход                  " << endl << endl;
}

bool isNumber(const std::string& s)
{
    return  s.length() < 2 and !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

long numberOrDefault(const string& command){
    if (isNumber(command)) {
        return strtol(command.c_str(), NULL, 10);
    }
    return -1;
}




void saveToFile(const Pipe& pipe, const CS& cs) {
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        if (!pipe.name.empty()) {
            outFile << "PIPE" << endl;
            outFile << pipe.name << endl;
            outFile << pipe.length << endl;
            outFile << pipe.diameter << endl;
            outFile << (pipe.repairStatus ? "1" : "0") << endl;
        }

        if (!cs.name.empty()) {
            outFile << "CS" << endl;
            outFile << cs.name << endl;
            outFile << cs.workshopNumber << endl;
            outFile << cs.workshopNumberInWork << endl;
            outFile << cs.efficiency << endl;
        }

        outFile.close();
        cout << "Данные сохранены в файл data.txt" << endl;
    } else {
        cout << "Не удалось открыть файл для записи" << endl;
    }
}

void loadFromFile(Pipe& pipe, CS& cs) {
    int a;
    int b;
    double c;
    string name;
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            try {
                if (line == "PIPE") {
                    getline(inFile, pipe.name);

                    getline(inFile, line);
                    pipe.length = stod(line);

                    getline(inFile, line);
                    pipe.diameter = stod(line);

                    getline(inFile, line);
                    pipe.repairStatus = (line == "1") ? true : false;

                    if (pipe.length < 0.1 || pipe.length > 10000) {
                        cerr << "Ошибка: длина трубы из файла некорректна." << endl;
                        inFile.close();
                        return;
                    }
                    if (pipe.diameter < 10 || pipe.diameter > 10000) {
                        cerr << "Ошибка: диаметр трубы из файла некорректен." << endl;
                        inFile.close();
                        return;
                    }

                } else if (line == "CS") {
//                    getline(inFile, cs.name);
//
//                    getline(inFile, line);
//                    cs.workshopNumber = stoi(line);
//
//                    getline(inFile, line);
//                    cs.workshopNumberInWork = stoi(line);
//
//                    getline(inFile, line);
//                    cs.efficiency = stoi(line);
                    
                    getline(inFile, name);
                    getline(inFile, line);
                    a = stoi(line);
                    
                    getline(inFile, line);
                    b = stoi(line);
                    
                    getline(inFile, line);
                    c = stoi(line);

//                    if (cs.workshopNumber < 1 || cs.workshopNumber > 1000) {
//                        cerr << "Ошибка: количество цехов из файла некорректно." << endl;
//                        inFile.close();
//                        return;
//                    } else {
//                        
//                    }
//                    if (cs.workshopNumberInWork < 1 || cs.workshopNumberInWork > cs.workshopNumber) {
//                        cerr << "Ошибка: количество рабочих цехов из файла некорректно." << endl;
//                        inFile.close();
//                        return;
//                    }
//                    if (cs.efficiency < 0.1 || cs.efficiency > 100) {
//                        cerr << "Ошибка: эффективность из файла некорректна." << endl;
//                        inFile.close();
//                        return;
//                    }
                    if (a > 1 and a < 1000 and b > 1 and b < a and c > 0.1 and c < 100) {
                        getline(inFile, cs.name);
    
                        getline(inFile, line);
                        cs.workshopNumber = stoi(line);
    
                        getline(inFile, line);
                        cs.workshopNumberInWork = stoi(line);
    
                        getline(inFile, line);
                        cs.efficiency = stoi(line);
                    }
                        
                    if (a < 1 || a > 1000) {
                        cerr << "Ошибка: количество цехов из файла некорректно." << endl;
                        inFile.close();
                        return;
                    }
                    if (cs.workshopNumberInWork < 1 || cs.workshopNumberInWork > cs.workshopNumber) {
                        cerr << "Ошибка: количество рабочих цехов из файла некорректно." << endl;
                        inFile.close();
                        return;
                    }
                    if (cs.efficiency < 0.1 || cs.efficiency > 100) {
                        cerr << "Ошибка: эффективность из файла некорректна." << endl;
                        inFile.close();
                        return;
                    }
                }
            } catch (const invalid_argument& e) {
                cerr << "Ошибка: некорректный формат данных в файле." << endl;
                pipe.name = "";
                cs.name = "";
                inFile.close();
                return;
            } catch (const out_of_range& e) {
                cerr << "Ошибка: значение из файла выходит за пределы допустимого диапазона." << endl;
                inFile.close();
                return;
            }
        }
        inFile.close();
        cout << "Данные загружены из файла data.txt" << endl;
    } else {
        cout << "Не удалось открыть файл для чтения" << endl;
    }
}

long numberInRange(const string& prompt, long minValue, long maxValue) {
    long value;
    while (true) {
        value = numberOrDefault(prompt);
        if (value >= minValue && value <= maxValue) {
            return value;
        } else {
            std::cout << "Ошибка: введите число от " << minValue << " до " << maxValue << ". Попробуйте снова." << std::endl;
        }
    }
}

int main() {
    Pipe pipe;
    CS cs;
    string command;
    long value;
    
    while (true) {
        menuDisplay();
        cout << "Выберите команду: ";

        getline(cin, command);

        value = numberOrDefault(command);
        
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
            if (pipe.name.empty()) {
                cout << "Труба еще не создана. Сначала добавьте трубу." << endl;
            } else {
                pipe.editRepairStatus();
            }
            break;
        case 5:
            cs.editWorkshop();
            break;
        case 6:
            saveToFile(pipe, cs);
            break;
        case 7:
            loadFromFile(pipe, cs);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default: // -1
            cout << "Неверный выбор, попробуйте снова." << endl;
            continue;
        }
    }
}
