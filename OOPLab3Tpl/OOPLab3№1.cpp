#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор за замовчуванням
    Date() : day(1), month(1), year(2000) {}

    // Конструктор з параметрами
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Функція для встановлення дня
    void setDay(int d) {
        if (d >= 1 && d <= 31)
            day = d;
        else
            std::cout << "Error: Invalid day." << std::endl;
    }

    // Функція для встановлення місяця
    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else
            std::cout << "Error: Invalid month." << std::endl;
    }

    // Функція для встановлення року
    void setYear(int y) {
        year = y;
    }

    // Функція для отримання дня
    int getDay() const {
        return day;
    }

    // Функція для отримання місяця
    int getMonth() const {
        return month;
    }

    // Функція для отримання року
    int getYear() const {
        return year;
    }

    // Функція друку в форматі "5 січня 2019 року"
    void printDate1() const {
        std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", 
                                   "August", "September", "October", "November", "December"};

        std::cout << day << " " << months[month - 1] << " " << year << " year" << std::endl;
    }

    // Функція друку в форматі "05.01.2019"
    void printDate2() const {
        std::cout << std::setfill('0') << std::setw(2) << day << "."
                  << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    }
};

// Програма тестування класу Date
int main() {


    // Створення об'єкту дати за замовчуванням
    Date date1;
    date1.printDate1(); // Виведе: 1 січня 2000 року
    date1.printDate2(); // Виведе: 01.01.2000

    std::cout << "\n";

    // Створення об'єкту дати з параметрами
    Date date2(5, 8, 2022);
    date2.printDate1(); // Виведе: 5 серпня 2022 року
    date2.printDate2(); // Виведе: 05.08.2022

    std::cout << "\n";

    // Зміна дати date1
    date1.setDay(25);
    date1.setMonth(12);
    date1.setYear(2019);
    date1.printDate1(); // Виведе: 25 грудня 2019 року
    date1.printDate2(); // Виведе: 25.12.2019

    return 0;
}

/*
#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* elements; // Вказівник на масив елементів
    int size;      // Число елементів у векторі
    int errorCode; // Код помилки

public:
    // Конструктор без параметрів
    Vector() : size(1), errorCode(0) {
        elements = new int[size];
        if (!elements)
            errorCode = -1; // Помилка: неможливо виділити пам'ять
        else
            elements[0] = 0; // Ініціалізуємо єдиний елемент вектора нулем
    }

    // Конструктор з одним параметром - розмір вектора
    Vector(int s) : size(s), errorCode(0) {
        elements = new int[size];
        if (!elements)
            errorCode = -1; // Помилка: неможливо виділити пам'ять
        else {
            for (int i = 0; i < size; ++i) {
                elements[i] = 0; // Ініціалізуємо всі елементи вектора нулем
            }
        }
    }

    // Конструктор з двома параметрами - розмір вектора та значення ініціалізації
    Vector(int s, int initValue) : size(s), errorCode(0) {
        elements = new int[size];
        if (!elements)
            errorCode = -1; // Помилка: неможливо виділити пам'ять
        else {
            for (int i = 0; i < size; ++i) {
                elements[i] = initValue; // Ініціалізуємо всі елементи вектора значенням initValue
            }
        }
    }

    // Конструктор копій
    Vector(const Vector& other) : size(other.size), errorCode(0) {
        elements = new int[size];
        if (!elements)
            errorCode = -1; // Помилка: неможливо виділити пам'ять
        else {
            for (int i = 0; i < size; ++i) {
                elements[i] = other.elements[i]; // Копіюємо елементи з іншого вектора
            }
        }
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements; // Звільнюємо попередні ресурси
            size = other.size;
            elements = new int[size];
            if (!elements) {
                errorCode = -1; // Помилка: неможливо виділити пам'ять
            } else {
                for (int i = 0; i < size; ++i) {
                    elements[i] = other.elements[i]; // Копіюємо елементи з іншого вектора
                }
                errorCode = 0; // Успішне присвоєння
            }
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] elements; // Звільняємо пам'ять
    }

    // Функція для встановлення значення елементу масиву (параметр за замовчуванням)
    void setElement(int index, int value = 0) {
        if (index >= 0 && index < size) {
            elements[index] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Функція для отримання значення елементу масиву
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return elements[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Функція друку вектора
    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    // Функція додавання векторів
    Vector add(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes do not match");
        }

        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // Функція віднімання векторів
    Vector subtract(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes do not match");
        }

        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    // Функція порівняння векторів (без скаляра)
    bool isEqual(const Vector& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; ++i) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }

        return true;
    }
};

// Програма тестування класу Vector
int main() {
    try {
        Vector v1(5, 10); // Створення вектора розміром 5 зі значенням 10
        Vector v2(5, 5);  // Створення вектора розміром 5 зі значенням 5

        v1.print(); // Виведе: [ 10 10 10 10 10 ]
        v2.print(); // Виведе: [ 5 5 5 5 5 ]

        Vector v3 = v1.add(v2); // Додавання векторів v1 і v2
        v3.print();             // Виведе: [ 15 15 15 15 15 ]

        Vector v4 = v1.subtract(v2); // Віднімання векторів v1 і v2
        v4.print();                  // Виведе: [ 5 5 5 5 5 ]

        if (v1.isEqual(v2)) {
            std::cout << "v1 and v2 are equal" << std::endl;
        } else {
            std::cout << "v1 and v2 are not equal" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
*/