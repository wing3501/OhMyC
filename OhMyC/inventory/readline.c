//
//  readline.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/13.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "readline.h"
#include <ctype.h>

int read_line(char str[], int n) {
    int ch = 0,i = 0;
    while (isspace(ch = getchar())) {
        ;
    }
    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
