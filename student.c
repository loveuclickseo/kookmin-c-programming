#include <stdio.h>
#include <string.h>
#include "student.h"

// 학생 정보와 성적 점수 입력
int	input(STUDENT* p, int num) {
   
    for (int i = num; i < arrMAXSIZE; ++i) {
        printf("\n%d번째 학생 정보를 입력하세요.\n", i + 1);
        printf("아 이 디(종료: end): ");
        gets_s(p[i].info.ID, sizeof(p[i].info.ID));	// gets(pStudent[i].info.ID);
        if (strcmp(p[i].info.ID, "end") == 0)
            break;

        printf("비밀번호: ");
        gets_s(p[i].info.PASS, sizeof(p[i].info.PASS)); // gets(pStudent[i].info.Name);

        printf("이    름: ");
        gets_s(p[i].info.Name, sizeof(p[i].info.Name)); // gets(pStudent[i].info.Name);

        printf("성별(예: 남자):  ");
        gets_s(p[i].info.Gender, sizeof(p[i].info.Gender));
        // gets(pStudent[i].info.Gender);

        // 비트 필드 구조체 멤버에 데이터 저장
        int	year, month, day;
        printf("생년월일(예: 2000 12 31) : ");
        scanf_s("%d %d %d%*c", &year, &month, &day);

        p[i].info.Birthday.year = year;
        p[i].info.Birthday.month = month;
        p[i].info.Birthday.day = day;

        printf("연 락 처: ");
        gets_s(p[i].info.Tel, sizeof(p[i].info.Tel)); // gets(pStudent[i].info.Tel);

        printf("주    소: ");
        gets_s(p[i].info.Addr, sizeof(p[i].info.Addr));	// gets(p[i].info.Addr);

        // 2) 학생 성적 점수 입력 처리
        printf("\n%d번째 학생 성적을 입력하세요.\n", i + 1);
        printf("국어 점수: ");
        scanf_s("%d", &p[i].score.kor);		// scanf("%d", &p[i].score.korkor);

        printf("영어 점수: ");
        scanf_s("%d", &p[i].score.eng);		// scanf("%d", &p[i].score.koreng);

        printf("수학 점수: ");
        scanf_s("%d%*c", &p[i].score.math);	// scanf("%d", &p[i].score.kormath);

        p[i].score.tot = p[i].score.kor + p[i].score.eng + p[i].score.math;
        p[i].score.ave = (float)p[i].score.tot / 3;

        p[i].score.rank = 0; 
        ++num;
    }
    return num;
}

// 학생 정보와 성적 점수 출력
void	output(STUDENT* p, int num) {
    for (int i = 0; i < num; ++i, ++p) {
        printf("\n##### 학생 정보와 성적 점수 결과 ##### \n");
        printf("아 이 디: %-10s / 패스워드: %-10s\n", p->info.ID, p->info.PASS);
        printf("이    름: %-10s / 성    별: %-6s / 생년월일: %4d년 %02d월 %02d일\n",
            p->info.Name, p->info.Gender,
            p->info.Birthday.year, p->info.Birthday.month, p->info.Birthday.day);

        printf("연 락 처: %-16s \n", p->info.Tel);
        printf("주    소: %-80s \n", p->info.Addr);

        printf("성적정보: 국어(%03d), 영어(%03d), 수학(%03d), 총점(%03d), 평균(%5.1f), 석차(%03d) \n",
            p->score.kor, p->score.eng, p->score.math, p->score.tot, p->score.ave, p->score.rank);
    }
}

void rank(STUDENT* p, int num) {

    for (int i = 0; i < num; i++) {
        p[i].score.rank = 1;
        for (int j = 0; j < num; j++) {
            if (p[i].score.tot < p[j].score.tot) {
                ++p[i].score.rank;
            }
             
        }

    }

};
void search(STUDENT* p, int num) {

    int wanted = 0;
    printf("찾고 싶은 석차: ");
    scanf_s("%d", &wanted);
    for (int i = 0; i < num; i++) {
        if (p[i].score.rank == wanted) wanted = i;
    }

    printf("\n##### 학생 정보와 성적 점수 결과 ##### \n");
    printf("아 이 디: %-10s / 패스워드: %-10s\n", p[wanted].info.ID, p[wanted].info.PASS);
    printf("이    름: %-10s / 성    별: %-6s / 생년월일: %4d년 %02d월 %02d일\n",
        p[wanted].info.Name, p[wanted].info.Gender,
        p[wanted].info.Birthday.year, p[wanted].info.Birthday.month, p[wanted].info.Birthday.day);

    printf("연 락 처: %-16s \n", p[wanted].info.Tel);
    printf("주    소: %-80s \n", p[wanted].info.Addr);

    printf("성적정보: 국어(%03d), 영어(%03d), 수학(%03d), 총점(%03d), 평균(%5.1f), 석차(%03d) \n",
        p[wanted].score.kor, p[wanted].score.eng, p[wanted].score.math, p[wanted].score.tot, p[wanted].score.ave, p[wanted].score.rank);
};