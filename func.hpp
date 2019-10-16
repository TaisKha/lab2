#ifndef func_hpp
#define func_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
#endif /* func_hpp */

class ITservice{ //класс IT-компаниии
private:
    string service; //название услуги
    int price; //цена услуги
    int term; //срок выполнения
    int preprice; //размер предоплата
public:
    ITservice(string); //конструктор
    void printIT(); //вывод класса на экран
    void write_to_file(string, bool); //запись экземляра класса в файл
    friend bool operator>(const ITservice, const ITservice); //перегрузка оператора >
    friend bool operator<(const ITservice, const ITservice); //перегрузка оператора <
    friend bool operator>=(const ITservice, const ITservice); //перегрузка оператора >=
    friend bool operator<=(const ITservice, const ITservice); //перегрузка оператора <=
   // void swap(ITservice&, ITservice&);
};
void generate(); //генерирование рандомных данных и запись в файл
void write_to_vector(vector<ITservice>&); //запись в вектор данных из файла
void insert_sort(vector<ITservice>); // сортировска простыми вставками
void buble_sort(vector<ITservice>); //сортировка пузырьком


