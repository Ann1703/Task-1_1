//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>
/**
* @brief ��������� � ��������� ���� ���������� ���� int
* @return ���������� ��������� ��������
*/
int GetInt(const char* const message);

/**
* @brief ������� �������� ������ ������������� ������� ������� �����.
* @param size - ������ �������
* @param a -  ������
*/
void ReplacingNegativeElement(const size_t size, int* a);



/**
* @brief ������ ����������� ����� � ����� ���� ���������, ������� ������ ������
* @param x- ����� ��� ��������� ���� �������� ���������.
* @param size - ������ �������
* @param a -  ������
* @return ���������� �������
*/
void ValueK(const size_t size, int* a);

/**
* @brief ������� �������� ������
* @param size - ������ �������
* @param a -  ������
*/
void PrintArray(int* a, const size_t size);

/**
* @brief ������� ��� �������� �������
* @param � - �������� �������
* @param size - ������ �������
* @return ���������� ������
*/
int* GetArray(const size_t size);
/**
* @brief ������� ��� 3 ������ �������
* @param size - ������ �������
* @param a -  ������
* @param d - ����� ������
* @return ���������� ����� ������
*/
void GetNewArray(int* a, const size_t size);

/**
* @brief ������� ��� ���������� ������� � ������
* @param size - ������ �������
* @param a -  ������
*/
void FillArray(int* a, const size_t size);
/**
* @brief ������� ��� ���������� ������� � ���������� �������
* @param size - ������ �������
* @param a -  ������
*/
void FillArrayRand(int* a, const size_t size);
/**
* @brief ������� ������� ������
* @param a -  ������
*/
void FreeArray(int* a);
/**
* @brief ������� �������� ������
* @param resultArray - ����� �������
* @param size - ������ �������
* @param a -  ������
*/
int* getCpyArray(const size_t size, const int* const a);
/**
* @brief ������� ��� ����������� ������� �������
* @return ���������� ������ �������
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
    enum Case inputs = (enum Case)GetInt("Enter choice: ");
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
        break;
    }
    PrintArray(a, size);
    puts("Task 1:");
    int* secondArray = getCpyArray(size, a);
    int* thirdArray = getCpyArray(size, a);
    int* fourthArray = getCpyArray(size, a);
    ReplacingNegativeElement(size, secondArray);
    PrintArray(secondArray, size);
    FreeArray(secondArray);
    puts("Task 2:");
    PrintArray(thirdArray, size);
    ValueK(size, thirdArray);
    puts("\nTask 3:");
    PrintArray(fourthArray, size);
    GetNewArray(size, fourthArray);
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
        a[i] = rand() % 200 - 100; // �������� ��������� ����� �� -100 �� 100
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

int* getCpyArray(const size_t size, const int* const a)
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


void GetNewArray( const size_t size,int* a, size_t size_of_d)
{
    int* d = (int*)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        if ((i % 2) == 0)
        {
            d[i] = (i-1)*a[i];
        }
        else
        {
           d[i] = a[i] * i*2;
        }
    }
    for (size_t i = 0; i < size ; i++)
    {
        printf_s("%d ", d[i]);
    }
    return 0;
}
void FreeArray(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}