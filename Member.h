#ifndef ___Member
#define ___Member

// ȸ�� ������
typedef	struct {
	int no;			// ��ȣ
	char name[20];	// �̸�
} Member;

#define	MEMBER_NO		1	// ��ȣ�� ��Ÿ���� ������
#define	MEMBER_NAME		2	// �̸��� ��Ÿ���� ������

int MemberNoCmp(const Member* x, const Member* y);		// ȸ�� ��ȣ �� �Լ�
int MemberNameCmp(const Member* x, const Member* y);	// ȸ�� �̸� �� �Լ�
void PrintMember(const Member* x);						// ȸ�� �����͸� ��� (�� �ٲ�x)
void PrintLmMember(const Member* x);					// ȸ�� �����͸� ��� (�� �ٲ�o)
Member ScanMember(const char* message, int sw);			// ȸ�� �����͸� �д� �Լ�

#endif // !___Member

