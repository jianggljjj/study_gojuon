/*******************************************************************************
 * file:    gojuon.h
 * author:  jianggl
 * description: 保存了gojuon.cpp需要用到的数据
 ******************************************************************************/

#ifndef _GOJUON_H_
#define _GOJUON_H_

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

// 每个假名之间的相差数量不太规则，这里只能把他们全部存下来
//******************************************************************************
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

#endif
