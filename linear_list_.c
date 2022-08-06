#include <stdio.h>
#define MAX 20 /*顺序表大小*/

typedef struct
{
  int a[MAX];
  int length;
} sequenlist; /*顺序表的定义*/

int i, b, x;                          /*全局变量的申明*/
void insert(sequenlist *L, int, int); /*函数声明*/
void delete (sequenlist *L, int);
int locate(sequenlist *L, int);
void print_array(sequenlist *L);

void main()
{
  sequenlist L; /*声明一个sequenlist变量L*/
  printf("please input 表长:=?\n");
  scanf("%d", &L.length);            /*输入表长*/
  printf("please input :s[1..n]\n"); /*向表中输入数值*/
  for (i = 1; i <= L.length; i++)
    scanf("%d", &L.a[i]);
  printf("\n");
  printf("output :s[1..n]\n");
  print_array(&L); /*输出n个数组元素a[1]..a[n]*/
  printf("\n");
  /*模拟插入，i为插入的结点数，b为插入数值*/
  printf("请输入需要插入的结点位置：\n");
  scanf("%d", &i);
  printf("请输入插入的数值：\n");
  scanf("%d", &b);
  printf("insert a[%d]=%d result:\n", i, b);
  insert(&L, i, b); /*在第i个元素位置插入b*/
  printf("插入一个元素后的表长为:%d\n", L.length);
  printf("\n");
  /*模拟删除，i为删除的结点数*/
  printf("请输入需要删除的结点：\n");
  scanf("%d", &i);
  printf("delete a[%d]=%d result:\n", i, L.a[i]);
  delete (&L, i); /*删除第i个元素a[i]*/
  printf("删除一个元素后的表长为:%d\n", L.length);
  printf("\n");
  /*模拟查找，x为查找的数值*/
  printf("请输入需要查找的数值：\n");
  scanf("%d", &x); /*要查找的数*/
  if (locate(&L, x) == 0)
    printf("%d does not exist .\n", x);
  else
    printf("元素%d在表中的位置为%d\n", x, locate(&L, x)); /*确定x是否在表中*/
}
/*插入函数的定义*/
void insert(sequenlist *L, int i, int b) /*插入函数*/
{
  int j;
  if ((i < 1) || (i > L->length + 1))
    printf("position does not exist .\n");
  else
  {
    for (j = L->length; j >= i; j--)
      L->a[j + 1] = L->a[j];
    L->a[i] = b;
    L->length++;
  }
  print_array(L);
}

void delete (sequenlist *L, int i) /*删除函数*/
{
  int j;
  if ((i < 1) || (i > L->length))
    printf("position does not exist\n");
  else
  {
    for (j = i + 1; j <= L->length; j++)
      L->a[j - 1] = L->a[j];
    L->length--;
  }
  print_array(L);
}

int locate(sequenlist *L, int x) /*查找函数*/
{
  int i;
  i = 1;
  while ((i < L->length) && (L->a[i] != x))
    i++;
  if (L->a[i] == x)
    return i;
  else
    return 0;
}

void print_array(sequenlist *L) /*输出元素*/
{
  int j;
  for (j = 1; j <= L->length; j++)
    printf("%d ", L->a[j]);
  printf("\n");
}
