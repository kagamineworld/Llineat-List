#include <stdio.h>
#define MAX 20 /*˳����С*/

typedef struct
{
  int a[MAX];
  int length;
} sequenlist; /*˳���Ķ���*/

int i, b, x;                          /*ȫ�ֱ���������*/
void insert(sequenlist *L, int, int); /*��������*/
void delete (sequenlist *L, int);
int locate(sequenlist *L, int);
void print_array(sequenlist *L);

void main()
{
  sequenlist L; /*����һ��sequenlist����L*/
  printf("please input ��:=?\n");
  scanf("%d", &L.length);            /*�����*/
  printf("please input :s[1..n]\n"); /*�����������ֵ*/
  for (i = 1; i <= L.length; i++)
    scanf("%d", &L.a[i]);
  printf("\n");
  printf("output :s[1..n]\n");
  print_array(&L); /*���n������Ԫ��a[1]..a[n]*/
  printf("\n");
  /*ģ����룬iΪ����Ľ������bΪ������ֵ*/
  printf("��������Ҫ����Ľ��λ�ã�\n");
  scanf("%d", &i);
  printf("������������ֵ��\n");
  scanf("%d", &b);
  printf("insert a[%d]=%d result:\n", i, b);
  insert(&L, i, b); /*�ڵ�i��Ԫ��λ�ò���b*/
  printf("����һ��Ԫ�غ�ı�Ϊ:%d\n", L.length);
  printf("\n");
  /*ģ��ɾ����iΪɾ���Ľ����*/
  printf("��������Ҫɾ���Ľ�㣺\n");
  scanf("%d", &i);
  printf("delete a[%d]=%d result:\n", i, L.a[i]);
  delete (&L, i); /*ɾ����i��Ԫ��a[i]*/
  printf("ɾ��һ��Ԫ�غ�ı�Ϊ:%d\n", L.length);
  printf("\n");
  /*ģ����ң�xΪ���ҵ���ֵ*/
  printf("��������Ҫ���ҵ���ֵ��\n");
  scanf("%d", &x); /*Ҫ���ҵ���*/
  if (locate(&L, x) == 0)
    printf("%d does not exist .\n", x);
  else
    printf("Ԫ��%d�ڱ��е�λ��Ϊ%d\n", x, locate(&L, x)); /*ȷ��x�Ƿ��ڱ���*/
}
/*���뺯���Ķ���*/
void insert(sequenlist *L, int i, int b) /*���뺯��*/
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

void delete (sequenlist *L, int i) /*ɾ������*/
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

int locate(sequenlist *L, int x) /*���Һ���*/
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

void print_array(sequenlist *L) /*���Ԫ��*/
{
  int j;
  for (j = 1; j <= L->length; j++)
    printf("%d ", L->a[j]);
  printf("\n");
}
