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

/* --- 宏 --- */
//==============================================================================
#define MAX_SIZE 60
#define NUMBER 46

/* --- 结构体/全局变量 --- */
//==============================================================================

// 五十音图中一个字母的所有数据
// 包括罗马字，平假名，片假名
typedef struct
{
    char *rChar;    // 罗马字
    char *hChar;    // 平假名
    char *kChar;    // 片假名
} letter;
// 用一个顺序表来存储五十音图
typedef struct
{
    letter data[MAX_SIZE];
    int length;
} table;

//  罗马字
char *rChars[] =
    {
        (char *)"a ", (char *)"i ", (char *)"u ", (char *)"e ", (char *)"o ",
        (char *)"ka", (char *)"ki", (char *)"ku", (char *)"ke", (char *)"ko",
        (char *)"sa", (char *)"si", (char *)"su", (char *)"se", (char *)"so",
        (char *)"ta", (char *)"ti", (char *)"tu", (char *)"te", (char *)"to",
        (char *)"na", (char *)"ni", (char *)"nu", (char *)"ne", (char *)"no",
        (char *)"ha", (char *)"hi", (char *)"hu", (char *)"he", (char *)"ho",
        (char *)"ma", (char *)"mi", (char *)"mu", (char *)"me", (char *)"mo",
        (char *)"ya", (char *)"yu", (char *)"yo",
        (char *)"ra", (char *)"ri", (char *)"ru", (char *)"re", (char *)"ro",
        (char *)"wa", (char *)"wo",
        (char *)"n "
    };
// 平假名
char *hChars[] =
    {
        (char *)"あ", (char *)"い", (char *)"う", (char *)"え", (char *)"お",
        (char *)"か", (char *)"き", (char *)"く", (char *)"け", (char *)"こ",
        (char *)"さ", (char *)"し", (char *)"す", (char *)"せ", (char *)"そ",
        (char *)"た", (char *)"ち", (char *)"つ", (char *)"て", (char *)"と",
        (char *)"な", (char *)"に", (char *)"ぬ", (char *)"ね", (char *)"の",
        (char *)"は", (char *)"ひ", (char *)"ふ", (char *)"へ", (char *)"ほ",
        (char *)"ま", (char *)"み", (char *)"む", (char *)"め", (char *)"も",
        (char *)"や", (char *)"ゆ", (char *)"よ",
        (char *)"ら", (char *)"り", (char *)"る", (char *)"れ", (char *)"ろ",
        (char *)"わ", (char *)"を",
        (char *)"ん"
    };
// 片假名
char *kChars[] = 
    {
        (char *)"ア", (char *)"イ", (char *)"ウ", (char *)"エ", (char *)"オ",
        (char *)"カ", (char *)"キ", (char *)"ク", (char *)"ケ", (char *)"コ",
        (char *)"サ", (char *)"シ", (char *)"ス", (char *)"セ", (char *)"ソ",
        (char *)"タ", (char *)"チ", (char *)"ツ", (char *)"テ", (char *)"ト",
        (char *)"ナ", (char *)"ニ", (char *)"ヌ", (char *)"ネ", (char *)"ノ",
        (char *)"ハ", (char *)"ヒ", (char *)"フ", (char *)"ヘ", (char *)"ホ",
        (char *)"マ", (char *)"ミ", (char *)"ム", (char *)"メ", (char *)"モ",
        (char *)"ヤ", (char *)"ユ", (char *)"ヨ",
        (char *)"ラ", (char *)"リ", (char *)"ル", (char *)"レ", (char *)"ロ",
        (char *)"ワ", (char *)"ヲ",
        (char *)"ン"
    };

/* --- 函数 --- */
//==============================================================================
// 初始化线性表
void initTable(table *&t)
{
    t = (table *)malloc(sizeof(table));
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

void print(table *gojuon, int number)
{
    char str[3];
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
            getchar();
            break;
        }
    }
}

// 完成特殊功能
void start(table *gojuon)
{
    int seed;   // 用来产生随机数
    int number[46]; // 按数组给出的顺序输出五十音
    int i, randNum;
    int temp;   // 用来交换数组number[]数据

    // 自然顺序(递增的0-n)
    for (i = 0; i < gojuon->length; i++)
        number[i] = i;
    printf("以上是完整的五十音图。\n");
    printf("输入一个整数生成五十音的随机顺序以开始测试: ");
    scanf("%d", &seed);
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
        print(gojuon, number[i]);
    }
    system("cls");
    printf("恭喜，你成功通过了测试!\n");
}

/* --- main函数 --- */
//==============================================================================
int main(void)
{
    table *gojuon;

    initTable(gojuon);
    createGojuon(gojuon, rChars, hChars, kChars);
    dispGojuon(gojuon);
    start(gojuon);
    destroyTable(gojuon);
    return 0;
}
