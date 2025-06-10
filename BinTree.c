#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode* AllocBinNode(void) {
	return calloc(1, sizeof(BinNode));
} // 노드를 동적으로 할당



static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right) {
	n->data = *x;		// 데이터
	n->left = left;		// 왼쪽 포인터
	n->right = right;	// 오른쪽 포인터
} // 노드 멤버값 설정

BinNode* Search(BinNode* p, const Member* x) {
	int cond;
	if (p == NULL)
		return NULL;		// 검색 실패
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;			// 검색 성공
	else if (cond < 0)
		Search(p->left, x);
	else
		Search(p->right, x);
} // 노드 검색하는 함수

BinNode* Add(BinNode* p, const Member* x) {
	int cond;
	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("[오류] %d는(은) 이미 등록되어 있습니다.\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
} // 노드 삽입

int Remove(BinNode** root, const Member* x) {
	BinNode* next;							// 삭제될 노드를 대체할 노드
	BinNode* temp;							// 삭제될 노드를 임시 저장할 포인터
	BinNode** left;							// 후계자 노드를 찾을 때 사용할 포인터의 포인터
	BinNode** p = root;						// 현재 탐색중 노드의 포인터를 가리키는 포인터, 초기값은 루트 노드의 주소

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("[오류] %d는(은) 등록되어 있지 않습니다.\n", x->no);
			return -1;						// 없는 키를 삭제하려 했을 경우
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;							// 검색 성공하여 while break
		else if (cond < 0)
			p = &((*p)->left);				// 왼쪽 서브트리에서 검색
		else
			p = &((*p)->right);				// 오른쪽 서브트리에서 검색
	}

	if ((*p)->left == NULL)					// 왼쪽 자식이 없다면 (현재 값이 가장 큰 값이라면)
		next = (*p)->right;					// 오른쪽 자식을 후계자로 지정 (삭제할 노드가 leaf or 오른쪽만 있는 경우)
	else {									// 왼쪽 자식이 있다면, 왼쪽 서브트리에서 가장 큰 값(가장 오른쪽)을 찾는다
		left = &((*p)->left);				// left를 현재 삭제할 노드의 왼쪽 자식 포인터의 "주소"로 초기화
		while ((*left)->right != NULL)		// 오른쪽 자식이 없을 때까지 (지가 제일 짱일 때 까지)
			left = &(*left)->right;			// 계속 오른쪽으로 이동하면서 왼쪽 서브트리의 가장 큰 값을 찾는다
		next = *left;						// 드디어 후계자가 정해졌습니다 (next: 후계자)
		*left = (*left)->left;				// 후계자 노드의 원래 위치에 후계자의 왼쪽 자식을 연결 (후계자 노드가 제거)
		next->left = (*p)->left;			// 후계자 노드의 왼쪽 링크를 삭제할 노드의 왼쪽 자식에 연결
		next->right = (*p)->right;			// 오른쪽도 마찬가지.
	}
	temp = *p;								// 삭제할 노드 임시 저장
	*p = next;								// 삭제할 노드의 위치(*p)에 후계자 노드 (next)를 연결
	free(temp);								// temp 해제

	return 0;
}

void PrintTree(const BinNode* p) {
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p) {
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}
