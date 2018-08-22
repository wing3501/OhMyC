//
//  debug.h
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/11.
//  Copyright © 2018年 styf. All rights reserved.
//

#ifndef debug_h
#define debug_h

#include <stdio.h>
#ifdef DEBUGG
#define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
#else
#define PRINT_DEBUG(n)
#endif

extern int my_debug_int;

extern int my_debug_fun(void);



inline double average(double a,double b) {
    return (a + b) / 2;
}

struct haha;

#endif /* debug_h */
