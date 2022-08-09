/*本篇代码中处理使用到的函数是经过修改后可以正常运行外，其他没有使用的函数没有进行修改，不清楚会有什么问题*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node /*定义单链表结构类型*/
{
    int data;
    struct node *next;
} linklist;

int number; /*定义一个全局变量，用来记录结点个数*/

int main() /*主函数*/
{
    linklist *p;
    int x;
    linklist *creatlistf(); /*头插法建表,此为程序使用的函数*/                    /*声明建表函数*/
    linklist *creatlistf2();                                                     /*尾插法建表*/
    linklist *creatlistf2_1();                                                   /*尾插法建表改进，引入头结点，简化版*/
    linklist *locate(linklist * head, int key); /*按值查找，此为程序使用的函数*/ /*声明查找函数*/
    linklist *get(linklist * head, int i);                                       /*按序号查找*/
    void insertafter(linklist * p, int x); /*后插操作，此为程序使用的函数*/      /*声明插入函数*/
    void insertafter1_1(linklist * head, linklist * p, int x);                   /*前插操作*/
    void insertafter1_2(linklist * p, int x);                                    /*前插操作改进*/
    void deleteafter(linklist * p); /*删除运算，此为程序使用的函数*/             /*声明删除函数*/
    void print_linked(linklist * p);                                             /*输出当前的链表*/
    printf("开始创建单链表！\n");
    p = creatlistf();
    print_linked(p);
    printf("\n");
    printf("插入一个数到列表当中,请输入需要插入的数的值\n");
    scanf("%d", &x);
    insertafter(p, x);
    print_linked(p);
    printf("\n");
    printf("开始查找一个数，请输入需要查找的数的值\n");
    scanf("%d", &x);
    locate(p, x);
    printf("开始删除p的后续结点\n");
    print_linked(p);
    deleteafter(p);
    printf("删除后的链表为\n");
    print_linked(p);
    return 0;
}

/*建立单链表*/

/*头插法建表*/
/*生成的链表结点的次序和输入的顺序相反*/
linklist *creatlistf()
{
    int i;
    linklist *head, *s;
    number = 0;
    i = 0;
    head = NULL;
    printf("你想创建多长的链表:\n");
    scanf("%d", &number);
    printf("开始创建!\n");
    // scanf("%d", &a); /*读入第一个结点的值*/
    for (i = 0; i < number; i++)
    {
        s = malloc(sizeof(linklist)); /*生成新的结点*/
        scanf("%d", &s->data);        /*将输入数据放入新结点的数据域中*/
        s->next = head;
        head = s; /*将新的结点插入到表头上*/
    }
    return head; /*返回表头指针*/
}

/*尾插法建表*/
/*生成的链表结点的次序和输入的顺序相同*/
linklist *creatlistf2()
{
    char ch;
    linklist *head, *s, *r;
    head = NULL; /*链表初指针为空*/
    r = NULL;    /*链表尾指针为空*/
    printf("输入第一个结点的值：\n");
    ch = getchar(); /*读入第一个结点的值*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*生成新的结点*/
        s->data = ch;                 /*将输入数据放入新结点的数据域中*/
        if (head == NULL)
        {
            head = s; /*新结点*s插入到空表*/
        }
        else
        {
            r->next = s; /*非空表，新节点插入到尾结点*r之后*/
        }
        r = s;          /*尾指针指向新的表尾*/
        ch = getchar(); /*读入下一个结点值*/
    }
    if (r != NULL)
    {
        r->next = NULL; /*对于非空表，将尾结点的指针域置空*/
    }
    return head; /*返回表头指针*/
}

/*尾插法建表改进，引入头结点，简化版*/
linklist *creatlistf2_1()
{
    char ch;
    linklist *head, *s, *r;
    head = malloc(sizeof(linklist)); /*生成头结点*/
    r = head;                        /*链表尾指针初值指向头结点*/
    printf("输入第一个结点的值：\n");
    ch = getchar(); /*读入第一个结点的值*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*生成新的结点*/
        s->data = ch;                 /*将输入数据放入新结点的数据域中*/
        r->next = s;                  /*新节点插入到尾结点*r之后*/
        r = s;                        /*尾指针指向新的表尾*/
        ch = getchar();               /*读入下一个结点值*/
    }
    r->next = NULL; /*将尾结点的指针域置空*/
    return head;    /*返回表头指针*/
}
/*以上三种算法时间复杂度均为O(n)*/

/*查找运算*/

/*按序号查找*/
linklist *get(linklist *head, int i)
{
    int j;
    linklist *p;
    p = head;
    j = 0; /*从头结点开始*/
    while ((p->next != NULL) && (j < i))
    {
        p = p->next; /*扫描下一个结点*/
        j++;         /*已扫描结点计数器*/
    }
    if (i == j)
    {
        return p; /*找到第i个结点*/
    }
    else
    {
        return NULL; /*找不到，i<=0或i>n，n为总的结点数*/
    }
}

/*按值查找*/
linklist *locate(linklist *head, int key)
{
    linklist *p;
    int i;
    p = head; /*从开始结点比较*/
    for (i = 1; i <= number; i++)
    {
        // printf("当前是第%d个结点，结点值为%d\n", i, p->data);
        if (p->data != key)
        {
            p = p->next; /*没找到，继续循环*/
        }
        else
        {
            // printf("已循环%d次\n", i);
            printf("该结点在第%d个，结点值为%d\n", i, p->data);
            break;
        }
    }
    return p;
}
/*算法的平均时间复杂度为O(n)*/

/*插入运算*/

/*后插操作*/
void insertafter(linklist *p, int x) /*将值为x的新结点插入*p之后*/
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = x;
    s->next = p->next;
    p->next = s; /*将*s插入*p之后*/
    number++;
}
/*时间复杂度为O(1)*/

/*前插操作*/
void insertafter1_1(linklist *head, linklist *p, int x)
{
    linklist *s, *q;
    s = malloc(sizeof(linklist));
    s->data = x;
    q = head;            /*从头指针开始*/
    while (q->next != p) /*查找*p的前趋结点*q */
    {
        q = q->next;
    }
    s->next = p;
    q->next = s;
}
/*时间复杂度为O(n),注意：在前插算法中，若链表没有头节点，则当*p是开始结点时，前趋结点*q不存在，必须特殊处理*/

/*前插操作改进*/
void insertafter1_2(linklist *p, int x)
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = p->data;
    s->next = p->next;
    p->data = x;
    p->next = s;
}
/*时间复杂度为O(1),但是结点的数据的信息量较大，则交换*p和*s的值时，时间开销也较为可观*/
/*比较以上两种算法，可以得出，在表的第一个位置上的前插操作外，表中其他位置上前插操作都没有后插操作方便。所以应该把单链表上的插入操作转化为后插操作*/

/*删除运算*/
void deleteafter(linklist *p)
{
    linklist *r;
    r = p->next;
    p->next = r->next; /*将结点*r从链上摘下来*/
    free(r);
    number--;
}
/*时间复杂度O(n)*/

/*输出运算*/
void print_linked(linklist *p)
{
    int i;
    printf("当前列表为：\n");
    for (i = 0; i <= number; i++)
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        else
        {
            break;
        }
    }
    printf("当前表长为%d", number);
}