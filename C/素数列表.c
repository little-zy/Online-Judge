#include<stdio.h>
#include <math.h>
#define N 50
int main()
{
  long int a[N]={2,2,3},m=2;
  int i,j;
  int n;
  for(i=1;i<N;i++)
  {	
    n=(int)sqrt((double)m)+1;//todo 注意sqrt函数原型，double 和double ，而且不能单步调试？这次是设了只隔一行的夹断点
    for(j=1;j<i&&a[j]<=n;j++)
    {	
      if(m%a[j]==0)
      {
        m++;
        n=(int)sqrt((double)m)+1;
        j=0;//!for循环的i++：作用于每一次循环结束后
/* i的妙用：是不是还能实现continue+break的双功能？？ */
      }
    }
    a[i]=m;
    m++;
  }
  scanf("%d",&j);
  for(i=0;i<j;i++)
  {	
    scanf("%ld",&m);
    printf("%ld\n",a[m]);
  }
  return 0;
}