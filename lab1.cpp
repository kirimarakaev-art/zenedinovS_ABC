#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
double binaryToDecimal(const string& binary) {
    size_t dotPos = binary.find('.');
    string intPart, fracPart;

    if (dotPos == string::npos) {
        intPart = binary;
        fracPart = "";
    } else {
        intPart = binary.substr(0, dotPos);
        fracPart = binary.substr(dotPos + 1);
    }

    double result = 0.0;

    // Обработка целой части
    int intLen = intPart.length();
    for (int i = 0; i < intLen; ++i) {
        if (intPart[i] == '1') {
            result += pow(2.0, intLen - 1 - i);
        } else if (intPart[i] != '0') {
            throw invalid_argument("Недопустимый символ в целой части.");
        }
    }

    // Обработка дробной части
    int fracLen = fracPart.length();
    for (int i = 0; i < fracLen; ++i) {
        if (fracPart[i] == '1') {
            result += pow(2.0, -(i + 1));
        } else if (fracPart[i] != '0') {
            throw invalid_argument("Недопустимый символ в дробной части");
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL,"Russian");
    string filename;

    // Получение имени файла
    if (argc > 1) {
        filename = argv[1];
    } else {
        cout << "Введите имя входного файла: ";
        cin >> filename;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return 1;
    }

    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        lineNum++;
        
        // Удаление пробелов в начале и конце строки
        size_t first = line.find_first_not_of(" \t\n\r");
        if (first == string::npos) {
            continue; // пустая строка
        }
        size_t last = line.find_last_not_of(" \t\n\r");
        string trimmed = line.substr(first, last - first + 1);

        // Проверка допустимых символов и количества точек
        bool valid = true;
        int dotCount = 0;
        for (char c : trimmed) {
            if (c == '.') {
dotCount++;
                if (dotCount > 1) {
                    valid = false;
                    break;
                }
            } else if (c != '0' && c != '1') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cerr << "Предупреждение: линия " << lineNum << " Содержит недопустимые символы, пропускаем." << endl;
            continue;
        }

        try {
            double decimal = binaryToDecimal(trimmed);
            cout << trimmed << " (binary) = " << decimal << " (decimal)" << endl;
        } catch (const exception& e) {
            cerr << "Ошибка преобразования строки " << lineNum << ": " << e.what() << endl;
        }
    }

    file.close();
    return 0;
}