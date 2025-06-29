#ifndef ___Member
#define ___Member

// 회원 데이터
typedef	struct {
	int no;			// 번호
	char name[20];	// 이름
} Member;

#define	MEMBER_NO		1	// 번호를 나타내는 정수값
#define	MEMBER_NAME		2	// 이름을 나타내는 정수값

int MemberNoCmp(const Member* x, const Member* y);		// 회원 번호 비교 함수
int MemberNameCmp(const Member* x, const Member* y);	// 회원 이름 비교 함수
void PrintMember(const Member* x);						// 회원 데이터를 출력 (줄 바꿈x)
void PrintLmMember(const Member* x);					// 회원 데이터를 출력 (줄 바꿈o)
Member ScanMember(const char* message, int sw);			// 회원 데이터를 읽는 함수

#endif // !___Member

