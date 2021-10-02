
//   2020-1025开始
/* C语言笔记当然要用.c 格式了
#以后每个笔记都用这种注释吧
*/
#include <stdio.h>
//! 1----------------------运算符><和=
/*
int main()
{
    int x=12,y=10;
    y=x>12;
    printf("y=%d\n",y);
    printf("x=%d\n",x);
    return 0;
}
*/
// y=0,x=12
//!><高于=
//! 2------------__?__:__语句
/*
int main()
{
    int x=12,y=10;
    y=x>12?x+1:x-1;
    printf("y=%d\n",y);
    printf("x=%d\n",x);

return 0;
}
*/
// y=11,x=12
//!该语句优先级低于><高于=
//! 3--------------自增自减优先级
/*
int main()
{
    int m,x=4,y=-2,z=5;
    m=++x-y+z++;
    printf("y=%d\n",y);
    printf("x=%d\n",x);
    printf("z=%d\n",z);
    printf("m=%d\n",m);
return 0;
}
*/
// y=-2,x=5,z=6,m=12，注意z++是之前的值
//!自增自减高于+-
//还是独立有感觉
//。。。
// 20201025