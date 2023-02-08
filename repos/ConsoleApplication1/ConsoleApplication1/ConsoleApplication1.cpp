#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

int** createMatrix()
{
    int** arr = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[15];
    }
    return arr;
}


int** randomNumbersInMatrix(int** arr)
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            arr[i][j] = rand() % 5 - 2;
        }
    }
    return arr;
}

void writeMatrixToConsole(int** arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << '\n';
    }
}

int findSumOfAllElements(int** arr)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            sum += arr[i][j];
    return sum;
}

int findSumOfMainDiagonal(int** arr)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
            sum += arr[i][i];
    return sum;
}

int countSumInEveryRow(int** arr, int i)
{
    int sum = 0;
    for (int j = 0; j < 15; j++)
        sum += arr[i][j];
    return sum;
}

void sumInEveryRow(int** arr)
{
    for (int i = 0; i < 10; i++)
        cout << "Сумма элементов на " << (i + 1) << " строке = " << countSumInEveryRow(arr, i) << endl;
}

int findSumAboveZeroNumbers(int** arr)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            if (arr[i][j] > 0)
                sum += arr[i][j];
    return sum;
}

int findSumOddNumbers(int** arr)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            if (i + j % 2 == 0)
                sum += arr[i][j];
    return sum;
}

int findSumOfSecondDiagonal(int** arr)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += arr[i][14 - i];
    return sum;
}

int findSumInEveryColumn(int** arr, int j)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += arr[i][j];
    return sum;
}

void sumInEveryColumn(int** arr)
{
    for (int j = 0; j < 15; j++)
        cout << "Сумма элементов столбца " << (j + 1) << " = " << findSumInEveryColumn(arr, j) << endl;
}

int findZeroInMatrix(int** arr)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            if (arr[i][j] == 0)
                count++;
    return count;
}


int findOnesInMatrix(int** arr)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            if (arr[i][j] == 1)
                count++;
    return count;
}

int findMinusOnesInMatrix(int** arr)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            if (arr[i][j] == -1)
                count++;
    return count;
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int** arr = createMatrix();
    arr = randomNumbersInMatrix(arr);
    writeMatrixToConsole(arr);
    cout << "Сумма всех элементов = " << findSumOfAllElements(arr) << endl;
    cout << "Сумма элементов на главной диагонали = " << findSumOfMainDiagonal(arr) << endl;
    sumInEveryRow(arr);
    cout << "Сумма положительных элементов = " << findSumAboveZeroNumbers(arr) << endl;
    cout << "Сумма нечетных элементов = " << findSumOddNumbers(arr) << endl;
    cout << "Сумма элементов на побочной диагонали = " << findSumOfSecondDiagonal(arr) << endl;
    sumInEveryColumn(arr);
    cout << "Количество нулей = " << findZeroInMatrix(arr) << endl;
    cout << "Количество единиц = " << findOnesInMatrix(arr) << endl;
    cout << "Количество минус единиц = " << findMinusOnesInMatrix(arr) << endl;
}