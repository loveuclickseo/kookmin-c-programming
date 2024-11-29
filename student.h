#pragma once
#define arrMAXSIZE 50	// �л� ��

// ��Ʈ �ʵ� ����ü ���� ����
typedef  struct _bitFieldDATE {
    unsigned int  year : 16;	// 0 ~ 9999
    unsigned int  month : 4;	// 1 ~ 12
    unsigned int  day : 5;		// 1 ~ 31
    unsigned int : 7;		// Reserved	// Padding Bits
} bitFieldDATE;

// ����ü ����: PERSON(struct  _person)
typedef	 struct _person {
    // int		Birthday[12];	// �������: 8�ڸ�(20001231)
    bitFieldDATE	Birthday;	// �������
    char		Gender[8];	// ����: ����, ����
    char		Name[12];	// �̸�: ȫ�浿, ��������
    char		ID[16];		// ����
    char		PASS[16];	// ��й�ȣ
    char		Tel[16];	// ����ó: 010-1009-1004
    char		Addr[80];	// �ּ�
} PERSON;

// ����ü ����: SCORE(struct  _score)
typedef struct _score {
    int	kor, eng, math, tot, rank;
    float	ave;
} SCORE;

// ����ü ����: STUDENT(struct  _student)
typedef struct _student {
    PERSON		info;
    SCORE		score;
} STUDENT;

// �Լ� ���� ����
int	input(STUDENT* pStudent, int num);
void	output(STUDENT* pStudent, int num);
void rank(STUDENT* p, int num);
void search(STUDENT* p, int num);
