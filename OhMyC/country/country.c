//
//  country.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/16.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "country.h"
#include <ctype.h>

#define MAX_COUNTRY_COUNT 200
#define MAX_COUNTRY_NAME_LENGTH 100
typedef struct {
    char name[MAX_COUNTRY_NAME_LENGTH + 1];
    int code;
}Country_Code;

Country_Code country_codes[MAX_COUNTRY_COUNT];
int s_index = 0;
void s_insert(void);
void s_search(void);
void s_update(void);
void s_print(void);

int country_start(void) {
    char op;
    while (1) {
        printf("输入操作符:");
        scanf(" %c",&op);
        switch (op) {
            case 'i':
                s_insert();
                break;
            case 's':
                s_search();
                break;
            case 'u':
                s_update();
                break;
            case 'p':
                s_print();
                break;
            case 'q':
                return 0;
            default:
                printf("非法操作符");
        }
    }
}

int s_readline(char str[],int n) {
    int ch,i = 0;
    while (isspace(ch = getchar())) {
        ;
    }
    while (ch != '\n'&&ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

int s_find(int code) {
    int index = -1;
    for (int i = 0; i < s_index; i++) {
        if (country_codes[i].code == code) {
            index = i;
            break;
        }
    }
    return index;
}

void s_insert(void) {
    if (s_index < MAX_COUNTRY_COUNT) {
        printf("输入国家区号:");
        int code;
        scanf(" %d",&code);
        if (s_find(code) > -1) {
            printf("国家区号已经存在\n");
        }else{
            printf("输入国家名称:");
            s_readline(country_codes[s_index].name, MAX_COUNTRY_NAME_LENGTH);
            country_codes[s_index].code = code;
            s_index++;
        }
    }else{
        printf("已经存满了");
    }
}

void s_search(void) {
    printf("输入国家区号:");
    int code;
    scanf(" %d",&code);
    int index = s_find(code);
    if (index > -1) {
        Country_Code c = country_codes[index];
        printf("国家名称:%s 国家区号:%d\n",c.name,c.code);
    }else{
        printf("不存在这个国家数据");
    }
}

void s_update(void) {
    
}

void s_print(void) {
    for (int i = 0; i < s_index; i++) {
        printf("国家名称:%s 国家区号:%d\n",country_codes[i].name,country_codes[i].code);
    }
}
