#ifndef ___BinTree
#define ___BinTree
#include "Member.h"

// 노드
typedef struct __bnode {
	Member data;
	struct __bnode* left;
	struct __bnode* right;
}BinNode;

BinNode* Search(BinNode* p, const Member* x);	// 검색
BinNode* Add(BinNode* p, const Member* x);		// 노드 삽입
int Remove(BinNode** root, const Member* x);	// 노드 삭제
void PrintTree(const BinNode* p);				// 모든 노드 출력
void FreeTree(BinNode* p);						// 모든 노드 삭제 (free)

#endif // !___BinTree

