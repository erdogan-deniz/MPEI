// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
  setlocale(LC_ALL, "RUS");
  cout << "\t\tЗаменить элементы матрицы, равные нулю, на заданное значение.\n\n";
  
  cout << "Введите количество строк массива:\n";
  int key = 1;
  int n;
  float N;
  char a;

  if (scanf("%f%c", &N, &a) != 2 || a != '\n') {  // Проверка на букву
    cout << "Неверное значение длины массива";
    key = 0;
  }
  else {
    n = N;
    if (n != N || n <= 0) {  //  Проверка на вещественное
      cout << "Неверное значение длины массива";
      key = 0;
    }
    
    int m;
    float M;
    char A;

    if (key != 0) {
      cout << "Введите количество столбцов массива:\n";
      if (scanf("%f%c", &M, &A) != 2 || A != '\n') {  // Проверка на букву
        cout << "Неверное значение длины массива";
        key = 0;
      }
      else {
        m = M;
        if (m != M || m <= 0) {  //  Проверка на вещественное
          cout << "Неверное значение длины массива";
          key = 0;
        }
      }
    }
    
    float value;
    if (key != 0) {
      cout << "Введите значение, которое будет использоваться вместо нуля:\n";
      if (!scanf("%f", &value)) {  // Проверка на букву
        cout << "Неверное значение!";
        key = 0;
      }
    }

    float** matrix;
    if (key != 0) {
      matrix = new float* [N];
      for (int i = 0; i < N; i++) {
        matrix[i] = new float[M];
      }

      char Z;
      cout << "Введите элементы массива:\n";

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
          if (key != 0) {
            cout << "Элемент" << " [" << i << "][" << j << "]\n";
          }
          if (key != 0) {
            if (scanf("%f%c", &matrix[i][j], &Z) != 2 || Z != '\n') {  // Проверка на букву
              cout << "Неверное значение элемента массива";
              key = 0;
              break;
            }
          }
        }
      }

      if (key != 0) {
        for (int i = 0; i < N; i++)
          for (int j = 0; j < M; j++)
          {
            if (matrix[i][j] == 0) {
              matrix[i][j] = value;
            }
          }
      }

      if (key != 0) {
        cout << endl;
        cout << "Элементы вашего массива:" << endl;
        for (int i = 0; i < N; i++) { // ввод 
          for (int j = 0; j < M; j++)
          {
            cout << "Элемента массива " << "[" << i << "][" << j << "] = " << matrix[i][j] << endl;
          }
        }
      }

      if (key != 0) {
        for (int i = 0; i < N; i++) { // ввод 
          free(matrix[i]);
        }
        free(matrix);
      }
      cout << endl;
    }
  }
  return 0;
}
