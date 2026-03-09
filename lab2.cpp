#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    double double_precision = 3.14159265358979323846;
    float single_precision = 3.14159265358979323846f;
   
    double difference = double_precision - single_precision;

    cout << fixed << setprecision(20);
    cout << "Число в двойной точности (double): " << double_precision << endl;
    cout << "Число в одинарной точности (float): " << single_precision << endl;
    cout << "Разница между представлениями: " << difference << endl;
    cout << "\nРазмер double в байтах: " << sizeof(double) << " (64 бита)" << endl;
    cout << "Размер float в байтах: " << sizeof(float) << " (32 бита)" << endl;
    return 0;
}