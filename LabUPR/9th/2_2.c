# include <stdio.h>

void input(float a[100], int n);
void output (float a[100], int n);
void sort(float a[100], int n);
int main()
{
    int n;
    float a[100];
    printf("n=");
    scanf("%d",&n);
    input (a,n) ;
    sort (a,n) ;
    output (a,n) ;
    return 0;
}
void input(float a[100], int n)
{
    int i;
    for(i = 0; i<n;i++)
    {
        printf("a[%d]=",i);scanf("%f",&a[i]);
    }
}
void output (float a[100], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%.2f\t",i,a[i]);
    }
}
void sort(float a[100], int n)
{
    int i, j;
    float x;

    for(i = 1; i < n; i++)
    {
        x = a[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(x > a[j])
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = x;
    }
}