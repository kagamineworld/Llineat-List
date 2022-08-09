/*��ƪ�����д���ʹ�õ��ĺ����Ǿ����޸ĺ�������������⣬����û��ʹ�õĺ���û�н����޸ģ����������ʲô����*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node /*���嵥����ṹ����*/
{
    int data;
    struct node *next;
} linklist;

int number; /*����һ��ȫ�ֱ�����������¼������*/

int main() /*������*/
{
    linklist *p;
    int x;
    linklist *creatlistf(); /*ͷ�巨����,��Ϊ����ʹ�õĺ���*/                    /*����������*/
    linklist *creatlistf2();                                                     /*β�巨����*/
    linklist *creatlistf2_1();                                                   /*β�巨����Ľ�������ͷ��㣬�򻯰�*/
    linklist *locate(linklist * head, int key); /*��ֵ���ң���Ϊ����ʹ�õĺ���*/ /*�������Һ���*/
    linklist *get(linklist * head, int i);                                       /*����Ų���*/
    void insertafter(linklist * p, int x); /*����������Ϊ����ʹ�õĺ���*/      /*�������뺯��*/
    void insertafter1_1(linklist * head, linklist * p, int x);                   /*ǰ�����*/
    void insertafter1_2(linklist * p, int x);                                    /*ǰ������Ľ�*/
    void deleteafter(linklist * p); /*ɾ�����㣬��Ϊ����ʹ�õĺ���*/             /*����ɾ������*/
    void print_linked(linklist * p);                                             /*�����ǰ������*/
    printf("��ʼ����������\n");
    p = creatlistf();
    print_linked(p);
    printf("\n");
    printf("����һ�������б���,��������Ҫ���������ֵ\n");
    scanf("%d", &x);
    insertafter(p, x);
    print_linked(p);
    printf("\n");
    printf("��ʼ����һ��������������Ҫ���ҵ�����ֵ\n");
    scanf("%d", &x);
    locate(p, x);
    printf("��ʼɾ��p�ĺ������\n");
    print_linked(p);
    deleteafter(p);
    printf("ɾ���������Ϊ\n");
    print_linked(p);
    return 0;
}

/*����������*/

/*ͷ�巨����*/
/*���ɵ�������Ĵ���������˳���෴*/
linklist *creatlistf()
{
    int i;
    linklist *head, *s;
    number = 0;
    i = 0;
    head = NULL;
    printf("���봴���೤������:\n");
    scanf("%d", &number);
    printf("��ʼ����!\n");
    // scanf("%d", &a); /*�����һ������ֵ*/
    for (i = 0; i < number; i++)
    {
        s = malloc(sizeof(linklist)); /*�����µĽ��*/
        scanf("%d", &s->data);        /*���������ݷ����½�����������*/
        s->next = head;
        head = s; /*���µĽ����뵽��ͷ��*/
    }
    return head; /*���ر�ͷָ��*/
}

/*β�巨����*/
/*���ɵ�������Ĵ���������˳����ͬ*/
linklist *creatlistf2()
{
    char ch;
    linklist *head, *s, *r;
    head = NULL; /*�����ָ��Ϊ��*/
    r = NULL;    /*����βָ��Ϊ��*/
    printf("�����һ������ֵ��\n");
    ch = getchar(); /*�����һ������ֵ*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*�����µĽ��*/
        s->data = ch;                 /*���������ݷ����½�����������*/
        if (head == NULL)
        {
            head = s; /*�½��*s���뵽�ձ�*/
        }
        else
        {
            r->next = s; /*�ǿձ��½ڵ���뵽β���*r֮��*/
        }
        r = s;          /*βָ��ָ���µı�β*/
        ch = getchar(); /*������һ�����ֵ*/
    }
    if (r != NULL)
    {
        r->next = NULL; /*���ڷǿձ���β����ָ�����ÿ�*/
    }
    return head; /*���ر�ͷָ��*/
}

/*β�巨����Ľ�������ͷ��㣬�򻯰�*/
linklist *creatlistf2_1()
{
    char ch;
    linklist *head, *s, *r;
    head = malloc(sizeof(linklist)); /*����ͷ���*/
    r = head;                        /*����βָ���ֵָ��ͷ���*/
    printf("�����һ������ֵ��\n");
    ch = getchar(); /*�����һ������ֵ*/
    while (ch != '$')
    {
        s = malloc(sizeof(linklist)); /*�����µĽ��*/
        s->data = ch;                 /*���������ݷ����½�����������*/
        r->next = s;                  /*�½ڵ���뵽β���*r֮��*/
        r = s;                        /*βָ��ָ���µı�β*/
        ch = getchar();               /*������һ�����ֵ*/
    }
    r->next = NULL; /*��β����ָ�����ÿ�*/
    return head;    /*���ر�ͷָ��*/
}
/*���������㷨ʱ�临�ӶȾ�ΪO(n)*/

/*��������*/

/*����Ų���*/
linklist *get(linklist *head, int i)
{
    int j;
    linklist *p;
    p = head;
    j = 0; /*��ͷ��㿪ʼ*/
    while ((p->next != NULL) && (j < i))
    {
        p = p->next; /*ɨ����һ�����*/
        j++;         /*��ɨ���������*/
    }
    if (i == j)
    {
        return p; /*�ҵ���i�����*/
    }
    else
    {
        return NULL; /*�Ҳ�����i<=0��i>n��nΪ�ܵĽ����*/
    }
}

/*��ֵ����*/
linklist *locate(linklist *head, int key)
{
    linklist *p;
    int i;
    p = head; /*�ӿ�ʼ���Ƚ�*/
    for (i = 1; i <= number; i++)
    {
        // printf("��ǰ�ǵ�%d����㣬���ֵΪ%d\n", i, p->data);
        if (p->data != key)
        {
            p = p->next; /*û�ҵ�������ѭ��*/
        }
        else
        {
            // printf("��ѭ��%d��\n", i);
            printf("�ý���ڵ�%d�������ֵΪ%d\n", i, p->data);
            break;
        }
    }
    return p;
}
/*�㷨��ƽ��ʱ�临�Ӷ�ΪO(n)*/

/*��������*/

/*������*/
void insertafter(linklist *p, int x) /*��ֵΪx���½�����*p֮��*/
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = x;
    s->next = p->next;
    p->next = s; /*��*s����*p֮��*/
    number++;
}
/*ʱ�临�Ӷ�ΪO(1)*/

/*ǰ�����*/
void insertafter1_1(linklist *head, linklist *p, int x)
{
    linklist *s, *q;
    s = malloc(sizeof(linklist));
    s->data = x;
    q = head;            /*��ͷָ�뿪ʼ*/
    while (q->next != p) /*����*p��ǰ�����*q */
    {
        q = q->next;
    }
    s->next = p;
    q->next = s;
}
/*ʱ�临�Ӷ�ΪO(n),ע�⣺��ǰ���㷨�У�������û��ͷ�ڵ㣬��*p�ǿ�ʼ���ʱ��ǰ�����*q�����ڣ��������⴦��*/

/*ǰ������Ľ�*/
void insertafter1_2(linklist *p, int x)
{
    linklist *s;
    s = malloc(sizeof(linklist));
    s->data = p->data;
    s->next = p->next;
    p->data = x;
    p->next = s;
}
/*ʱ�临�Ӷ�ΪO(1),���ǽ������ݵ���Ϣ���ϴ��򽻻�*p��*s��ֵʱ��ʱ�俪��Ҳ��Ϊ�ɹ�*/
/*�Ƚ����������㷨�����Եó����ڱ�ĵ�һ��λ���ϵ�ǰ������⣬��������λ����ǰ�������û�к��������㡣����Ӧ�ðѵ������ϵĲ������ת��Ϊ������*/

/*ɾ������*/
void deleteafter(linklist *p)
{
    linklist *r;
    r = p->next;
    p->next = r->next; /*�����*r������ժ����*/
    free(r);
    number--;
}
/*ʱ�临�Ӷ�O(n)*/

/*�������*/
void print_linked(linklist *p)
{
    int i;
    printf("��ǰ�б�Ϊ��\n");
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
    printf("��ǰ��Ϊ%d", number);
}