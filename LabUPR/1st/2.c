#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a; // деклариране на цяла променлива
    float b; // деклариране на реална променлива
    char f = 0; // инициализиране на символна променлива
    printf("Enter one symbol:");
    scanf("%c", &f); // четене от клавиатурата
    printf("Enter one integer number:");
    scanf("%d", &a); // четене от клавиатурата
    printf("Enter one float number:");
    scanf("%f", &b); // четене от клавиатурата
    printf("The entered values of variables separated with tabs ");
    printf("are as follows:\n");
    printf("a = %d\tb = %f\tf = %c\n", a, b, f); // извиждане на данни върху монитора
    printf("The entered values of variables separated with tabs are as follows:\n");
    printf("a = %5d\tb = %8.2f\tf = %5c\n", a, b, f);

    return 0;
}
