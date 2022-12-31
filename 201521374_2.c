#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>      // 표준 라이브러리함수 헤더
#include <string.h>    // strtok 함수가 선언된 헤더 파일
#include <stdlib.h>     // 헤더

int main()  // main함수

{

    char s1[100];    // 크기가 30인 char형 배열을 선언하고 문자열 할당
    char *p = (char *)malloc(strlen(s1) + 1);    // 문자열의 길이를 계산하여 크기에 맞게 기억공간을 동적할당
    char* sArr[10] = { NULL, };  // 크기가 10인 문자열 포인터 배열을 선언하고 NULL로 초기화
    
    printf("문자열 입력: ");    // 사용자로부터 문자열 입력받기
    gets(s1);   // s1에 저장

    int i = 0;                     // 문자열 포인터 배열의 인덱스로 사용할 변수
    char* ptr = strtok(s1, " .,");   // 공백 문자열을 기준으로 문자열을 자름

    while (ptr != NULL)            // 자른 문자열이 나오지 않을 때까지 반복
    {
        sArr[i] = ptr;             // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
        i++;                       // 인덱스 증가
        ptr = strtok(NULL, " .,");   // 다음 문자열을 잘라서 포인터를 반환
    }

    printf("***** 단어리스트 *****\n"); // 잘라서 보관한 단어들 리스트 출력

for (int i = 0; i < 10; i++)    // 반복문으로 인덱스 탐색
    {
        if (sArr[i] != NULL)           // 문자열 포인터 배열의 요소가 NULL이 아닐 때만
            printf("%s\n", sArr[i]);   // 문자열 포인터 배열에 인덱스로 접근하여 각 문자열 출력
    }

    free(p);    // 동적 메모리 해제
    return 0;   // 리턴값

}