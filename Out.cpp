#include <Out.h>
#include <iostream>
#include <fstream>
using namespace std;

void Out::show(const Input& input) {
    for (const string& line : input.text) {
        cout << line << endl;
    }
}

void Out::saveToFile(const Input& input, const string& filename) {
    ofstream file(filename);
    for (const string& line : input.text) {
        file << line << endl;
    }
    file.close();
}

void Out::saveToDatabase(const Input& input, sqlite3* db) {
    for (const string& line : input.text) {
        string sql = "INSERT INTO TextEntries (text) VALUES ('" + line + "');";
        char* errMsg = nullptr;
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
            cerr << "Ошибка SQL: " << errMsg << endl;
            sqlite3_free(errMsg);
        }
    }
}
