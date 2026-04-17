#include <stdio.h>

#define MAX 50

// 1. Сума в интервала [10;50]
int sumInterval(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 10 && arr[i] <= 50)
        {
            sum += arr[i];
        }
    }
    return sum;
}

// 2. Брой четни числа
int countEven(int arr[], int n)
{
    int count = 0; // брояч
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// 3. Най-малко число
int findMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

// 4. Елементи с нечетен индекс
void printOddIndex(int arr[], int n)
{
    printf("Elementi s necheten indeks:\n");
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }
}

int main()
{
    int n;
    int arr[MAX];

    // 🔒 Проверка за валиден размер
    do
    {
        printf("Vavedete broi elementi (1-50): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 50);

    // Въвеждане на масива
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // 🔥 Извикване на функциите
    int sum = sumInterval(arr, n);
    int evenCount = countEven(arr, n);
    int min = findMin(arr, n);

    // Резултати
    printf("\n--- Rezultati ---\n");
    printf("Suma v interval [10;50]: %d\n", sum);
    printf("Broi chetni chisla: %d\n", evenCount);
    printf("Nai-malko chislo: %d\n", min);

    printOddIndex(arr, n);

    return 0;
}