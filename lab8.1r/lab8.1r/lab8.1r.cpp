#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція для підрахунку кількості символів "+", "-", "=".
int CountOccurrences(const char* str, int index = 0) {
    if (str[index] == '\0') return 0;  // Базовий випадок: якщо досягли кінця рядка, повертаємо 0.
    // Якщо символ один із шуканих, додаємо 1 і викликаємо функцію для наступного символа.
    return (str[index] == '+' || str[index] == '-' || str[index] == '=') + CountOccurrences(str, index + 1);
}

// Рекурсивна функція для заміни кожного символу "+", "-", "=" на пару зірочок "**".
void ReplaceSymbols(char* str, int index = 0) {
    if (str[index] == '\0') return;  // Базовий випадок: якщо досягли кінця рядка, завершити функцію.
    if (str[index] == '+' || str[index] == '-' || str[index] == '=') {  // Якщо символ один із шуканих.
        str[index] = '*';  // Замінюємо символ на '*'.
        str[index + 1] = '*';  // Замінюємо наступний символ на '*'.
    }
    ReplaceSymbols(str, index + 1);  // Рекурсивно викликаємо функцію для наступного символа.
}

int main() {
    char str[101];  // Оголошення масиву для введення рядка.
    cout << "Enter string:" << endl;  // Запит на введення рядка.
    cin.getline(str, 100);  // Введення рядка з обмеженням на 100 символів.
    cout << "Total occurrences of '+', '-', '=': " << CountOccurrences(str) << endl;  // Виведення кількості символів "+", "-", "=".
    ReplaceSymbols(str);  // Виклик функції для заміни символів.
    cout << "Modified string: " << str << endl;  // Виведення модифікованого рядка.
    return 0;  // Завершення програми.
}
