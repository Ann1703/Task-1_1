#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief считывает и проверяет ввод переменной типа int
* @return Возвращает считанное значение
*/
int get_int(const char* message);

/**
* @brief функция для определения размера массива
* @return возвращает размер массива
*/
size_t get_size_t(const char* message);

/**
* @brief функция для создания массива
* @param size - размер массива
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
*/
int** get_array(const size_t rows, const size_t columns);

/**
* @brief Функция для обработки ошибки выделения памяти
*/
void array_null();

/**
* @brief Функция для заполнения массива в ручную
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
* @param MinEnterval -  минимальное значение интервала для генерации чисел
* @param MaxEnterval -  максимальное значение интервала для генерации чисел
*/
void fill_array(int** const array, const size_t rows, const size_t columns);

/**
* @brief функция для заполнения массива в рандомными числами
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
* @param MinEnterval -  минимальное значение интервала для генерации чисел
* @param MaxEnterval -  максимальное значение интервала для генерации чисел
*/
void fill_array_random(int** const array, const size_t rows, const size_t columns);
/**
* @brief функция печатает массив
* @param size - размер массива
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
*/
void show_array(int** const array, const size_t rows, const size_t columns);

/**
* @brief функция вставляет после всех столбцов, содержащих максимальный элемент столбец из нулей
* @param rows -  строка массива
* @param columns -  столбец массива
* @param maxColumn -  максимальное значение матрицы
*/
int* second_task(int** control_array, size_t rows, size_t cols);

/**
* @brief функция копирует массив
* @param array_copy - копия массива
* @param rows -  строка массива
* @param columns -  столбец массива
* @param array_original -  массив
*/
int** copy_array(int** const array_original, const size_t rows, const size_t columns);

/**
* @brief функция заменяет максимальный элемент каждой строки на противоположный по знаку
* @param rows -  строка массива
* @param columns -  столбец массива
* @param array_original -  массив
*/
int** replace_array(int** myarray, const size_t rows, const size_t columns);

/**
* @brief функция ищет максимальный элемент в каждой строке
* @param rows -  строка массива
* @param columns -  столбец массива
* @param array_original -  массив
*/
int FindMax(int** const array_original, const size_t rows, const size_t columns);

/**
* @brief функция ищет максимальный элемент в каждой строке
* @param rows -  строка массива
* @param columns -  столбец массива
* @param array_original -  массив
*/
int* FindMaxArray(int** const array_original, const size_t rows, const size_t columns);

/**
* @brief Функция для освобождения памяти, выделенной под массив
* @param rows -  строка массива
* @param array -  массив
*/
void free_array(int** array, size_t rows);

/**
* @brief Выбор заполнения массива.
*/
enum Manual
{
    random = 1,
    enter = 2,
};

int main(void)
{
    const size_t rows = get_size_t("Input rows: ");
    const size_t columns = get_size_t("Input columns: ");
    int** origin_array = get_array(rows, columns);

    enum Manual inputs = (enum Manual)get_int("Enter choice: ");
    switch (inputs)
    {
    case random:
        fill_array_random(origin_array, rows, columns);
        break;
    case enter:
        fill_array(origin_array, rows, columns);
        break;
    default:
        puts("Incorrect input.\n");
        return 1;
        break;
    }

    show_array(origin_array, rows, columns);
    puts("Task1\n");
    int** secondArray = replace_array(origin_array, rows, columns);
    show_array(secondArray, rows, columns);
    free_array(secondArray, rows);

    puts("Task2");
    int** task_2_array = second_task(origin_array, rows, columns);

    show_array(task_2_array, rows, columns + 1);

    free_array(origin_array, rows);
    return 0;
}

int get_int(const char* message)
{
    puts(message);
    int number;
    if (scanf_s
    ("%d", &number) != 1)
    {
        errno = EIO;
        perror("Inserted a wrong value\n");
        abort();
    }
    return number;
}

size_t get_size_t(const char* message)
{
    int number = get_int(message);
    if (number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)number;
}

void array_null()
{
    errno = ENOMEM;
    perror("Error: ");
    abort();
}

int** get_array(const size_t rows, const size_t columns)
{
    int** array = (int**)malloc(rows * sizeof(int*));
    if (NULL == array)
    {
        array_null();
    }

    for (size_t i = 0; i < rows; i++)
    {
        array[i] = (int*)malloc(columns * sizeof(int));
        if (NULL == array[i])
        {
            array_null();
        }
    }
    return array;
}

void fill_array(int** const array, const size_t rows, const size_t columns)
{
    puts("Insert array elements:\n");
    int MinEnterval = get_int("Enter the beginning of the interval: ");
    int MaxEnterval = get_int("Enter the end of the interval : ");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (MinEnterval > -101 && MaxEnterval < 101) 
            {
                array[i][j] = get_int("Get element");
            }
            else
            {
                puts("The entered value does not satisfy the condition!");
                abort();
            }
        }
    }
}

void fill_array_random(int** const array, const size_t rows, const size_t columns)
{
    puts("Insert array elements:\n");
    int MinEnterval = get_int("Enter the beginning of the interval: ");
    int MaxEnterval = get_int("Enter the end of the interval : ");
    srand(time(NULL));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (MinEnterval > -101 && MaxEnterval < 101) {
                array[i][j] = MinEnterval + rand() % (MaxEnterval - MinEnterval + 1);
            }
            else
            {
                puts("The entered value does not satisfy the condition!");
                abort();
            }
        }
    }
}

void show_array(int** const array, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf_s(" %d ", array[i][j]);
        }
        printf("\n");
    }
    puts("\n");
}

void free_array(int** array, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        if (NULL != array[i])
        {
            free(array[i]);
        }
    }
    if (NULL != array)
    {
        free(array);
    }
}

int** copy_array(int** const array_original, const size_t rows, const size_t columns)
{
    int** array_copy = get_array(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array_copy[i][j] = array_original[i][j];
        }
    }
    return array_copy;
}

int** replace_array(int** myarray, const size_t rows, const size_t columns)
{
    int** newarray = copy_array(myarray, rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        int max = FindMax(newarray, i, columns);
        for (size_t j = 0; j < columns; j++)
        {
            if (newarray[i][j] == max)
            {
                newarray[i][j] *= -1;
            }
        }
    }
    return newarray;
}
int* second_task(int** control_array, size_t rows, size_t columns)
{
    int** newarray2 = copy_array(control_array, rows, columns);
    int maxColumn = FindMaxArray(newarray2, rows, columns);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = columns; j > maxColumn; j--)
        {
            newarray2[i][j] = newarray2[i][j - 1];
        }
        newarray2[i][maxColumn + 1] = 0;
    }
    return newarray2;
}

int FindMax(int** const array_original, const size_t rows, const size_t columns)
{
    int max = array_original[rows][0];
    for (size_t j = 1; j < columns; j++)
    {
        if (array_original[rows][j] > max)
        {
            max = array_original[rows][j];
        }
    }
    return max;
}

int* FindMaxArray(int** array_original, const size_t rows, const size_t columns)
{
    int maxElement = array_original[0][0];
    int maxColumn = 0;
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (array_original[i][j] > maxElement)
            {
                maxElement = array_original[i][j];
                maxColumn = j;
            }
        }
    }
    return maxColumn;
}




