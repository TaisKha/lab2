#include "func.hpp"
ITservice::ITservice(string s){ //конструктор
    int pos1 = 0;
    int pos2 = s.find(';', pos1); //ставим указатель на первый разделитель ;
    service = s.substr(pos1, pos2 - pos1); //записывам в переменную все, что находится между pos1 и pos2
    pos1 = pos2 + 1; //сдвигаем pos1 на начало следующего слова
    pos2 = s.find(';',pos1); // находим следующий разделитель
    price = stoi(s.substr(pos1, pos2 - pos1)); //записываем аналогично, при этом преобразовывая строку в число
    pos1 = pos2 + 1; //сдвигаем pos1 на начало следующего слова
    pos2 = s.find(';',pos1);//находим следующий разделитель
    term = stoi(s.substr(pos1, pos2 - pos1));//записываем аналогично, при этом преобразовывая строку в число
    pos1 = pos2 + 1; //сдвигаем pos1 на начало  следующего слова
    pos2 = s.find(';',pos1);//находим следующий разделитель
    preprice = stoi(s.substr(pos1, pos2 - pos1));//записываем аналогично, при этом преобразовывая строку в число
    
}
void ITservice::printIT(){//печать атрибутов класса
    cout << service <<' '<< price << ' ' << term << ' ' << ' ' << preprice << ' ' << endl;
}
void ITservice::write_to_file(string str, bool choice){
    ofstream f;
    if (choice){
        f.open(str); //перезаписываем файл
    }else{
            f.open(str, ios::app); //дописываем в файл
    }
    if (!f){ //проверка, открылся ли файл
        cout << "Error of openning file" << str << endl;
        exit(1);
    }
    f << service << ";" << price << ";" << term << ";" << preprice << '\n'; //записали в файл
    f.close();
}
// перегрузка операторов сравнения
 //если названия услуги одинаковые, то сравнение производим по цене услуги
bool operator>(const ITservice a, const ITservice b){
    if (a.service == b.service) {
        return (a.price > b.price);
    } else {
        return (a.service > b.service);
    }
}
bool operator<(const ITservice a, const ITservice b){
    if (a.service == b.service) {
        return (a.price < b.price);
    } else {
        return (a.service < b.service);
    }
}
bool operator>=(const ITservice a, const ITservice b){
    if (a.service == b.service) {
        return (a.price >= b.price);
    } else {
        return (a.service >= b.service);
    }
}
bool operator<=(const ITservice a, const ITservice b){
    if (a.service == b.service) {
        return (a.price <= b.price);
    } else {
        return (a.service <= b.service);
    }
}

void generate(){
    srand (time(NULL)); //сделано, чтобы функция rand() возвращала разные наборы
    int x; //размерность данных
    cout << "how many data would you like to check ? ";
    cin >> x;
    int length;
    ofstream f("fail1.csv"); //открываем файл на запись
    if (!f){ //проверка на успешное открытие файла
        cout << "Error of opening file 'fail1.csv'" << endl;
        exit(1);
    }
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //массив, из которого будут сгенерированы абберевеатуры IT-услуг
    string s; //строка, которую потом записываем в файл
    int money;
    for (int i = 0; i < x; i++){
        length = rand() % 5 + 3; //длина слова генерируется от 3 до 7
        s = ""; //обновление строки на каждое итерации цикла
        for (int j = 0; j < length; j++){//генерируем слово длины length
            s += alpha[rand() % (sizeof(alpha) - 1)]; //добавляя по одной рандомной букве из массива alpha
        }
        money = rand() % 1000000 + 1; //цена на услуги не превосходит 1 000 000
        //предоплата равно либо полной стоимости, либо половине, либо трети
        f << s << ';' << money << ';' << rand() % 90 + 1 << ';' << money / (rand() % 3 + 1) << '\n'; //записываем в файл
    }
    f.close(); //закрываем файл
}
void write_to_vector(vector<ITservice> &vec){ //функция считывания из сгенерированного файла и записи в вектор
    string str;//строка для считывания из файла
    ifstream f;
    f.open("fail1.csv"); //открываем файл для чтения
    if (!f){//проверка на успешное открытие файла
        cout << "Error 2 of openning file 'fail1.csv'";
        exit(1);
    }
     while (getline(f, str)){ //считываем до конца файла
         vec.push_back(str);//записываем в конец вектора
     }
    f.close();//закрываем в файл
}
void insert_sort(vector<ITservice> x){ //сортировка простыми вставками
     
    clock_t time;
    time = clock(); //засекаем время программно
    for(int i = 0; i < x.size(); i++){
        for(int j = i; j > 0 && x[j-1] > x[j] ; j--){ // пока j > 0 и элемент j-1 > j, x-массив int
                swap(x[j-1], x[j]);
        }
    }// меняем местами элементы j и j-1
    time = clock() - time; //считаем сколько времени прошло
    cout  <<  "sorted by inserted sort : " << (double)time / CLOCKS_PER_SEC << endl;
    bool choice = true; //переменная-флаг, контролирующая нужно ли перезаписывать в файл или дописывать
    for (int i = 0; i < x.size(); i++){
        x[i].write_to_file("buble.csv", choice); //записываем отсортированный вектор в файл
        choice = false;

    }
}
void buble_sort(vector<ITservice> x){
    clock_t time;
    time = clock();//засекаем время программно
    for (int i = 0; i < x.size(); i++){
        for(int j = x.size() - 1; j > i; j--){ //идем с коца в начало
            if (x[j-1] > x[j]) swap(x[j-1], x[j]); //если x[j-1] > x[j], то меняем местами
        }
    }
    time = clock() - time;//считаем сколько прошло времени
    cout <<  "sorted by buble sort : " << (double)time / CLOCKS_PER_SEC << endl;
    int choice = true;//переменная-флаг, контролирующая нужно ли перезаписывать в файл или дописывать
    for (int i = 0; i < x.size(); i++){
        x[i].write_to_file("insert.csv", choice);//записываем отсортированный вектор в файл
        choice = false;
    }
}

