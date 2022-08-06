#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} linklist;

int main() /*主函数*/
{
    linklist *CREATLISTF();
    linklist *LOCATE(linklist * head, int key);
    void LNSERTAFTER(linklist * p, int x);
    void DELETEAFTER(linklist * p);
}

/*建立单链表*/

/*头插法建表*/
/*生成的链表结点的次序和输入的顺序相反*/
linklist *CREATLISTF()
{
    char ch;
    linklist *head, *s;
    head = NULL;
    printf("输入第一个结点的值：\n");
    ch = getchar(); /*读入第一个结点的值*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*生成新的结点*/
        s->data = ch;                 /*将输入数据放入新结点的数据域中*/
        s->next = head;
        head = s;       /*将新的结点插入到表头上*/
        ch = getchar(); /*读入下一个结点的值*/
    }
    return head; /*返回表头指针*/
}

/*尾插法建表*/
/*生成的链表结点的次序和输入的顺序相同*/
// linklist *CREATLISTF()
// {
//     char ch;
//     linklist *head, *s， *r;
//     head = NULL; /*链表初指针为空*/
//     r = NULL;    /*链表尾指针为空*/
//     printf("输入第一个结点的值：\n");
//     ch = getchar(); /*读入第一个结点的值*/
//     while (ch != '$')
//     {
//         s = malloc(sizeof(linklist)); /*生成新的结点*/
//         s->data = ch;                 /*将输入数据放入新结点的数据域中*/
//         if (head == NULL)
//         {
//             head = s; /*新结点*s插入到空表*/
//         }
//         else
//         {
//             r->next = s; /*非空表，新节点插入到尾结点*r之后*/
//         }
//         r = s;          /*尾指针指向新的表尾*/
//         ch = getchar(); /*读入下一个结点值*/
//     }
//     if (r != NULL)
//     {
//         r->next = NULL; /*对于非空表，将尾结点的指针域置空*/
//     }
//     return head; /*返回表头指针*/
// }

/*尾插法建表改进，引入头结点，简化版*/
// linklist *CREATLISTF1()
// {
//     char ch;
//     linklist *head, *s， *r;
//     head = malloc(sizeof(linklist)); /*生成头结点*/
//     r = head;                        /*链表尾指针初值指向头结点*/
//     printf("输入第一个结点的值：\n");
//     ch = getchar();                  /*读入第一个结点的值*/
//     while (ch != '$')
//     {
//         s = malloc(sizeof(linklist)); /*生成新的结点*/
//         s->data = ch;                 /*将输入数据放入新结点的数据域中*/
//         r->next = s;                  /*新节点插入到尾结点*r之后*/
//         r = s;                        /*尾指针指向新的表尾*/
//         ch = getchar();               /*读入下一个结点值*/
//     }
//     r->next = NULL; /*将尾结点的指针域置空*/
//     return head;    /*返回表头指针*/
// }
/*以上三种算法时间复杂度均为O(n)*/

/*查找运算*/

/*按序号查找*/
// linklist *GET(linklist *head, int i)
// {
//     int j;
//     linklist *p;
//     p = head;
//     j = 0; /*从头结点开始*/
//     while ((p->next != NULL) && (j < i)))
//         {
//             p = p->next; /*扫描下一个结点*/
//             j++;         /*已扫描结点计数器*/
//         }
//     if (i == j)
//     {
//         return p; /*找到第i个结点*/
//     }
//     else
//     {
//         return NULL; /*找不到，i<=0或i>n，n为总的结点数*/
//     }
// }

/*按值查找*/
linklist *LOCATE(linklist *head, int key)
{
    linklist *p;
    p = head->next; /*从开始结点比较*/
    while (p != NULL)
    {
        if (p->data != key)
        {
            p = p->next; /*没找到，继续循环*/
        }
        else
        {
            break;
        }
    }
    return p;
}
/*算法的平均时间复杂度为O(n)*/

/*插入运算*/

/*后插操作*/
void LNSERTAFTER(linklist *p, int x) /*将值为x的新结点插入*p之后*/
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = x;
    s->next = p->next;
    p->next = s; /*将*s插入*p之后*/
}
/*时间复杂度为O(1)*/

/*前插操作*/
// void LNSERTAFTER(linklist *head, linklist *p, int x)
// {
//     linklist *s, *q;
//     s = malloc(sizeof(linklist));
//     s->data = x;
//     q = head;/*从头指针开始*/
//     while (q->next != p)/*查找*p的前趋结点*q */
//     {
//         q = q->next;
//     }
//     s->next = p;
//     q->next = s;
// }
/*时间复杂度为O(n),注意：在前插算法中，若链表没有头节点，则当*p是开始结点时，前趋结点*q不存在，必须特殊处理*/

/*前插操作改进*/
// void LNSERTAFTER(linklist *p, int x)
// {
//     linklist *s;
//     s = malloc(sizeof(linklist));
//     s->data = p->data;
//     s->next = p->next;
//     p->data = x;
//     p->next = s;
// }
/*时间复杂度为O(1),但是结点的数据的信息量较大，则交换*p和*s的值时，时间开销也较为可观*/
/*比较以上两种算法，可以得出，在表的第一个位置上的前插操作外，表中其他位置上前插操作都没有后插操作方便。所以应该把单链表上的插入操作转化为后插操作*/

/*删除运算*/
void DELETEAFTER(linklist *p)
{
    linklist *r;
    r = p->next;
    p->next = r->next; /*将结点*r从链上摘下来*/
    free(r);
}
/*时间复杂度O(n)*/