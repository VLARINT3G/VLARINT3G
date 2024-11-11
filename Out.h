/**
 * @file Out.h
 * @brief Заголовочный файл для класса Out, который отвечает за вывод и сохранение текста.
 */

#pragma once
#include <string>
#include <Input.h>
#include <sqlite3.h>

/**
 * @brief Класс для вывода и сохранения текста.
 */
class Out {
public:
    /**
     * @brief Выводит текст на экран.
     * @param input Объект класса Input.
     */
    void show(const Input& input);

    /**
     * @brief Сохраняет текст в файл.
     * @param input Объект класса Input.
     * @param filename Имя файла для сохранения.
     */
    void saveToFile(const Input& input, const std::string& filename);

    /**
     * @brief Сохраняет текст в базу данных SQLite.
     * @param input Объект класса Input.
     * @param db Указатель на базу данных SQLite.
     */
    void saveToDatabase(const Input& input, sqlite3* db);
};
