//
//  line.h
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/10.
//  Copyright © 2018年 styf. All rights reserved.
//

#ifndef line_h
#define line_h

#include <stdio.h>

/**
 清除行缓冲区
 */
void clear_line(void);

/**
 往行缓冲区添加单词
 */
void add_word(const char *word);

/**
 检查行缓冲区中还剩多少字符
 */
int space_remaining(void);

/**
 输出行缓冲区的内容，进行调整
 */
void write_line(void);
/**
 输出行缓冲区的内容，不进行调整
 */
void flush_line(void);

#endif /* line_h */
