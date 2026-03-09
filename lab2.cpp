#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL,"Russian");
    
    float single = 3.14;
    double double precision = 3.14;
    
    float difference float = single - double precision;
    
    double difference double = single - double precision;
    
    cout << "Разница между float и double для числа" << single << endl;
    cout << "Разница в формате float:" << difference float << endl;
    cout << "Разница в фориате double:" << difference double << endl;
    
    return 0;
}