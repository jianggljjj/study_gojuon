/*******************************************************************************
 * file:    gojuon.h
 * author:  jianggl
 * description: ������gojuon.cpp��Ҫ�õ�������
 ******************************************************************************/

#ifndef _GOJUON_H_
#define _GOJUON_H_

/* --- �� --- */
//==============================================================================
#define MAX_SIZE 60
#define NUMBER 46

/* --- �ṹ��/ȫ�ֱ��� --- */
//==============================================================================
// ��ʮ��ͼ��һ����ĸ����������
// ���������֣�ƽ������Ƭ����
typedef struct
{
    char *rChar;    // ������
    char *hChar;    // ƽ����
    char *kChar;    // Ƭ����
} letter;
// ��һ��˳������洢��ʮ��ͼ
typedef struct
{
    letter data[MAX_SIZE];
    int length;
} table;

// ÿ������֮������������̫��������ֻ�ܰ�����ȫ��������
//******************************************************************************
//  ������
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

// ƽ����
char *hChars[] =
    {
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��",
        (char *)"��"
    };
// Ƭ����
char *kChars[] = 
    {
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��", (char *)"��", (char *)"��", (char *)"��",
        (char *)"��", (char *)"��",
        (char *)"��"
    };

#endif
