#include <stdio.h>
int sum (int a, int b, int c); //деклариране на функция sum
int biggestNum (int a,int b,int c); //деклариране на функция sum
int lowestNum (int a,int b,int c); //деклариране на функция sum
int average (int a,int b,int c); //деклариране на функция sum
int main () // главна функция на програмата
 {
    int a ;
    int b ;
    int c ;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int total;
    total = sum (a,b,c); // извикване на функция sum
    printf ("The sum is : %d\n", total);
    int biggest = biggestNum(a,b,c);
    printf ("The biggest is : %d\n", biggest);
    int lowest = lowestNum(a,b,c);
    printf ("The lowest is : %d\n", lowest);
    int averageNum = average(a,b,c);
    printf ("The average is : %d\n", averageNum);
    return 0;
 }
int sum (int a, int b, int c) //дефиниция на функция
{
    int s;
    s=a+b+c;
    return s;
}
int biggestNum(int a, int b, int c) {
    int s = 0;
    int myNumbers[] = {a,b,c};
    int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    for (int i=0;i<length; i++) {
        if (myNumbers[i]>s) {
            s=myNumbers[i];
        }
    }
    return s;
}

int lowestNum(int a, int b, int c) {
    int myNumbers[] = {a,b,c};;
    int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    int s = myNumbers[0];
    for (int i;i<length; i++) {
        if (myNumbers[i]<s) {
            s=myNumbers[i];
        }
    }
    return s;
}
int average(int a, int b, int c) {
    int myNumbers[] = {a,b,c};;
    int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    int s =0;
    for (int i; i<length; i++) {
        s+=myNumbers[i];
    }
    return s/length;
}