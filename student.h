#pragma once
#define arrMAXSIZE 50	// 학생 수

// 비트 필드 구조체 형식 정의
typedef  struct _bitFieldDATE {
    unsigned int  year : 16;	// 0 ~ 9999
    unsigned int  month : 4;	// 1 ~ 12
    unsigned int  day : 5;		// 1 ~ 31
    unsigned int : 7;		// Reserved	// Padding Bits
} bitFieldDATE;

// 구조체 설계: PERSON(struct  _person)
typedef	 struct _person {
    // int		Birthday[12];	// 생년월일: 8자리(20001231)
    bitFieldDATE	Birthday;	// 생년월일
    char		Gender[8];	// 성별: 남자, 여자
    char		Name[12];	// 이름: 홍길동, 을지문덕
    char		ID[16];		// 계정
    char		PASS[16];	// 비밀번호
    char		Tel[16];	// 연락처: 010-1009-1004
    char		Addr[80];	// 주소
} PERSON;

// 구조체 설계: SCORE(struct  _score)
typedef struct _score {
    int	kor, eng, math, tot, rank;
    float	ave;
} SCORE;

// 구조체 설계: STUDENT(struct  _student)
typedef struct _student {
    PERSON		info;
    SCORE		score;
} STUDENT;

// 함수 원형 선언
int	input(STUDENT* pStudent, int num);
void	output(STUDENT* pStudent, int num);
void rank(STUDENT* p, int num);
void search(STUDENT* p, int num);
