
#include "func.hpp"
int main() {
    generate(); //генерируем данные и записываем в файл
    vector<ITservice> vec;
    write_to_vector(vec);//данные из фала записываем в вектор

    string choice = "";
    while (choice != "1" && choice != "2" && choice != "3"){ //проверка на корректный ввод
        cout << "|Choose option, please|" << endl << "1 - buble sort - 1" << endl << \
        "2 - insert sort - 2" << endl << "3 - both - 3" << endl;
        cin >> choice;
        
    }
    switch (stoi(choice)) {
        case 1:
            buble_sort(vec);
            break;
        case 2:
            insert_sort(vec);
            break;
        case 3:
            insert_sort(vec);
            buble_sort(vec);
        default:
            break;
    }
    return 0;
}
