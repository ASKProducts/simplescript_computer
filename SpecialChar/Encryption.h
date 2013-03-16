//
//  Encryption.h
//  SpecialChar
//
//  Created by stephen kaufer on 8/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SpecialChar_Encryption_h
#define SpecialChar_Encryption_h
#include "Data.h"

typedef struct{
    eight_byte number;
    String string;
}num2str;
num2str num2strEncrypt(eight_byte num);



num2str num2strEncrypt(eight_byte num){
    num2str n2s;
    
    n2s.number = num;
    
    return n2s;
}


#endif
