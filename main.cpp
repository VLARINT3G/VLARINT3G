/**
 * @file main.cpp
 * @brief Основной файл программы для обработки текста с использованием C++, SQLite и Doxygen.
 */

#include <iostream>
#include <Input.h>
#include <Work.h>
#include <Out.h>
#include <Database.h>
#include <sqlite3.h>

using namespace std;

/**
 * @brief Инициализация базы данных SQLite.
 * @param db Указатель на базу данных SQLite.
 * @return true, если база данных успешно открыта и таблица создана, иначе false.
 */
bool initDatabase(sqlite3*& db) {
    if (sqlite3_open("text_processing.db", &db)) {
        cerr << "Не удалось открыть базу данных: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    const char* sql = "CREATE TABLE IF NOT EXISTS TextEntries (id INTEGER PRIMARY KEY, text TEXT);";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "Ошибка SQL: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

/**
 * @brief Основная функция программы.
 * @return Код завершения программы (0 - успешное выполнение).
 */
int main() {
    Input input;
    Work processor;
    Out output;
    sqlite3* db;

    // Инициализация базы данных
    if (!initDatabase(db)) {
        return 1;
    }

    char choice;
    do {
        cout << "\nМеню:\n";
        cout << "1) Ввести текст\n";
        cout << "2) Обработать текст\n";
        cout << "3) Ввести разделители и символ замены\n";
        cout << "4) Показать текст\n";
        cout << "5) Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cin.ignore();
                input.setText();
                break;
            case '2':
                if (input.hasText() && input.hasZamena()) {
                    processor.processText(input);
                    cout << "Текст обработан." << endl;
                } else {
                    cout << "Ошибка: нет текста или символа замены." << endl;
                }
                break;
            case '3':
                input.setRazdel();
                input.setZamena();
                break;
            case '4':
                if (input.hasText()) {
                    output.show(input);
                    cout << "\nСохранить текст в файл? (Y/N): ";
                    char saveChoice;
                    cin >> saveChoice;
                    if (saveChoice == 'Y' || saveChoice == 'y') {
                        output.saveToFile(input, "Kursach.txt");
                        output.saveToDatabase(input, db);
                        cout << "Текст сохранен." << endl;
                    }
                } else {
                    cout << "Ошибка: нет текста." << endl;
                }
                break;
            case '5':
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор, попробуйте снова." << endl;
        }
    } while (choice != '5');

    // Закрытие базы данных
    sqlite3_close(db);
    return 0;
}
