//
//  queue.h
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/19.
//  Copyright © 2018年 styf. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>

struct queue_type;

typedef struct queue_type *Queue;

Queue queue_create(void);
void queue_push(Queue queue,int value);
int queue_pop(Queue queue);
int queue_firstone(Queue queue);
int queue_lastone(Queue queue);
bool queue_is_empty(Queue queue);

#endif /* queue_h */
