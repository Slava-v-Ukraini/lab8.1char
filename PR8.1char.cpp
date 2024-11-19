#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s, int i) {
    if (s[i] == '\0' || s[i + 1] == '\0')
        return 0; // ʳ���� �����, ����� ���� �� ���������

    if (s[i] == ',' && s[i + 1] == '-')
        return 1 + Count(s, i + 1); // �������� ����� ",-", ���������� � ���������� �������

    return Count(s, i + 1); // ���������� ��������
}

char* Change(char* s, char* dest, int i, int j) {
    if (s[i] == '\0') {
        dest[j] = '\0'; // ���������� ���������, ������ ���������� ������
        return dest;
    }

    if (s[i] == ',' && s[i + 1] == '-') {
        strcat_s(dest, 201, "*"); // ������ "*" ������ ����� ",-"
        return Change(s, dest, i + 2, j + 1); // ���������� ����� ",-", ���������� ���
    }
    else {
        dest[j] = s[i]; // ������� �������� ������
        dest[j + 1] = '\0'; // ��������� �����
        return Change(s, dest, i + 1, j + 1); // ���������� �� ���������� �������
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100); // �������� ����� ������������

    int count = Count(str, 0);
    cout << "String contained " << count << " groups of ',-'" << endl;

    char dest[201] = ""; // ����� ��� ���������� (����������� � ������� �� �����)
    Change(str, dest, 0, 0);

    cout << "Modified string (param) : " << dest << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
