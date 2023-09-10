#ifndef STRING
#include<string>
#endif
#ifndef CAESARCIPHER_HPP
#include"caesarCipher.hpp"
#endif

std::string caesarCipher(std::string text, int shift){
    shift %= 26;

    for(size_t i = 0; i < text.size(); i++){
        if(!('a' <= text[i] && text[i] <= 'z')) continue;

        char newChar = text[i]-'a'+shift;
        if(newChar < 0) newChar = 'z'-'a'+1+newChar;
        newChar %= 'z'-'a'+1;

        text[i] = 'a'+newChar;
    }

    return text;
}
