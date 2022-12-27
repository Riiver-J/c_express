#include <stdio.h>  // printf,scanf사용을 위한 header
int main(void)  // main 시작
{
    char season=0; // 문자형태로 입력받을것이므로 char & 변수 초기화
    printf("과일을 추천받고싶은 계절을 다음의 알파벳으로 입력해주세요.(봄=S,여름=M,가을=F,겨울=W): ");  // 지시사항
    scanf("%c", &season);   // char를 season에 저장
    switch(season)  // switch문 시작
    {
    case 'S' :  // 사용자가 대문자 'S'를 입력시
    case 's' :  // 사용자가 소문자 's'를 입력시
        printf("봄에 어울리는 제철과일은 딸기,한라봉,매실입니다."); // 추천음식 출력
        break;  // switch문 빠져나옴
    case 'M' :  // 사용자가 대문자 'M'를 입력시
    case 'm' :  // 사용자가 소문자 'm'를 입력시
        printf("여름에 어울리는 제철과일은 참외,복숭아,자두,수박,포도입니다."); // 추천음식 출력
        break;  // switch문 빠져나옴
    case 'F' :  // 사용자가 대문자 'F'를 입력시
    case 'f' :  // 사용자가 소문자 'f'를 입력시
        printf("가을에 어울리는 제철과일은 블루베리,배,석류,사과입니다."); // 추천음식 출력
        break;  // switch문 빠져나옴
    case 'W' :  // 사용자가 대문자 'W'를 입력시
    case 'w' :  // 사용자가 소문자 'w'를 입력시
        printf("겨울에 어울리는 제철과일은 유자,귤,석류입니다."); // 추천음식 출력
        break;  // switch문 빠져나옴
    default :   // 이외의 입력값일경우
        printf("올바르지 않은 형식입니다. 다시 입력해주세요");  // 예외처리
    }
}       
