/**
 * @file Input.h
 * @brief Заголовочный файл для класса Input, который отвечает за ввод и хранение текста.
 */

#pragma once
#include <vector>
#include <string>

/**
 * @brief Класс для ввода данных.
 */
class Input {
private:
    std::vector<std::string> text;  ///< Вектор строк текста.
    std::string razdel;             ///< Строка с разделителями.
    char zamena;                    ///< Символ замены для гласных букв.
    bool status;                    ///< Флаг, указывающий, введен ли текст.

public:
    /**
     * @brief Устанавливает разделители.
     */
    void setRazdel();

    /**
     * @brief Вводит строки текста от пользователя.
     */
    void setText();

    /**
     * @brief Устанавливает символ замены для гласных букв.
     */
    void setZamena();

    /**
     * @brief Проверяет, был ли введен текст.
     * @return true, если текст введен, иначе false.
     */
    bool hasText() const;

    /**
     * @brief Проверяет, установлен ли символ замены.
     * @return true, если символ замены установлен, иначе false.
     */
    bool hasZamena() const;

    friend class Work;  ///< Дает доступ классу Work.
    friend class Out;   ///< Дает доступ классу Out.
};
