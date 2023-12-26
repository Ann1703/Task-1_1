#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <stdbool.h>


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
* @brief Функция для проверки четности
*/
bool is_even(size_t number);

/**
* @brief Функция для заполнения массива в ручную
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
*/
void fill_array(int** const array, const size_t rows, const size_t columns);

/**
* @brief функция для заполнения массива в рандомными числами
* @param array -  массив
* @param rows -  строка массива
* @param columns -  столбец массива
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
* @param top_row - переменная для вставки 0 в строку
* @param top_сol -  переменная для вставки 0 в столбец
* @param rows -  строка массива
* @param columns -  столбец массива
*/
void second_task(int** control_array, int** array, size_t rows, size_t cols);

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
void replace_array(int** const array, const size_t rows, const size_t columns);

/**
* @brief функция ищет максимальный элемент в каждой строке
* @param rows -  строка массива
* @param columns -  столбец массива
* @param array_original -  массив
*/
int FindMax(int** const array_original, const size_t rows, const size_t columns);

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
        fill_array_random(origin_array, rows,columns);
        break;
    case enter:
        fill_array(origin_array, rows,columns);
        break;
    default:
        puts("Incorrect input.\n");
        return 1;

    }

    
    show_array(origin_array, rows, columns);
    puts("Task1\n");
    int** secondArray = copy_array(origin_array,rows,columns);
    replace_array(secondArray, rows, columns);
    show_array(secondArray, rows,columns);
    free_array(secondArray, rows);

    puts("Task2");
    int** task_2_array = get_array(rows, columns * 2);
    second_task(origin_array, task_2_array, rows, columns * 2);
    show_array(task_2_array, rows, columns * 2);
    
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

void second_task(int** control_array, int** array, size_t rows, size_t columns)
{
    size_t top_row = 0, top_col = 0;
    for (size_t i = 0; i < columns; i++)
    {
        if (is_even(i))
        {
            for (size_t j = 0; j < rows; j++)
            {
                array[j][i] = control_array[top_row][top_col];
                top_row++;
            }
            top_col++;
            top_row = 0;
        }
        else
        {
            for (size_t j = 0; j < rows; j++)
            {
                array[j][i] = 0;
            }
        }
    }
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

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = get_int("Get element");
        }
    }
}
void fill_array_random(int** const array, const size_t rows, const size_t columns)
{
    puts("Insert array elements:\n");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 200 - 100;
        }
    }
}

bool is_even(size_t number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    return false;
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

void replace_array(int** const array, const size_t rows, const size_t columns) 
{
    for (size_t i = 0; i < columns; i++)
    {
        int max = FindMax(array,i,columns);
        array[i][max] *= -1;
    }

}
int FindMax(int** array_original, const size_t rows, const size_t columns)
{
    int max = 0;
    for (size_t j = 0; j < columns; j++)
    {
        if (array_original[rows][j] > array_original[rows][max])
        {
            max = j;
        }
    }
    return max;

}