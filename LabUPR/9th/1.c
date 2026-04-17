#include<stdio.h>
#define DIM 5
void output(int a[]);
int find(int a[],int v,int l,int r);
int main()
{
    int a[DIM]={3,5,8,10,13}; int v,res;
    printf("Masivat za obrabotka e:\n");
    output(a);
    printf("Vavedete tarsen element:");
    scanf("%d",&v);
    res=find(a,v,0,DIM-1);
    if(res!=-1)
        printf("Tarseniat element e na pozicia %d v masiva.\n",res);
    else
        printf("Tarseniat element ne e nameren!\n");
    return 0; }
void output(int a[])
{
    int i;
    for(i=0;i<DIM;i++)
        printf("a[%d]=%d\n",i,a[i]);
}
int find(int a[],int v,int l,int r) {
    int m;
    int count=0;
    while(r >= l) {
        count++;
        m = (l+r)/2;
        if(v == a[m]) return m;
        if(v < a[m]) r = m-1;
        else l = m+1;
    }
    return -1;
}