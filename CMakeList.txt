/**
 * @file Database.h
 * @brief Заголовочный файл для работы с базой данных SQLite.
 */

#pragma once
#include <sqlite3.h>

/**
 * @brief Функция для инициализации базы данных SQLite.
 * @param db Указатель на базу данных SQLite.
 * @return true, если база данных успешно открыта и таблица создана, иначе false.
 */
bool initDatabase(sqlite3*& db);
