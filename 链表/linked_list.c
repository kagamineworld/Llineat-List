#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} linklist;

int main() /*������*/
{
    linklist *CREATLISTF();
    linklist *LOCATE(linklist * head, int key);
    void LNSERTAFTER(linklist * p, int x);
    void DELETEAFTER(linklist * p);
}

/*����������*/

/*ͷ�巨����*/
/*���ɵ�������Ĵ���������˳���෴*/
linklist *CREATLISTF()
{
    char ch;
    linklist *head, *s;
    head = NULL;
    printf("�����һ������ֵ��\n");
    ch = getchar(); /*�����һ������ֵ*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*�����µĽ��*/
        s->data = ch;                 /*���������ݷ����½�����������*/
        s->next = head;
        head = s;       /*���µĽ����뵽��ͷ��*/
        ch = getchar(); /*������һ������ֵ*/
    }
    return head; /*���ر�ͷָ��*/
}

/*β�巨����*/
/*���ɵ�������Ĵ���������˳����ͬ*/
// linklist *CREATLISTF()
// {
//     char ch;
//     linklist *head, *s�� *r;
//     head = NULL; /*�����ָ��Ϊ��*/
//     r = NULL;    /*����βָ��Ϊ��*/
//     printf("�����һ������ֵ��\n");
//     ch = getchar(); /*�����һ������ֵ*/
//     while (ch != '$')
//     {
//         s = malloc(sizeof(linklist)); /*�����µĽ��*/
//         s->data = ch;                 /*���������ݷ����½�����������*/
//         if (head == NULL)
//         {
//             head = s; /*�½��*s���뵽�ձ�*/
//         }
//         else
//         {
//             r->next = s; /*�ǿձ��½ڵ���뵽β���*r֮��*/
//         }
//         r = s;          /*βָ��ָ���µı�β*/
//         ch = getchar(); /*������һ�����ֵ*/
//     }
//     if (r != NULL)
//     {
//         r->next = NULL; /*���ڷǿձ���β����ָ�����ÿ�*/
//     }
//     return head; /*���ر�ͷָ��*/
// }

/*β�巨����Ľ�������ͷ��㣬�򻯰�*/
// linklist *CREATLISTF1()
// {
//     char ch;
//     linklist *head, *s�� *r;
//     head = malloc(sizeof(linklist)); /*����ͷ���*/
//     r = head;                        /*����βָ���ֵָ��ͷ���*/
//     printf("�����һ������ֵ��\n");
//     ch = getchar();                  /*�����һ������ֵ*/
//     while (ch != '$')
//     {
//         s = malloc(sizeof(linklist)); /*�����µĽ��*/
//         s->data = ch;                 /*���������ݷ����½�����������*/
//         r->next = s;                  /*�½ڵ���뵽β���*r֮��*/
//         r = s;                        /*βָ��ָ���µı�β*/
//         ch = getchar();               /*������һ�����ֵ*/
//     }
//     r->next = NULL; /*��β����ָ�����ÿ�*/
//     return head;    /*���ر�ͷָ��*/
// }
/*���������㷨ʱ�临�ӶȾ�ΪO(n)*/

/*��������*/

/*����Ų���*/
// linklist *GET(linklist *head, int i)
// {
//     int j;
//     linklist *p;
//     p = head;
//     j = 0; /*��ͷ��㿪ʼ*/
//     while ((p->next != NULL) && (j < i)))
//         {
//             p = p->next; /*ɨ����һ�����*/
//             j++;         /*��ɨ���������*/
//         }
//     if (i == j)
//     {
//         return p; /*�ҵ���i�����*/
//     }
//     else
//     {
//         return NULL; /*�Ҳ�����i<=0��i>n��nΪ�ܵĽ����*/
//     }
// }

/*��ֵ����*/
linklist *LOCATE(linklist *head, int key)
{
    linklist *p;
    p = head->next; /*�ӿ�ʼ���Ƚ�*/
    while (p != NULL)
    {
        if (p->data != key)
        {
            p = p->next; /*û�ҵ�������ѭ��*/
        }
        else
        {
            break;
        }
    }
    return p;
}
/*�㷨��ƽ��ʱ�临�Ӷ�ΪO(n)*/

/*��������*/

/*������*/
void LNSERTAFTER(linklist *p, int x) /*��ֵΪx���½�����*p֮��*/
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = x;
    s->next = p->next;
    p->next = s; /*��*s����*p֮��*/
}
/*ʱ�临�Ӷ�ΪO(1)*/

/*ǰ�����*/
// void LNSERTAFTER(linklist *head, linklist *p, int x)
// {
//     linklist *s, *q;
//     s = malloc(sizeof(linklist));
//     s->data = x;
//     q = head;/*��ͷָ�뿪ʼ*/
//     while (q->next != p)/*����*p��ǰ�����*q */
//     {
//         q = q->next;
//     }
//     s->next = p;
//     q->next = s;
// }
/*ʱ�临�Ӷ�ΪO(n),ע�⣺��ǰ���㷨�У�������û��ͷ�ڵ㣬��*p�ǿ�ʼ���ʱ��ǰ�����*q�����ڣ��������⴦��*/

/*ǰ������Ľ�*/
// void LNSERTAFTER(linklist *p, int x)
// {
//     linklist *s;
//     s = malloc(sizeof(linklist));
//     s->data = p->data;
//     s->next = p->next;
//     p->data = x;
//     p->next = s;
// }
/*ʱ�临�Ӷ�ΪO(1),���ǽ������ݵ���Ϣ���ϴ��򽻻�*p��*s��ֵʱ��ʱ�俪��Ҳ��Ϊ�ɹ�*/
/*�Ƚ����������㷨�����Եó����ڱ�ĵ�һ��λ���ϵ�ǰ������⣬��������λ����ǰ�������û�к��������㡣����Ӧ�ðѵ������ϵĲ������ת��Ϊ������*/

/*ɾ������*/
void DELETEAFTER(linklist *p)
{
    linklist *r;
    r = p->next;
    p->next = r->next; /*�����*r������ժ����*/
    free(r);
}
/*ʱ�临�Ӷ�O(n)*/