/*******************************************************************************
 * file:            gojuon.cpp
 * author:          jianggl
 * created time:    2022/4/13 ����
 * description:     �����ʮ��ͼ
 * ****************************************************************************/

/* --- ͷ�ļ� --- */
//==============================================================================
#include <stdio.h>
#include <stdlib.h>

// ��������Ҫ�õ�������
#include "gojuon.h"

/* --- ���� --- */
//==============================================================================
// ��ʼ�����Ա�
void initTable(table *&t)
{
    // malloc���ص�ֵ����Ϊnull
    // ����t֮ǰҪ�����Ƿ�Ϊnull
    t = (table *)malloc(sizeof(table));
    if (t != NULL)
        t->length = 0;
}

// ɾ�����Ա�
void destroyTable(table *&t)
{
    free(t);
}

// ���һ����������ʮ��ͼ
void dispGojuon(table *t)
{
    int i, j;
    i = 0;
    j = 0;
    while (i < t->length)
    {
        printf("%s ", t->data[i].rChar);
        printf("%s ", t->data[i].hChar);
        printf("%s    ", t->data[i].kChar);

        // Ϊ�����ۣ��ڿ�λ���ո�
        if (i == 35 || i == 36)
        {
            printf("            ");
            j++;
        }
        if (i == 43)
        {
            printf("            ");
            printf("            ");
            printf("            ");
            j += 3;
        }

        // ÿ�����5������ʱ����
        if ((j + 1) % 5 == 0)
            printf("\n");
        i++;
        j++;
    }
    printf("\n");
}

// ������ʮ��ͼ
void createGojuon(table *&t, char *rChars[], char *hChars[], char *kChars[])
{
    int i;
    letter node;

    for (i = 0; i < NUMBER; i++)
    {
        node.rChar = rChars[i];
        node.hChar = hChars[i];
        node.kChar = kChars[i];
        t->data[i] = node;
    }
    t->length = NUMBER;
}

// ����ƽ������������ƥ���û�������
void match(table *gojuon, int number)
{
    char str[3];
    char uselessChars;
    int tip = 0;

    printf("%s\n", gojuon->data[number].hChar);
    while (true)
    {
        printf("����: ");
        while ((str[0] = getchar()) == '\n');
        // �⼸����������ֻ��һ����ĸ
        if (number < 5 || number == 45)
            if (str[0] == gojuon->data[number].rChar[0])
                break;
        while ((str[1] = getchar()) == '\n');
        str[2] = getchar();
        if (str[0] == gojuon->data[number].rChar[0])
            if (str[1] == gojuon->data[number].rChar[1])
                if (str[2] == '\n')
                    break;
        if (str[2] != '\n')
            while ((str[2] = getchar()) != '\n');
        tip++;
        if (tip == 3)
            printf("��ʾ: %c\n", gojuon->data[number].rChar[0]);
        if (tip == 6)
        {
            printf("��: %s\n", gojuon->data[number].rChar);
            // getchar�з���ֵ
            uselessChars = getchar();
            break;
        }
    }
}

// ��ʼһ�����ԣ�����һ��ƽ������ƥ���û������������
void startTest(table *gojuon)
{
    int scanfReturn;
    int seed;   // �������������
    int number[46] = { 0 }; // �����������˳�������ʮ��
    int i, randNum;
    int temp;   // ������������number[]����

    // ��Ȼ˳��(������0-n)
    for (i = 0; i < gojuon->length; i++)
        number[i] = i;
    printf("��������������ʮ��ͼ��\n");
    printf("����һ������������ʮ�������˳���Կ�ʼ����: ");
    // scanf�з���ֵ
    scanfReturn = scanf("%d", &seed);
    srand(seed);

    // �õ�һ�����˳��
    for (i = 0; i < gojuon->length - 1; i++)
    {
        randNum = rand() % gojuon->length;
        temp = number[randNum];
        number[randNum] = number[i];
        number[i] = temp;
    }
    // �����˳�����number[],ͬʱ������ʮ��
    for (i = 0; i < 46; i++)
    {
        system("cls");
        match(gojuon, number[i]);
    }
    system("cls");
    printf("��ϲ����ɹ�ͨ���˲���!\n");
    system("pause");
}

/* --- main���� --- */
//==============================================================================
int main(void)
{
    table *gojuon;

    initTable(gojuon);
    createGojuon(gojuon, rChars, hChars, kChars);
    dispGojuon(gojuon);
    startTest(gojuon);
    destroyTable(gojuon);
    return 0;
}
