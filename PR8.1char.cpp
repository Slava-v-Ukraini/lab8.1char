#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s, int i) {
    if (s[i] == '\0' || s[i + 1] == '\0')
        return 0; // Кінець рядка, більше нема що перевіряти

    if (s[i] == ',' && s[i + 1] == '-')
        return 1 + Count(s, i + 1); // Знайдена група ",-", продовжуємо з наступного символу

    return Count(s, i + 1); // Продовжуємо перевірку
}

char* Change(char* s, char* dest, int i, int j) {
    if (s[i] == '\0') {
        dest[j] = '\0'; // Завершення копіювання, додаємо термінуючий символ
        return dest;
    }

    if (s[i] == ',' && s[i + 1] == '-') {
        strcat_s(dest, 201, "*"); // Додаємо "*" замість групи ",-"
        return Change(s, dest, i + 2, j + 1); // Пропускаємо групу ",-", продовжуємо далі
    }
    else {
        dest[j] = s[i]; // Копіюємо поточний символ
        dest[j + 1] = '\0'; // Завершуємо рядок
        return Change(s, dest, i + 1, j + 1); // Переходимо до наступного символу
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100); // Введення рядка користувачем

    int count = Count(str, 0);
    cout << "String contained " << count << " groups of ',-'" << endl;

    char dest[201] = ""; // Рядок для результату (розраховано з запасом на заміну)
    Change(str, dest, 0, 0);

    cout << "Modified string (param) : " << dest << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
