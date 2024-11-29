#include <stdio.h>
#include <stdlib.h>	  // system
#include <stdbool.h>	  // bool, true, false
#include "student.h"


int main(void)
{
    int menu = 0, count = 0;

    // 구조체 배열
    STUDENT	arr[arrMAXSIZE] = { 0 };
    while(1){
        system("cls");
        printf("  ##### 학생 정보(성적) 관리 #####\n\n");
        printf("1)학생 정보 입력\n");
        printf("2)학생 정보 출력\n");
        printf("3)학생 석차 검색\n");
        printf("4)프로그램 종료\n\n");
        printf("메뉴 선택: ");
        scanf_s("%d%*c", &menu);

        switch (menu) {
            case 1: count = input(arr, count);
                rank(arr, count);
                break;
            case 2: output(arr, count);     break;
            case 3: search(arr, count);     break;
            case 4: printf("프로그램 종료!!!\n");
                exit(0);
        
        }
        system("pause");
    }

    return 0;
}
