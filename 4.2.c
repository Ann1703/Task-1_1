#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief считывает и проверяет ввод переменной типа int
* @return Возвращает считанное значение
*/
int GetInt(const char* const message);

/**
* @brief функция заменяет первый отрицательный элемент массива нулем.
* @param size - размер массива
* @param a -  массив
*/
void ReplacingNegativeElement(const size_t size, int* a);

/**
* @brief фунция подставляет число К после всех элементов, кратных своему номеру
* @param size - размер массива
* @param a -  массив
* @return возвращает итоговый массив
*/
void ValueK(const size_t size, int* a);

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
* @brief функция для 3 пукнта задания
* @param size - размер массива
* @param a -  массив
* @param d - новый массив
* @return возвращает новый массив
*/
int* GetNewArray(int* a, const size_t size);

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
int* GetCpyArray(const size_t size, const int* const a);
/**
* @brief функция для определения размера массива
* @return возвращает размер массива
*/
size_t GetArraySize();

/**
* @brief Выбор заполнения массива.
*/
enum Manual
{
    random = 1,
    enter = 2,
};

int main()
{
    size_t size = GetArraySize();
    int* a = GetArray(size);
    enum Manual inputs = (enum Manual)GetInt("Enter choice: ");
    switch (inputs)
    {
    case random:
        FillArrayRand(a, size);
        break;
    case enter:
        FillArray(a, size);
        break;
    default:
        puts("Incorrect input.\n");
        return 1;
       
    }
    PrintArray(a, size);
    puts("Task 1:");
    int* secondArray = GetCpyArray(size, a);
    int* thirdArray = GetCpyArray(size, a);
    int* fourthArray = GetCpyArray(size, a);
     
    ReplacingNegativeElement(size, secondArray);
    PrintArray(secondArray, size);
    FreeArray(secondArray);
    puts("Task 2:");
    PrintArray(thirdArray, size);
    ValueK(size, thirdArray);
    puts("\nTask 3:");
    PrintArray(fourthArray, size);
    PrintArray(GetNewArray(*a, size),size);
    FreeArray(fourthArray);
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

int* GetArray(const size_t size)
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

void FillArray(int* a, const size_t size)
{
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        a[i] = GetInt("Input element = ");
    }
}
void FillArrayRand(int* a, const size_t size)
{
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        a[i] = rand() % 200 - 100; // диапазон случайных чисел от -100 до 100
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

int* GetCpyArray(const size_t size, const int* const a)
{
    int* resultArray = GetArray(size);
    for (size_t i = 0; i < size; i++)
    {
        resultArray[i] = a[i];
    }

    return resultArray;
}

void ReplacingNegativeElement(const size_t size, int* a)
{
    for (size_t i = 0; i < size; i++) {
        if (a[i] < 0) {
            a[i] = 0;
            break;
        }
    }
}


void ValueK(const size_t size, int* a)
{
    int k = GetInt("Enter array elements:");
    int m = 0;
    size_t i;
    int j;
    for (i = 0; i <= size; i++)
    {
        if ((a[i] % (i + 1)) == 0)
        {
            for (j = size + m; j > i + 1; j--)
            {
                a[j] = a[j - 1];
            }
            a[i + 1] = k;
            m += 1;
        }
    }
    for (size_t i = 0; i < size + m; i++)
    {
        printf_s("%d  ", a[i]);
    }

    return 0;
}

int* GetNewArray(int* a, const size_t size)
{
    int* d = GetArray(size);
    for (size_t i = 0; i < size; i++)
    {
        if ((i % 2) == 0)
        {
            d[i] = (i - 1) * a[i];
        }
        else
        {
            d[i] = a[i] * i * 2;
        }
        return d[i];
    }
    
}

void FreeArray(int** a)
{
    if (NULL != a)
    {
        free(a);
        a = NULL;
    }
}