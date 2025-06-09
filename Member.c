#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Member.h"

// 회원 번호 비교 함수
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

// 회원 이름 비교 함수
int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
}

// 회원 데이터(번호, 이름) 출력(줄 바꿈x)
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

// 회원 데이터(번호, 이름) 출력(줄 바꿈x)
void PrintLmMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}

// 회원 데이터(번호, 이름) 읽음
Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("%s하는 데이터를 입력하시오.\n", message);
	if (sw & MEMBER_NO) {
		printf("번호: ");
		scanf("%d", &temp.no);
	}
	if (sw & MEMBER_NAME) {
		printf("이름: ");
		scanf("%s", temp.name);
	}
	return temp;
}