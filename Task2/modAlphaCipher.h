/** @file
 * @author Авдонин А.С.
 * @version 1.0
 * @date 5.12.23
 * @copyright ИБСТ ПГУ
 * @warning Лабораторная работа №4
 * @brief Заголовочный файл для модуля шифра Табличной перестановки
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <codecvt>
#include <algorithm>

/** @brief Шифрование методом Табличной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */

class modAlphaCipher
{
private:
    /// ключ для конструктора
    int newkey;
    
public:
        /**
        * @brief Метод для проверки ключа \n
        * Если ключ меньше 0, то он считается неправильным \n
        * @param [in] s число типа int
        * @return число типа int
        * @throw cipher_error, если ключ меньше 0 
        */
    int getValidKey(int &s);
        /**
        * @brief Метод для проверки соответствия длинны ключа длинне текста \n
        * Длина ключа должна быть меньше длины сообщения \n
        * @param [in] text строка с сообщением типа string
        * @param [in] key число типа int
        * @return строка типа string
        * @throw cipher_error, если строка короче ключа
        */
    int getValidKeyText(int key, std::string &text);
        /**
        * @brief Метод для проверки текста для зашифрования/расшифрования \n
        * Все символы не принадлежащие английскому алфавиту удаляются \n
        * @param [in] s строка с сообщением типа string
        * @return строка типа string
        * @throw cipher_error, если строка пуста
        */
    std::string getValidOpenText(std::string &s);
    ///запретим конструктор без параметров
    modAlphaCipher()=delete;
    ///конструктор для установки ключа
    modAlphaCipher(const int& key, std::string) :newkey(key) {};
        /**
        * @brief Зашифрование
        * @param [in] user_str Строка для зашифрования
        * @return Зашифрованная строка
        */   
    std::string encrypt(const std::string& user_str);  
        /**
        * @brief Расшифровывание
        * @param [in] user_str Строка для зашифрования
        * @return Расшифрованная строка
        */
    std::string decrypt(const std::string& user_str); 
};
        /** @brief класс-исключение cipher_error 
         * @details производный от класса std::invalid_argument \n
         * В данном классе перегружены конструкторы с параметрами. \n
         * При перегрузке явно указан вызов конструктора базового класса с параметром
         */
class cipher_error: public std::invalid_argument {
    public:
        explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
        explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};