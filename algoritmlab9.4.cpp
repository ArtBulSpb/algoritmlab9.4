//Самые лучшие объяснения здесь: https://informatics.msk.ru/mod/book/view.php?id=579

#include <iostream>
#include <cstdlib> 
#include <string> // подключаем строки
#include <fstream> // подключаем файлы

#define N 300



using namespace std;



int main()
{
    int counter = 0;
    setlocale(LC_ALL, "rus");
    string str; // сюда будем класть считанные знаки из файла
    char file_data[N];
    int s = 0, k = 0, n = 0;
    n = N;

    const char* ar[] = { "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С",
        "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ь", "Ы", "Ъ", "Э", "Ю", "Я", ":", ",", "-", ".", " "};
    int repetition_rate[38] = {};

    // Делаем рандом для рандомайзера
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
        {
            file_data[i] = *ar[rand()%37];
            cout << file_data[i];
            if (i % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; };
            //Заполнили массив с логикой true - означает не повторяюшиеся элементы. На этом этапе проверки на уникальность нет, заполняем всё true
        };

   ofstream file_f("d:\\1\\rushentext.txt");
    if (!file_f) 
    {
        cout << "29 строка файл не открыт";
    }
    else
    {
        cout << "Заполняем файл a[i]" << endl;
        
        file_f << file_data;
    };

    file_f.close();


    ifstream file;

    //открываем файл в режиме чтения
    file.open("d:\\1\\rushentext.txt");
    //если открытие файла прошло корректно, то
    if (file)
    {
        cout << "\nВыводим элементы массива после чтения их из файла и записи в массив" << endl; // выводим на экран
        while (file >> str) {//getline(file, str)) { // пока не достигнут конец файла класть очередную строку в переменную (str)
            
        }
        

        file.close(); // обязательно закрываем файл что бы не повредить его

    }
    else cout << " Файл не существует" << endl;

        for (int i = 0; i < 37; i++)
        {
            for (int j = 0; j < N;j++) 
            {
                //cout << "85 line" << str[j];
                if (str[j] == *ar[i]) {
                    repetition_rate[i]++;
                }
            }
            cout << ar[i]<<  " = " << repetition_rate[i] << endl;
            counter += repetition_rate[i];
            //Если элемент в массиве логики = true, значит он уникальный и мы его записываем в файл g, иначе пропускаем.
            
        }
        double rezult[38];
        for (int i = 0; i < 37; i++) 
        {
            rezult[i] = (double)repetition_rate[i] / counter;
            cout << "Частота повторения \t" << ar[i] << " =\t";
            printf("%.2f", rezult[i] * 100);
            cout<< "%" << endl;
        }
   
    cout << endl << endl;

    system("pause");
    return 0;

}