/**
 * @file Work.h
 * @brief Заголовочный файл для класса Work, который выполняет обработку текста.
 */

#pragma once
#include <string>
#include <Input.h>

/**
 * @brief Класс для обработки текста.
 */
class Work {
public:
    /**
     * @brief Проверяет, является ли символ разделителем.
     * @param c Символ для проверки.
     * @param razd Строка с разделителями.
     * @return true, если символ является разделителем, иначе false.
     */
    bool isRazdel(char c, const std::string& razd);

    /**
     * @brief Считает количество слов в строке.
     * @param str Строка для подсчета.
     * @param razd Строка с разделителями.
     * @return Количество слов в строке.
     */
    int countWords(const std::string& str, const std::string& razd);

    /**
     * @brief Проверяет, является ли символ гласной буквой.
     * @param c Символ для проверки.
     * @return true, если символ является гласной, иначе false.
     */
    bool isGlasnaya(char c);

    /**
     * @brief Изменяет текст, заменяя гласные буквы символом замены.
     * @param str Строка для изменения.
     * @param zamen Символ замены.
     * @param razd Строка с разделителями.
     */
    void changeText(std::string& str, char zamen, const std::string& razd);

    /**
     * @brief Обрабатывает текст из объекта Input.
     * @param input Объект класса Input.
     */
    void processText(Input& input);
};
