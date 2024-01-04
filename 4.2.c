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
void ReplacingNegativeElement(const size_t size, int* array);

/**
* @brief фунция подставляет число К после всех элементов, кратных своему номеру
* @param k - ввод числа k для задания 2
*/
int GetK();

/**
* @brief фунция подставляет число К после всех элементов, кратных своему номеру
* @param size - размер массива
* @param a -  массив
*/
size_t ValueK(size_t size, int* array, int* count);

/**
* @brief подсичтывает количество элементов в массиве
* @param count - переменная в которую записывает сколько элементов в массиве
*/

int GetCount(const size_t size, int* array);

/**
* @brief функция печатает массив
* @param size - размер массива
* @param a -  массив
*/
void PrintArray(const int* array, const size_t size);

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
int* GetNewArray(int* array, const size_t size);

/**
* @brief функция для заполнения массива в ручную
* @param size - размер массива
* @param a -  массив
*/
void FillArray(int* array, const size_t size);

/**
* @brief функция для заполнения массива в рандомными числами
* @param size - размер массива
* @param a -  массив
*/
void FillArrayRandom(int* array, const size_t size);

/**
* @brief функция очищает массив
* @param a -  массив
*/
void FreeArray(int* array);

/**
* @brief функция копирует массив
* @param resultArray - копия массива
* @param size - размер массива
* @param a -  массив
*/
int* GetCpyArray(const size_t size, const int* const array);

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
    int* array = GetArray(size);

    enum Manual inputs = (enum Manual)GetInt("Enter choice: ");
    switch (inputs)
    {
    case random:
        FillArrayRandom(array, size);
        break;
    case enter:
        FillArray(array, size);
        break;
    default:
        puts("Incorrect input.\n");
        return 1;
        break;
    }

    PrintArray(array, size);
    puts("Task 1:");
    int* secondArray = GetCpyArray(size, array);
    ReplacingNegativeElement(size, secondArray);
    PrintArray(secondArray, size);
    FreeArray(secondArray);
    puts("Task 2:");
    int k = GetK();
    int* thirdArray = GetCpyArray(size, array);
    size_t size3 = ValueK(size, thirdArray, k);
    PrintArray(thirdArray, size3);
    puts("\nTask 3:");
    int* fourthArray = GetCpyArray(size, array);
    PrintArray(fourthArray, size);
    GetNewArray(fourthArray, size);
    PrintArray(fourthArray, size);
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
    int* array = malloc(size * sizeof(int));

    if (NULL == array)
    {
        errno = ENOMEM;
        perror("Error :");
        abort();
    }

    return array;
}

void FillArray(int* array, const size_t size)
{
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        array[i] = GetInt("Input element = ");
    }
}
void FillArrayRandom(int* array, const size_t size)
{
    srand(time(NULL));
    puts("Enter array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % 200 - 100; 
    }
}

void PrintArray(const  int* array, const size_t size)
{
    puts("Array elements: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("Element %zu = %d\n", i, array[i]);
    }
}

int* GetCpyArray(const size_t size, const int* const array)
{
    int* resultArray = GetArray(size);
    for (size_t i = 0; i < size; i++)
    {
        resultArray[i] = array[i];
    }

    return resultArray;
}

void ReplacingNegativeElement(const size_t size, int* array)
{
    for (size_t i = 0; i < size; i++) {
        if (array[i] < 0) {
            array[i] = 0;
            break;
        }
    }
}

int GetCount(const size_t size, int* array)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        count++;
    }
    return count;
}

int GetK()
{
    int k = GetInt("Enter array elements:");
    return k;
}

size_t ValueK(size_t size, int* array, int k)
{
    int addedItems = 0;
    for (int i = 0; i < size + addedItems; i++) {
        if (array[i] % (i - addedItems + 1) == 0) {
            for (int j = size + addedItems; j > i + 1; j--) {
                array[j] = array[j - 1];
            }
            array[i + 1] = k;
            i++; 
            addedItems++;
        }
    }
    return size + addedItems;
}

int* GetNewArray( int* array, const size_t size)
{
    int* NewArray = GetArray(size);
    for (size_t i = 1; i < size; i++)
    {
        if ((i % 2) != 0)
        {
            array[i] = (i - 1) * array[i];
        }
        else
        {
            array[i] = array[i] * i * 2;
        }
    }
    return array;
}
void FreeArray(int** array)
{
    if (NULL != array)
    {
        free(array);
        array = NULL;
    }
}