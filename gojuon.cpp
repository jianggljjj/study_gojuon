#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 60
#define NUMBER 55

// 一个字母的数据
// 在五十音图中的位置，罗马字，平假名，片假名
typedef struct
{
    char *rChar;
    char *hChar;
    char *kChar;
} tableNode;
typedef struct
{
    tableNode data[MAX_SIZE];
    int length;
} table;

char *rChars[] =
    {
        (char *)"a ", (char *)"i ", (char *)"u ", (char *)"e ", (char *)"o ",
        (char *)"ka", (char *)"ki", (char *)"ku", (char *)"ke", (char *)"ko",
        (char *)"sa", (char *)"si", (char *)"su", (char *)"se", (char *)"so",
        (char *)"ta", (char *)"ti", (char *)"tu", (char *)"te", (char *)"to",
        (char *)"na", (char *)"ni", (char *)"nu", (char *)"ne", (char *)"no",
        (char *)"ha", (char *)"hi", (char *)"hu", (char *)"he", (char *)"ho",
        (char *)"ma", (char *)"mi", (char *)"mu", (char *)"me", (char *)"mo",
        (char *)"ya", (char *)"  ", (char *)"yu", (char *)"  ", (char *)"yo",
        (char *)"ra", (char *)"ri", (char *)"ru", (char *)"re", (char *)"ro",
        (char *)"wa", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"wo",
        (char *)"n ", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"  "
    };
char *hChars[] =
    {
        (char *)"あ", (char *)"い", (char *)"う", (char *)"え", (char *)"お",
        (char *)"か", (char *)"き", (char *)"く", (char *)"け", (char *)"こ",
        (char *)"さ", (char *)"し", (char *)"す", (char *)"せ", (char *)"そ",
        (char *)"た", (char *)"ち", (char *)"つ", (char *)"て", (char *)"と",
        (char *)"な", (char *)"に", (char *)"ぬ", (char *)"ね", (char *)"の",
        (char *)"は", (char *)"ひ", (char *)"ふ", (char *)"へ", (char *)"ほ",
        (char *)"ま", (char *)"み", (char *)"む", (char *)"め", (char *)"も",
        (char *)"や", (char *)"  ", (char *)"ゆ", (char *)"  ", (char *)"よ",
        (char *)"ら", (char *)"り", (char *)"る", (char *)"れ", (char *)"ろ",
        (char *)"わ", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"を",
        (char *)"ん", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"  "
    };
char *kChars[] = 
    {
        (char *)"ア", (char *)"イ", (char *)"ウ", (char *)"エ", (char *)"オ",
        (char *)"カ", (char *)"キ", (char *)"ク", (char *)"ケ", (char *)"コ",
        (char *)"サ", (char *)"シ", (char *)"ス", (char *)"セ", (char *)"ソ",
        (char *)"タ", (char *)"チ", (char *)"ツ", (char *)"テ", (char *)"ト",
        (char *)"ナ", (char *)"ニ", (char *)"ヌ", (char *)"ネ", (char *)"ノ",
        (char *)"ハ", (char *)"ヒ", (char *)"フ", (char *)"ヘ", (char *)"ホ",
        (char *)"マ", (char *)"ミ", (char *)"ム", (char *)"メ", (char *)"モ",
        (char *)"ヤ", (char *)"  ", (char *)"ユ", (char *)"  ", (char *)"ヨ",
        (char *)"ラ", (char *)"リ", (char *)"ル", (char *)"レ", (char *)"ロ",
        (char *)"ワ", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"ヲ",
        (char *)"ン", (char *)"  ", (char *)"  ", (char *)"  ", (char *)"  "
    };

void initTable(table *&t)
{
    t = (table *)malloc(sizeof(table));
    t->length = 0;
}

void destroyTable(table *&t)
{
    free(t);
}

void insertTable(table *&t, int i, tableNode node)
{
    t->data[i - 1] = node;
}

void disp(table *t)
{
    int i;

    for (i = 0; i < t->length; i++)
    {
        printf("%s ", t->data[i].rChar);
        printf("%s ", t->data[i].hChar);
        printf("%s    ", t->data[i].kChar);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
}

void createTable(table *&t, char *rChars[], char *hChars[], char *kChars[], int num)
{
    int i;
    tableNode node;

    initTable(t);
    for (i = 0; i < num; i++)
    {
        node.rChar = rChars[i];
        node.hChar = hChars[i];
        node.kChar = kChars[i];
        insertTable(t, i + 1, node);
    }
    t->length = num;
}

void printNode(tableNode node, int j)
{
    switch (j)
    {
        case 0:printf("%s\n", node.rChar);break;
        case 1:printf("%s\n", node.hChar);break;
        case 2:printf("%s\n", node.kChar);break;
    }
//    getchar();
//    switch (j)
//    {
//        case 0:
//            printf("%s\n", node.hChar);
//            printf("%s\n", node.kChar);
//            break;
//        case 1:
//            printf("%s\n", node.rChar);
//            printf("%s\n", node.kChar);
//            break;
//        case 2:
//            printf("%s\n", node.rChar);
//            printf("%s\n", node.hChar);
//            break;
//    }
}

void start(table *t)
{
    char key;
    char c;
    int i;
    int j;

    while (true)
    {
        printf("回车继续,退出按q\n");
        key = getchar();
        if (key == 'q')
            break;
        if (key != '\n')
            while ((c = getchar()) != '\n');
        system("cls");
        while (true)
        {
            i = rand() % NUMBER;
            if (i != 37 && i != 39 && i != 47 && i != 48)
                if ( i != 49 && i != 52 && i != 53 && i != 54 && i != 55)
                    break;
        }
        j = rand() % 3;
        printNode(t->data[i - 1], j);
    }
}

void start_2(table *t)
{
    char key, c, str[3];
    int i, j, k;
    int number[46];
    int seed;

    printf("输入种子: ");
    scanf("%d", &seed);
    for (k = 0; k <= 35; k++)
        number[k] = k;
    number[36] = 37;
    for (k = 37; k <= 43; k++)
        number[k] = k + 2;
    number[44] = 49;
    number[45] = 50;
    for (k = 0; k < 20; k++)
    {
        while (true)
        {
            i = (rand() + seed) % NUMBER;
            if (i != 37 && i != 39 && i != 47 && i != 48)
                if ( i != 49 && i != 52 && i != 53 && i != 54 && i != 55)
                    break;
        }
        j = number[i];
        number[i] = number[k];
        number[k] = j;;
    }
    for (k = 0; k < 46; k++)
    {
        system("cls");
        i = number[k] + 1;
        printNode(t->data[i - 1], 1);
        seed = 0;
        while (true)
        {
            printf("发音: ");
            str[0] = getchar();
            while (str[0] == '\n')
                str[0] = getchar();
            if (i <= 5 || i == 51)
                if (str[0] == t->data[i - 1].rChar[0])
                    break;
            str[1] = getchar();
            while (str[0] == '\n')
                str[0] = getchar();
            str[2] = getchar();
            if (str[0] == t->data[i - 1].rChar[0])
                if (str[1] == t->data[i - 1].rChar[1])
                    if (str[2] == '\n')
                        break;
            if (str[2] != '\n')
                while ((c = getchar()) != '\n');
            seed++;
            if (seed == 3)
                printf("提示: %c\n", t->data[i - 1].rChar[0]);
            if (seed == 6)
            {
                printf("答案为: %c", t->data[i - 1].rChar[0]);
                printf("%c\n", t->data[i - 1].rChar[1]);
                getchar();
                break;
            }
        }
    }
}

int main(void)
{
    table *table;

    createTable(table, rChars, hChars, kChars, NUMBER);
    disp(table);
    start_2(table);
    destroyTable(table);
    return 0;
}
