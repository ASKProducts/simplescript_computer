//
//  main.c
//  SpecialChar
//
//  Created by stephen kaufer on 8/10/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "Data.h"
#include "Encryption.h"
#include "Autoreleasepool.h"
#include "Dictionary.h"
#include "m_processor.h"
#include "mp_gen2.h"
#define kEndLine ';'

int main (int argc, const char * argv[]){
start:
    startautoreleasepool{
        initProcessor();
        four_byte currentline = 0;
        LOOP{
            currentline++;
            bool broken = NO;
            bool doublebroken = NO;
            String t =calloc(1000,1);
            String line = calloc(1000,1);
            scanf("%s",t);
            if(strcmp(t, "quit") == 0){doublebroken = YES; BREAK_OUT_OF_LOOP;}
            if(strcmp(t, "print_stack") == 0){printDictionaryfbStarting(_fbmd,5);printMainStack(); SKIP_LOOP_COUNT;}
            StrcmpIf(t, ==, "refresh_stack"){endautoreleasepool startautoreleasepool initProcessor();}
            //StrcmpIf(t, ==, "open"){processCode("loop 1;");printf("a.ask:\n");SKIP_LOOP_COUNT;}
            
            if(strcmp(t, "cancel") == 0){broken = YES; SKIP_LOOP_COUNT;}else 
            while (t[strlen(t)-1] != kEndLine) {
                sprintf(line, "%s %s",line,t);
                scanf("%s",t);
                if(strcmp(t, "quit") == 0){doublebroken = YES; BREAK_OUT_OF_LOOP;}
                if(strcmp(t, "cancel") == 0){broken = YES; BREAK_OUT_OF_LOOP;}
            }
            if(broken){printf("line canceled\n\n"); SKIP_LOOP_COUNT;}
            if(doublebroken)BREAK_OUT_OF_LOOP;
            t[strlen(t)-1] = 0;
            sprintf(line, "%s %s",line,t);
            line += 1;
            String s;
            if(strcmp(s = processCode(line), "Success") != 0){printf("\nerror on command %d: %s \n",currentline,s);}
            
        }
        endautoreleasepool
        LOOP{
            String s = malloc(30);
            scanf("%s",s);
            StrcmpIf(s, ==, "end")BREAK_OUT_OF_LOOP;
            StrcmpIf(s, ==, "restart")goto start;
        }
    
    }
    
}


