// ConsoleApplication12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class adress
{

public:
    void set_gorod(std::string gorod) { this->gorod=gorod; }
    std::string get_gorod() { return this->gorod; }
    void set_street(std::string street) { this->street=street; }
    std::string get_street() { return this->street; }
    void set_dom(int dom ) { this->dom=dom; }
    int get_dom() { return this->dom; }
    void set_kvartira(int kvartira) { this->kvartira=kvartira; }
    int get_kvartira() { return this->kvartira; }
    adress( )
    {
        this->gorod = "НЕТ";
        this->street = "НЕТ";
        this->dom = 0;
        this->kvartira = 0;

    }


private:
    std::string gorod;
    std::string street;
    int dom;
    int kvartira;
};






int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream fin ("in.txt");
    std::string s;
    int i, kol, vrem;
    if (fin.is_open())
    {
        fin >> s;
        kol = stoi(s);
        //std::cout << "количество строк: " << kol << std::endl;
        adress* adr = new adress[kol];
        for (i = 0; i < kol; i++)
        {
            fin >> s;
            adr[i].set_gorod(s);
           // std::cout << "Город: " << s << std::endl;
            fin >> s;
           // std::cout << "Улица: " << s << std::endl;
            adr[i].set_street(s);
            fin >> s;
           // std::cout << "Дом: " << s << std::endl;
            adr[i].set_dom(stoi(s));
            fin >> s;
           // std::cout << "Квартира: " << s << std::endl;
            adr[i].set_kvartira(stoi(s));
        }// for (i = 0; i < kol; i++)

        fin.close();
        std::ofstream fout("out.txt");
        fout << kol << std::endl;
        for (i = kol-1; i >= 0; i--)
        {
            s=adr[i].get_gorod();
            fout << s;
           // std::cout << "Город: " << s << std::endl;
            fout << ", ";
            s = adr[i].get_street();
            fout << s;
           // std::cout << "Улица: " << s << std::endl;
            fout << ", ";
            vrem=adr[i].get_dom();
            fout << vrem;
           // std::cout << "Дом: " <<vrem << std::endl;
            fout << ", ";
            vrem=adr[i].get_kvartira();
            fout << vrem;
           // std::cout << "Квартира: " << vrem << std::endl;
            fout << std::endl;

         }
        
        fout.close();
        delete [] adr;
    }
    else
    {
        std::cout << "Не получилось открыть файл! in.txt" << std::endl;
    }

    
}

/* Задача 1. Адреса
В этом задании вы будете читать адреса из файла и выводить их в другой файл в другом формате.

Вам дан файл in.txt, в котором находится N адресов.Число N идёт первым в файле.После числа N располагаются N блоков по 4 строки в каждом.Каждый блок состоит из следующих строк : название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt и вывести их в файл out.txt в другом формате и в обратном порядке.Не забудьте вывести количество адресов в начале.

Формат вывода адреса : <название города>, <название улицы>, <номер дома>, <номер квартиры>.

Пример работы программы
in.txt
3
Москва
Строителей
34
12
Омск
Пушкина
2
13
Новосибирск
Мира
85
64
out.txt
3
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
Москва, Строителей, 34, 12
*/