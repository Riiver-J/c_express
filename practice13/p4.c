#include <stdio.h>
#include <string.h>

#define SIZE 3

typedef struct contact {
	char name[100];
	char home_phone[100];
	char cell_phone[100];
}CONTACT;

int search_name(CONTACT* p, char* name);

int main(void)
{
	CONTACT list[5];
	int i;
	char name[100];

	for (i = 0; i < SIZE; i++) {
		printf("이름을 입력하시오:");
		scanf("%s", list[i].name);
		printf("집전화번호를 입력하시오:");
		scanf("%s", list[i].home_phone);
		printf("휴대폰 번호를 입력하시오:");
		scanf("%s", list[i].cell_phone);
		printf("\n");
	}
	printf("검색할 이름을 입력하시오:");
	scanf("%s", name);

	search_name(list, name);

	return 0;
}

int search_name(CONTACT* p, char* name)
{
	int i;

	for (i = 0; i < SIZE; i++) {
		if (strcmp(name, (p + i)->name) == 0) {
			printf("집전화번호: %s\n", (p + i)->home_phone);
			printf("휴대폰번호: %s\n", (p + i)->cell_phone);
			return 1;
		}
	}
	printf("검색이 실패하였습니다.\n");
	return 0;
}
