//
//  line.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/10.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "line.h"
#include <string.h>
#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;//当前行的字符数量
int num_words = 0;//当前行的单词数量

/**
 清除行缓冲区
 */
void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

/**
 往行缓冲区添加单词
 */
void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line,word);
    line_len += strlen(word);
    num_words++;
}

/**
 检查行缓冲区中还剩多少字符
 */
int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

/**
 输出行缓冲区的内容，进行调整
 */
void write_line(void)
{
    int extra_spaces,spaces_to_insert,i,j;
    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ') {
            putchar(line[i]);
        }else{
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++) {
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}
/**
 输出行缓冲区的内容，不进行调整
 */
void flush_line(void)
{
    if (line_len > 0) {
        puts(line);
    }
}
