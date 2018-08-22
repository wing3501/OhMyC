//
//  justify.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/7/10.
//  Copyright © 2018年 styf. All rights reserved.
//

#include "justify.h"
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int justify(void) {
    char word[MAX_WORD_LEN+2];
    unsigned long word_len;
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN) {
            word[MAX_WORD_LEN] = '*';
        }
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}
