//
//  main.cpp
//  chosung-search
//
//  Created by 이한범 on 09/02/2020.
//  Copyright © 2020 Hanbum.Lee. All rights reserved.
//

#include <iostream>
#include <locale>
#include <string>

using namespace std;

wchar_t consonants[] = {
   L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ',
   L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ',
   L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ',
   L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ',
   L'ㅌ', L'ㅍ', L'ㅎ'
};

// (http://blog.naver.com/PostView.nhn?blogId=jincyber09&logNo=80100554626)
// first hangeul code = 44032 ('가')
// 중성이 바뀌는 경우 코드값 차 : 28
// 초성이 바뀌는 경우 코드값 차 : 21*28 = 588

const int firstHangeul = 44032;

int GetChosung(char input)
{
   return (input - firstHangeul) / 588;
}

int main(int argc, const char * argv[]) {
    return 0;
}

