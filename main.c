#include <stdio.h>
#include <stdlib.h>	  // system
#include <stdbool.h>	  // bool, true, false
#include "student.h"


int main(void)
{
    int menu = 0, count = 0;

    // ����ü �迭
    STUDENT	arr[arrMAXSIZE] = { 0 };
    while(1){
        system("cls");
        printf("  ##### �л� ����(����) ���� #####\n\n");
        printf("1)�л� ���� �Է�\n");
        printf("2)�л� ���� ���\n");
        printf("3)�л� ���� �˻�\n");
        printf("4)���α׷� ����\n\n");
        printf("�޴� ����: ");
        scanf_s("%d%*c", &menu);

        switch (menu) {
            case 1: count = input(arr, count);
                rank(arr, count);
                break;
            case 2: output(arr, count);     break;
            case 3: search(arr, count);     break;
            case 4: printf("���α׷� ����!!!\n");
                exit(0);
        
        }
        system("pause");
    }

    return 0;
}
