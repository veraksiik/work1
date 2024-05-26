#include <iostream>
#include <Windows.h>
using namespace std;

//int Sum(int num1, int num2);
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int(*fPointer)(int num1, int num2);
//	fPointer = Sum;
//
//	return 0;
//}
//
//int Sum(int num1, int num2)
//{
//	int num3;
//	std::cout << "Введите первое число : ";
//	std::cin >> num1;
//	std::cout << "Введите первое число :";
//	std::cin >> num2;
//	num3 = num1 + num2;
//	std::cout << num3;
//	return 0;
//}
#include <iostream>
#include <cmath>

using namespace std;

double add(double a, double b) 
{ 
    return a + b; 

}
double subtract(double a, double b) 
{ 
    return a - b; 
}
double multiply(double a, double b) 
{ 
    return a * b; 
}
double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: Деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}
double modulo(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: Деление на ноль!" << endl;
        return 0;
    }
    return fmod(a, b);
}

double squareRoot(double a) {
    if (a < 0) {
        cout << "Ошибка: Невозможно извлечь корень из отрицательного числа!" << endl;
        return 0;
    }
    return sqrt(a);
}

double MakeDecision(double (*operation)(double, double), double a, double b) {
    return operation(a, b);
}

double MakeDecision(double (*operation)(double), double a) {
    return operation(a);
}

int main() {
    setlocale(LC_ALL, "ru");
    double num1, num2;
    char operation;

    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите операцию (+, -, *, /, %, sqrt(s)): ";
    cin >> operation;

    if (operation == 's') {
        cout << "Результат: " << MakeDecision(squareRoot, num1) << endl;
    }
    else {
        cout << "Введите второе число: ";
        cin >> num2;

        switch (operation) {
        case '+':
            cout << "Результат: " << MakeDecision(add, num1, num2) << endl;
            break;
        case '-':
            cout << "Результат: " << MakeDecision(subtract, num1, num2) << endl;
            break;
        case '*':
            cout << "Результат: " << MakeDecision(multiply, num1, num2) << endl;
            break;
        case '/':
            cout << "Результат: " << MakeDecision(divide, num1, num2) << endl;
            break;
        case '%':
            cout << "Результат: " << MakeDecision(modulo, num1, num2) << endl;
            break;
        default:
            cout << "Неверная операция!" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}


