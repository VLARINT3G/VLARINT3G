#include <Input.h>
#include <iostream>
using namespace std;

void Input::setRazdel() {
    cout << "Введите разделители: ";
    cin.ignore();
    getline(cin, razdel);
}

void Input::setText() {
    status = true;
    string buffer;
    cout << "Введите строки текста (для завершения введите пустую строку):" << endl;

    while (true) {
        getline(cin, buffer);
        if (buffer.empty()) break;
        text.push_back(buffer);
    }
}

void Input::setZamena() {
    cout << "Введите символ замены: ";
    cin >> zamena;
}

bool Input::hasText() const {
    return !text.empty();
}

bool Input::hasZamena() const {
    return zamena != '\0';
}
