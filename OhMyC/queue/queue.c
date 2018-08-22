//
//  queue.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/19.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

struct queue_node{
    int value;
    struct queue_node *prev;
};

struct queue_type {
    struct queue_node *first;
    struct queue_node *last;
};

Queue queue_create(void) {
    Queue queue = malloc(sizeof(struct queue_type));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void queue_push(Queue queue,int value) {
    struct queue_node *new_node = malloc(sizeof(struct queue_node));
    new_node->value = value;
    if (queue_is_empty(queue)) {
        new_node->prev = NULL;
        queue->first = new_node;
        queue->last = new_node;
    }else{
        new_node->prev = queue->last;
        queue->last = new_node;
    }
}

int queue_pop(Queue queue) {
    if (queue_is_empty(queue)) {
        return -1;
    }else{
        struct queue_node *temp = queue->last->prev;
        if (temp == NULL) {
            int value = queue->last->value;
            free(queue->last);
            queue->first = NULL;
            queue->last = NULL;
            return value;
        }else{
            while (temp->prev != NULL) {
                temp = temp->prev;
            }
            int value = temp->prev->value;
            free(temp->prev);
            temp->prev = NULL;
            queue->first = temp;
            return value;
        }
    }
}

int queue_firstone(Queue queue) {
    if (queue->first == NULL) {
        return -1;
    }else{
        return queue->first->value;
    }
}

int queue_lastone(Queue queue) {
    if (queue->last == NULL) {
        return -1;
    }else{
        return queue->last->value;
    }
}

bool queue_is_empty(Queue queue) {
    return queue->first == NULL;
}

//===========================================================数组实现

//#define QUEUE_CONTENT_MAX 10
//
//struct queue_type{
//    int index_to_push;
//    int index_to_pop;
//    int count;
//    int *contents;
//};
//
//Queue queue_create(void) {
//    Queue q = malloc(sizeof(struct queue_type));
//    q->contents = malloc(sizeof(int) * QUEUE_CONTENT_MAX);
//    return q;
//}
//
//void queue_make_empty(Queue queue) {
//    queue->index_to_push = 0;
//    queue->index_to_pop = 0;
//    queue->count = 0;
//}
//
//void queue_push(Queue queue,int value) {
//    if (queue->count == QUEUE_CONTENT_MAX) {
//        printf("队列置空");
//        queue_make_empty(queue);
//    }else{
//        if (queue->index_to_push == QUEUE_CONTENT_MAX) {
//            queue->index_to_push = 0;
//        }
//        queue->contents[queue->index_to_push++] = value;
//        queue->count++;
//    }
//}
//
//int queue_pop(Queue queue) {
//    if (queue_is_empty(queue)) {
//        printf("队列置空");
//        queue_make_empty(queue);
//        return -1;
//    }else{
//        if (queue->index_to_pop == QUEUE_CONTENT_MAX) {
//            queue->index_to_pop = 0;
//        }
//        int value = queue->contents[queue->index_to_pop++];
//        queue->count--;
//        return value;
//    }
//}
//
//int queue_firstone(Queue queue) {
//    if (queue_is_empty(queue)) {
//        printf("队列为空");
//        return -1;
//    }else{
//        if (queue->count == 1) {
//            return queue->contents[0];
//        }else{
//            return queue->contents[queue->index_to_pop];
//        }
//    }
//}
//int queue_lastone(Queue queue) {
//    if (queue_is_empty(queue)) {
//        printf("队列为空");
//        return -1;
//    }else{
//        if (queue->count == 1) {
//            return queue->contents[0];
//        }else{
//            return queue->contents[queue->index_to_push - 1];
//        }
//    }
//}
//
//bool queue_is_empty(Queue queue) {
//    return queue->count == 0;
//}
