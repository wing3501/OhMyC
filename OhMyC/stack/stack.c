//
//  stack.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/17.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
//struct node {
//    int value;
//    struct node *next;
//};
//
//struct node *top = NULL;
//
//void make_empty(void) {
//    struct node *temp = NULL;
//    while (top != NULL) {
//        temp = top;
//        top = top->next;
//        free(temp);
//    }
//}
//
//bool is_empty(void) {
//    return top == NULL;
//}
//
//void push(int i) {
//    struct node *new_node = malloc(sizeof(struct node));
//    if (new_node != NULL) {
//        new_node->next = top;
//        new_node->value = i;
//        top = new_node;
//    }else{
//        printf("内存不足");
//    }
//}
//
//int pop(void){
//    if (is_empty()) {
//        return 0;
//    }else{
//        struct node *temp = top;
//        top = top->next;
//        int i = temp->value;
//        free(temp);
//        return i;
//    }
//}



