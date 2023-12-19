//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>
/**
* @brief считывает и проверяет ввод переменной типа int
* @return Возвращает считанное значение
*/
int GetInt(const char* const message);

/**
* @brief функция вывод значения элементов массива с противоположным знаком
* @param size - размер массива
* @param a -  массив
*/
void OpposiveValue(const size_t size, int* a);

/**
* @brief выводит индексы тех элементов, значения которых кратны 3
* @param size - размер массива
* @param a -  массив
*/
void Multiplicity(const size_t size, int* a);

/**
* @brief фунция определяет, есть ли пара соседних элементов с суммой, равной заданному числу.
* @param x- число для сравнения пары соседних элементов.
* @param size - размер массива
* @param a -  массив
*/
int SumValue(const size_t size, int* a);

/**
* @brief функция печатает массив
* @param size - размер массива
* @param a -  массив
*/
void PrintArray(int* a, const size_t size);

/**
* @brief функция для создания массива
* @param а - название массива
* @param size - размер массива
* @return возвращает массив
*/
int* GetArray(const size_t size);

/**
* @brief функция для заполнения массива в ручную
* @param size - размер массива
* @param a -  массив
*/
void FillArray(int* a, const size_t size);
/**
* @brief функция для заполнения массива в рандомными числами
* @param size - размер массива
* @param a -  массив
*/
void FillArrayRand(int* a, const size_t size);
/**
* @brief функция очищает массив
* @param a -  массив
*/
void FreeArray(int* a);
/**
* @brief функция копирует массив
* @param resultArray - копия массива
* @param size - размер массива
* @param a -  массив
*/
int* getCpyArray(const size_t size, int* a);
/**
* @brief функция для определения размера массива
* @return возвращает размер массива
*/
size_t GetArraySize();

enum Case
{
    random = 1,
    enter = 2,
};

int main()
{ 
    size_t size = GetArraySize();  
    int* a = GetArray(size);
    enum Case inputs = (enum Case) GetInt("Enter choice: ");
    switch (inputs) 
    {
        case random:
            FillArrayRand(a,size);
            break;
        case enter:
            FillArray(a, size);
            break;
        default:
           puts("Incorrect input.\n");
           return 1;
        break; 
    }
    puts("Task 1:");
    int* secondArray = getCpyArray(size, a);
    OpposiveValue(size, secondArray);
    PrintArray(secondArray, size);
    FreeArray(secondArray);
    puts("Task 2:");
    Multiplicity(size, a);
    puts("Task 3:");
    SumValue(size, a);

    FreeArray(a);
    
    return 0;
}


int GetInt(const char* const message)
{
    int value = 0;
    printf("%s", message);
    int result = scanf_s("%d", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Error :");
        abort();
    }
        return value;
}

size_t GetArraySize()
{
    int size = GetInt("Enter size of array: ");
    if (size <= 0)
    {
        errno = ERANGE;
        perror("Error :");
        abort();
    }

    return (size_t)size;
}

int* GetArray( const size_t size)
{
    int* a = malloc(size * sizeof(int));
    if (NULL == a)
    {
        errno = ENOMEM;
        perror("Error :");
        abort();
    }

    return a;
}

void FillArray(int*  a, const size_t size)
{
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        a[i] = GetInt("Input element = ");
    }
}
void FillArrayRand(int*  a, const size_t size)
{
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        a[i] = rand() % 201 - 100; // диапазон случайных чисел от -100 до 100
    }
}

void PrintArray(int* a, const size_t size)
{
    puts("Array elements: ");
    for (size_t i = 0; i < size; i++)
    {
       printf("Element %zu = %d\n", i, a[i]);
    }
 }

int* getCpyArray(const size_t size, int* a)
{
    int* resultArray = GetArray(size);
    for (size_t i = 0; i < size; i++)
    {
        resultArray[i] = a[i];
    }

    return resultArray;
}

void OpposiveValue(const size_t size, int*a )
{ 
#
        for (size_t i = 0; i < size; i++)
        {
            a[i] = -1 * a[i];
        }

}

void Multiplicity(const size_t size, int* a)
{
    
    for (size_t i = 0; i < size; i++) 
    {
        if (a[i] % 3 == 0)
        {
          printf_s("Element_Multiplicity %d\n", i);
        }
    }
}
int SumValue (const size_t size, int* a)
{
    int x = GetInt("Enter array elements:"); 
    printf_s("value %d\n", x);
    
    for (size_t i = 0; i < size - 1; i++)
    {
        if (a[i] + a[i + 1] == x) {
            printf("The sum of the adjacent elements %d and %d is equal to %d\n", a[i], a[i + 1], x);
        }
        else {
            printf("The sum of the adjacent elements % d and %d is not equal %d\n", a[i], a[i + 1], x);
        }
    }
}
void FreeArray(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}