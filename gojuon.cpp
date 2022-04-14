/*******************************************************************************
 * file:            gojuon.cpp
 * author:          jianggl
 * created time:    2022/4/13 下午
 * description:     输出五十音图
 * ****************************************************************************/

/* --- 头文件 --- */
//==============================================================================
#include <stdio.h>
#include <stdlib.h>

// 包含了需要用到的数据
#include "gojuon.h"

/* --- 函数 --- */
//==============================================================================
// 初始化线性表
void initTable(table *&t)
{
    // malloc返回的值可能为null
    // 引用t之前要检验是否为null
    t = (table *)malloc(sizeof(table));
    if (t != NULL)
        t->length = 0;
}

// 删除线性表
void destroyTable(table *&t)
{
    free(t);
}

// 输出一个完整的五十音图
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

        // 为了美观，在空位填充空格
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

        // 每当输出5个数据时换行
        if ((j + 1) % 5 == 0)
            printf("\n");
        i++;
        j++;
    }
    printf("\n");
}

// 创建五十音图
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

// 给出平假名，并尝试匹配用户的输入
void match(table *gojuon, int number)
{
    char str[3];
    char uselessChars;
    int tip = 0;

    printf("%s\n", gojuon->data[number].hChar);
    while (true)
    {
        printf("发音: ");
        while ((str[0] = getchar()) == '\n');
        // 这几个的罗马字只有一个字母
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
            printf("提示: %c\n", gojuon->data[number].rChar[0]);
        if (tip == 6)
        {
            printf("答案: %s\n", gojuon->data[number].rChar);
            // getchar有返回值
            uselessChars = getchar();
            break;
        }
    }
}

// 开始一个测试，给出一个平假名，匹配用户输入的罗马字
void startTest(table *gojuon)
{
    int scanfReturn;
    int seed;   // 用来产生随机数
    int number[46] = { 0 }; // 按数组给出的顺序输出五十音
    int i, randNum;
    int temp;   // 用来交换数组number[]数据

    // 自然顺序(递增的0-n)
    for (i = 0; i < gojuon->length; i++)
        number[i] = i;
    printf("以上是完整的五十音图。\n");
    printf("输入一个整数生成五十音的随机顺序以开始测试: ");
    // scanf有返回值
    scanfReturn = scanf("%d", &seed);
    srand(seed);

    // 得到一个随机顺序
    for (i = 0; i < gojuon->length - 1; i++)
    {
        randNum = rand() % gojuon->length;
        temp = number[randNum];
        number[randNum] = number[i];
        number[i] = temp;
    }
    // 以随机顺序遍历number[],同时遍历五十音
    for (i = 0; i < 46; i++)
    {
        system("cls");
        match(gojuon, number[i]);
    }
    system("cls");
    printf("恭喜，你成功通过了测试!\n");
    system("pause");
}

/* --- main函数 --- */
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
