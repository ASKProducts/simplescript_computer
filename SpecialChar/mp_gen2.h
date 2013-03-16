



#ifndef mp_Gen_2_h
#define mp_Gen_2_h

#include "Data.h"
#include "Autoreleasepool.h"
#include "Dictionary.h"
#include "m_processor.h"

Dictionary _mfbhd;
Dictionary _mfbhd_types;
#define kNumberType 1
#define kStringType 2



#define kVarMax 1000
typedef enum{
    unknownPhraseType = 0,
    stringPhraseType,
    numberPhraseType,
    mathExpPhraseType,
    functionPhraseType,
    
}phraseType;
typedef struct s_phrase{
    phraseType type;
    String contents;
    four_byte wordCount;
    struct s_phrase *innerPhrases;
}phrase;
typedef struct{
    phrase *phrases;
    four_byte phraseCount;
}CodeLine;

#define makeCodeLine(words,count) (Code){words,count}

no_return initProcessor(no_param);
String processmp2Code(String code);
String performLevel1Task(String task,String extra,Code *code,String original);
String performLevel2Task(String task,String extra,Code *code,String original);
String performLevel3Task(String task,String extra,Code *code,String original);
String performLevel4Task(String task,String extra,Code *code,String original);
String performLevel5Task(String task,String extra,Code *code,String original);
CodeLine   breakDownIntoCodeLine(String code);
String foldIntoString(Code arr);

/*
CodeLine breakDownIntoCodeLine(String code){
    eight_byte length = strlen(code);
    CodeLine c;
    c.phraseCount = 1000;
    c.phrases = (phrase*)calloc(1000, sizeof(phrase));
    wordset w = breakDown(code);
    int word = 0;
    char ch;
    for (int i = 0; i<length; i++) {
        char c = code[i];
        if(c == ' ')word++;
    }
}



*/








#endif