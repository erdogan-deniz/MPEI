#include <iostream>  // Подключение стандартной библиотеки

void InputInt(int*);  // Прототип функции ввода значений

using namespace std;  // Использование стандартного пространства имён

class Complex  // Описание класса комплексных чисел
{
  public:
    Complex()  // Конструктор без параметров
    {
      cout << "Был создан представитель отцовского класса" << endl;
    }
    int a, b;  // Поля класса
    void Input();  // Функция ввода значений
    void Sum();  // Функция суммы
    void Div();  // Функция разности
};

void Complex::Input()  // Описание функции ввода
{
  cout << "Введите действительную часть числа";
  cout << endl;
  InputInt(&a);
  cout << "Введите мнимую часть числа"; cout << endl;
  InputInt(&b);
  cout << endl; cout << "Число равно: ";
  cout << a << "+i*" << b; cout << endl;
}

void Complex::Sum()  // Описание функции суммы
{
  int t = 0, d = 0, x = 0, z = 0;
  cout << "Введите действительную часть первого числа";
  cout << endl;
  InputInt(&t);
  cout << "Введите мнимую часть первого числа"; cout << endl;
  InputInt(&d);
  cout << endl;
  cout << "Введите действительную часть второго числа";
  cout << endl;
  InputInt(&x);
  cout << "Введите мнимую часть второго числа"; cout << endl;
  InputInt(&z);
  a = (t + x);
  b = (d + z);
  cout << "Сумма равна";
  cout << endl;
  cout << a << "+i*" << b; cout << endl;
}

class Son : public Complex  // Описание дочерного класса 
{
  public:
    Son()  // Конструктор без параметров
    {
      cout << "Был создан представитель дочерного класса" << endl;
    }
    void Mult()  // Функция умножения
    {
      int t = 0, d = 0, x = 0, z = 0;
      cout << "Введите действительную часть первого числа";
      cout << endl;
      InputInt(&t);
      cout << "Введите мнимую часть первого числа"; cout << endl;
      InputInt(&d);
      cout << endl;
      cout << "Введите действительную часть второго числа";
      cout << endl;
      InputInt(&x);
      cout << "Введите мнимую часть второго числа"; cout << endl;
      InputInt(&z);
      a = (t * x - d * z);
      b = (t * z + d * x);
      cout << "При умножении число равно"; cout << endl;
      cout << a << "+i*" << b; cout << endl;
    }
};

void Complex::Div()  // Описание функции разности
{
  int t = 0, d = 0, x = 0, z = 0;
  cout << "Введите действительную часть первого числа";
  cout << endl;
  InputInt(&t);
  cout << "Введите мнимую часть первого числа"; cout << endl;
  InputInt(&d);
  cout << endl;
  cout << "Введите действительную часть второго числа";
  cout << endl;
  InputInt(&x);
  cout << "Введите мнимую часть второго числа"; cout << endl;
  InputInt(&z);
  a = (t - x);
  b = (d - z);
  cout << "При вычитании число равно"; cout << endl;
  cout << a << "+i*" << b; cout << endl;
}

int main(void)
{
  setlocale(LC_ALL, "Russian");  // Подключение русского языка в консоли
  Son c;  // Представитель сына
  int v = 1;  // Ключ для меню
 
  while (v != 0)  // Меню
  {
    cout << endl;
    cout << "1-Ввод числа"; cout << endl;
    cout << "2-Сложение чисел"; cout << endl;
    cout << "3-Умножение чисел"; cout << endl;
    cout << "4-Вычитание чисел"; cout << endl;
    cout << "0-Выход"; cout << endl;
    InputInt(&v);
    if (v == 1)
    {
      c.Input();
    }
    if (v == 2)
    {
      c.Sum();
    }
    if (v == 3)
    {
      c.Mult();
    }
    if (v == 4)
    {
      c.Div();
    }
  }
  return 0;
}

void InputInt(int* tmp)  // Описание функции ввода чисел
{
  while (!(cin >> *tmp) || (cin.peek() != '\n'))
  {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Incorrect input!" << endl;
  }
}
