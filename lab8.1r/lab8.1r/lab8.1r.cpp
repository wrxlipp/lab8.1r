#include <iostream>
#include <cstring>
using namespace std;

// ���������� ������� ��� ��������� ������� ������� "+", "-", "=".
int CountOccurrences(const char* str, int index = 0) {
    if (str[index] == '\0') return 0;  // ������� �������: ���� ������� ���� �����, ��������� 0.
    // ���� ������ ���� �� �������, ������ 1 � ��������� ������� ��� ���������� �������.
    return (str[index] == '+' || str[index] == '-' || str[index] == '=') + CountOccurrences(str, index + 1);
}

// ���������� ������� ��� ����� ������� ������� "+", "-", "=" �� ���� ������ "**".
void ReplaceSymbols(char* str, int index = 0) {
    if (str[index] == '\0') return;  // ������� �������: ���� ������� ���� �����, ��������� �������.
    if (str[index] == '+' || str[index] == '-' || str[index] == '=') {  // ���� ������ ���� �� �������.
        str[index] = '*';  // �������� ������ �� '*'.
        str[index + 1] = '*';  // �������� ��������� ������ �� '*'.
    }
    ReplaceSymbols(str, index + 1);  // ���������� ��������� ������� ��� ���������� �������.
}

int main() {
    char str[101];  // ���������� ������ ��� �������� �����.
    cout << "Enter string:" << endl;  // ����� �� �������� �����.
    cin.getline(str, 100);  // �������� ����� � ���������� �� 100 �������.
    cout << "Total occurrences of '+', '-', '=': " << CountOccurrences(str) << endl;  // ��������� ������� ������� "+", "-", "=".
    ReplaceSymbols(str);  // ������ ������� ��� ����� �������.
    cout << "Modified string: " << str << endl;  // ��������� �������������� �����.
    return 0;  // ���������� ��������.
}
