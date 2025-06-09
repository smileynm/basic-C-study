#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

// 노드를 동적으로 할당
static BinNode* AllocBinNode(void) {
	return calloc(1, sizeof(BinNode));
}

// 노드 멤버값 설정
static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right) {
	n->data = *x;		// 데이터
	n->left = left;		// 왼쪽 포인터
	n->right = right;	// 오른쪽 포인터
}