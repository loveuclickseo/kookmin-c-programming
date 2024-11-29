#include <stdio.h>
#include <string.h>
#include "student.h"

// �л� ������ ���� ���� �Է�
int	input(STUDENT* p, int num) {
   
    for (int i = num; i < arrMAXSIZE; ++i) {
        printf("\n%d��° �л� ������ �Է��ϼ���.\n", i + 1);
        printf("�� �� ��(����: end): ");
        gets_s(p[i].info.ID, sizeof(p[i].info.ID));	// gets(pStudent[i].info.ID);
        if (strcmp(p[i].info.ID, "end") == 0)
            break;

        printf("��й�ȣ: ");
        gets_s(p[i].info.PASS, sizeof(p[i].info.PASS)); // gets(pStudent[i].info.Name);

        printf("��    ��: ");
        gets_s(p[i].info.Name, sizeof(p[i].info.Name)); // gets(pStudent[i].info.Name);

        printf("����(��: ����):  ");
        gets_s(p[i].info.Gender, sizeof(p[i].info.Gender));
        // gets(pStudent[i].info.Gender);

        // ��Ʈ �ʵ� ����ü ����� ������ ����
        int	year, month, day;
        printf("�������(��: 2000 12 31) : ");
        scanf_s("%d %d %d%*c", &year, &month, &day);

        p[i].info.Birthday.year = year;
        p[i].info.Birthday.month = month;
        p[i].info.Birthday.day = day;

        printf("�� �� ó: ");
        gets_s(p[i].info.Tel, sizeof(p[i].info.Tel)); // gets(pStudent[i].info.Tel);

        printf("��    ��: ");
        gets_s(p[i].info.Addr, sizeof(p[i].info.Addr));	// gets(p[i].info.Addr);

        // 2) �л� ���� ���� �Է� ó��
        printf("\n%d��° �л� ������ �Է��ϼ���.\n", i + 1);
        printf("���� ����: ");
        scanf_s("%d", &p[i].score.kor);		// scanf("%d", &p[i].score.korkor);

        printf("���� ����: ");
        scanf_s("%d", &p[i].score.eng);		// scanf("%d", &p[i].score.koreng);

        printf("���� ����: ");
        scanf_s("%d%*c", &p[i].score.math);	// scanf("%d", &p[i].score.kormath);

        p[i].score.tot = p[i].score.kor + p[i].score.eng + p[i].score.math;
        p[i].score.ave = (float)p[i].score.tot / 3;

        p[i].score.rank = 0; 
        ++num;
    }
    return num;
}

// �л� ������ ���� ���� ���
void	output(STUDENT* p, int num) {
    for (int i = 0; i < num; ++i, ++p) {
        printf("\n##### �л� ������ ���� ���� ��� ##### \n");
        printf("�� �� ��: %-10s / �н�����: %-10s\n", p->info.ID, p->info.PASS);
        printf("��    ��: %-10s / ��    ��: %-6s / �������: %4d�� %02d�� %02d��\n",
            p->info.Name, p->info.Gender,
            p->info.Birthday.year, p->info.Birthday.month, p->info.Birthday.day);

        printf("�� �� ó: %-16s \n", p->info.Tel);
        printf("��    ��: %-80s \n", p->info.Addr);

        printf("��������: ����(%03d), ����(%03d), ����(%03d), ����(%03d), ���(%5.1f), ����(%03d) \n",
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
    printf("ã�� ���� ����: ");
    scanf_s("%d", &wanted);
    for (int i = 0; i < num; i++) {
        if (p[i].score.rank == wanted) wanted = i;
    }

    printf("\n##### �л� ������ ���� ���� ��� ##### \n");
    printf("�� �� ��: %-10s / �н�����: %-10s\n", p[wanted].info.ID, p[wanted].info.PASS);
    printf("��    ��: %-10s / ��    ��: %-6s / �������: %4d�� %02d�� %02d��\n",
        p[wanted].info.Name, p[wanted].info.Gender,
        p[wanted].info.Birthday.year, p[wanted].info.Birthday.month, p[wanted].info.Birthday.day);

    printf("�� �� ó: %-16s \n", p[wanted].info.Tel);
    printf("��    ��: %-80s \n", p[wanted].info.Addr);

    printf("��������: ����(%03d), ����(%03d), ����(%03d), ����(%03d), ���(%5.1f), ����(%03d) \n",
        p[wanted].score.kor, p[wanted].score.eng, p[wanted].score.math, p[wanted].score.tot, p[wanted].score.ave, p[wanted].score.rank);
};