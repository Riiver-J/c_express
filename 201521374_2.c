#include <stdio.h>  // printf,scanf사용을 위한 header
void pri(int N) {   // 소수판별 및 출력 함수 정의
        int i, j;   // for문에 사용할 변수
        for (i = 2; i <= N; i++) {  // i를 2부터 N까지 1씩 증가시키며 반복 수행
            for (j = 2; j <= i - 1; j++) {  // j를 2부터 i-1까지 1씩 증가시키며 반복 수행
                        if (i%j == 0) { // 소수가 아닌(나누어떨어짐) 수일 경우
                            break;  // 루프 탈출
                        }
                }
                if (i == j) {   // 소수라면
                        printf("%d ", i);   // 소수 출력
                }
        }
        printf("\n");   // 가독성을 위함
}
int main() {    // main 시작
    int num=0;  // 입력받을 변수
    char o;     // 프로그램 계속실행or종료를 위한 변수
    while(1){   // 반복문 시작
        printf("2이상의 정수를 입력하세요 : "); // 사용자로부터 값을 입력받기위한 지시사항
        scanf("%d", &num);  // 변수 num에 int로 저장
        pri(num);   // pri함수 사용
        getchar();  // c에서는 enter도 입력문자로 인식하므로 잘못된 문구출력방지
        printf("프로그램을 종료하시겠습니까? (y/n)\n"); // 프로그램 종료 or 실행 여부 지시사항
		scanf("%c", &o);    // char로 o에 저장
		if (o == 'n' || o == 'N')   // n or N일경우
		{
			continue;   // 프로그램 다시 실행
		}
		else if(o == 'y' || o == 'Y')   // y or Y일경우
		{
			break;  // 루프 탈출
		}
		else    // 이외의 값을 받은경우
		{
			printf("잘못입력하였습니다. 다시 입력해주세요\n");  // 예외처리
			continue;   // 다시 입력받음
		}
    }
        return 0;   // 반환값
}