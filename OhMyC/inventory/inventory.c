//
//  inventory.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/13.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "inventory.h"
#include "readline.h"
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} *inventory;

//#define MAX_PARTS 100
//
//struct part {
//    int number;
//    char name[NAME_LEN+1];
//    int on_hand;
//} inventory[MAX_PARTS];
int count = 5;
int num_parts = 0;//目前存的数量

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void delete(void);
void output(void);
void input(void);
void hebing(void);

int start(void) {
    inventory = malloc(count * sizeof(struct part));
    char code;
    for (;;) {
        printf("输入操作符:");
        scanf(" %c",&code);
        switch (code) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'e':
                delete();
                break;
            case 'd':
                output();
                break;
            case 'r':
                input();
                break;
            case 'h':
                hebing();
                break;
            case 'q':
                return 0;
            default:
                printf("非法操作符");
        }
        printf("\n");
    }
}

void hebing() {
    printf("输入第一个文件名称:");
    char filename1[100];
    scanf("%s",filename1);
    printf("\n");
    FILE *fp1 = fopen(filename1, "rb");
    if (fp1 == NULL) {
        printf("文件打开失败");
        return;
    }
    
    printf("输入第二个文件名称:");
    char filename2[100];
    scanf("%s",filename2);
    printf("\n");
    FILE *fp2 = fopen(filename2, "rb");
    if (fp2 == NULL) {
        printf("文件打开失败");
        return;
    }
    
    printf("输入合并后文件名称:");
    char filename3[100];
    scanf("%s",filename3);
    printf("\n");
    FILE *fp3 = fopen(filename3, "wb");
    if (fp3 == NULL) {
        printf("文件打开失败");
        return;
    }
    //写入第一个文件
    if (num_parts == count) {
        count *= 2;
        void *temp = realloc(inventory, count * sizeof(struct part));
        inventory = temp;
    }
    struct part *p = inventory;
    size_t n;
    while ((n = fread(p, sizeof(struct part), count, fp1)) > 0) {
        num_parts += n;
        p += n;
    }
    fclose(fp1);
    
    //写入第二个文件
    if (num_parts == count) {
        count *= 2;
        void *temp = realloc(inventory, count * sizeof(struct part));
        inventory = temp;
    }
    
    while (1) {
        struct part *temp = malloc(sizeof(struct part));
        size_t m = fread(temp, sizeof(struct part), 1, fp2);
        if (m == 0) {
            break;
        }else{
            int number = find_part(temp->number);
            if (number > -1) {
                //已经存在了
                inventory[number].on_hand += temp->on_hand;
            }else{
                strncpy(inventory[num_parts].name,temp->name,NAME_LEN);
                inventory[num_parts].number = temp->number;
                inventory[num_parts].on_hand = temp->on_hand;
                num_parts++;
            }
        }
    }
    fclose(fp2);
    
    //写入合并的文件
    fwrite(inventory, sizeof(struct part), num_parts, fp3);
    fclose(fp3);
    printf("合并完成");
}

void input() {
    printf("输入导入的文件名:");
    char filename[100];
    scanf("%s",filename);
    printf("\n");
    
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("文件打开失败");
    }else{
        if (num_parts == count) {
            count *= 2;
            void *temp = realloc(inventory, count * sizeof(struct part));
            inventory = temp;
        }
        struct part *p = inventory;
        size_t n;
        while ((n = fread(p, sizeof(struct part), count, fp)) > 0) {
            num_parts += n;
            p += n;
        }
        fclose(fp);
        printf("数据导入完成");
    }
}

void output() {
    if (num_parts > 0) {
        printf("输入导出的文件名:");
        char filename[100];
        scanf("%s",filename);
        printf("\n");
        
        FILE *fp = fopen(filename, "wb");
        fwrite(inventory, sizeof(struct part), num_parts, fp);
        fclose(fp);
        printf("数据导出完成");
    }
}

int find_part(int number) {
    int i;
    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(void) {
    int part_number;

    if (num_parts == count) {
        count *= 2;
        printf("已存满，扩容到%d\n",count);
        void *temp = realloc(inventory, count * sizeof(struct part) );
        if (temp == NULL) {
            printf("已存满，不能存更多了\n");
        }
        inventory = temp;
    }
    printf("输入号码:");
    scanf("%d", &part_number);
    
    if (find_part(part_number) >= 0) {
        printf("号码已经存在\n");
        return;
    }
    inventory[num_parts].number = part_number;
    printf("输入名称:");
    read_line(inventory[num_parts].name,NAME_LEN);
    printf("输入数量:");
    scanf("%d",&inventory[num_parts].on_hand);
    num_parts++;
}

void search(void) {
    int i,number;
    
    printf("输入号码:");
    scanf("%d",&number);
    i = find_part(number);
    if (i >= 0) {
        printf("名称:%s\n",inventory[i].name);
        printf("数量:%d\n",inventory[i].on_hand);
    }else{
        printf("没有找到\n");
    }
}

void update(void) {
    int i,number,change;
    
    printf("输入号码：");
    scanf("%d",&number);
    i = find_part(number);
    if (i >= 0) {
        printf("输入要改变的数量:");
        scanf("%d",&change);
        inventory[i].on_hand += change;
    }else{
        printf("没有找到\n");
    }
}

void delete(void) {
    int i,number;
    printf("输入号码：");
    scanf("%d",&number);
    i = find_part(number);
    while (i > -1&&i + 1 < num_parts) {
        inventory[i] = inventory[i+1];
        i++;
    }
    if (i > -1) {
        num_parts--;
    }
}

int compare_part(const void *p,const void *q) {
    return ((struct part *)p)->number - ((struct part *)q)->number;
}

void print(void) {
    int i;
    printf("号码    名称    数量\n");
    qsort(inventory, num_parts, sizeof(struct part), compare_part);
    for (i = 0; i < num_parts; i++) {
        printf("%2d   %-25s%5d\n",inventory[i].number,inventory[i].name,inventory[i].on_hand);
    }
}


