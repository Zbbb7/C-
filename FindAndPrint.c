#include "main.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

void FindAndPrint() {
    FILE *fp;
    if ((fp = fopen("room.txt", "r")) == NULL) {
        perror("���ļ�ʧ��");
    }
    int count = 0; // ��¼�ṹ������
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF) {
        count++;
    }


    printf("��ʹ�õĲ�ѯ�������£�\n");
    printf("1����һ������ѯ\n");
    printf("2������������ѯ(ѧԺ���������)\n");
    printf("3���˳�\n");
    printf("������Ҫʹ�ù��ܵ���ţ�");

    int choose;
    scanf("%d", &choose);

    if (choose != 1 && choose != 2) {
        printf("��Ч���룡\n");
        return;
    } else if (choose == 1) {
        printf("��ѡ���ѯ����������\n");
        printf("1�������\n");
        printf("2���������\n");
        printf("3���ѷ��䴲λ���\n");
        printf("4���п��ലλ�ķ���\n");
        printf("5��ѧԺ\n");

        int ch1 = 0; // ������Ҫ��ѯ��һ������
        printf("��ѡ��");
        scanf("%d", &ch1);

        if (ch1 == 1) {
            char ch2[10]; // ������Ҫ��ѯ�ķ����
            printf("��������Ҫ��ѯ�ķ���ţ�");
            scanf("%s", ch2);
            int index = 0; // ��������������Ҫ��ѯ�ķ�����Ƿ����
            printf("��ѯ������£�\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].roomnumber, ch2) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("��ѯ�ķ���Ų����ڣ�\n");
            }
        }
        else if (ch1 == 2) {
            char ch3[3]; // ������Ҫ�������
            printf("��������Ҫ��ѯ�ķ������");
            int index = 0; // �������������ѡ��ķ�������Ƿ���ֻ���ȷ
            scanf("%s", ch3);
            printf("��ѯ������£�\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].roomcategory, ch3) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("��ѯ�ķ���������\n");
            }
        }
        else if (ch1 == 3) {
            int index = 0;
            printf("����������£�\n");
            for (int i = 0; i < count; i++) {
                printf("%d\t%s\t%s\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].allocatedbed, apart[i].college);
                index++;
            }
            if (index == 0) {
                printf("δ��ѯ���ѷ��䷿��\n");
            }
        }
        else if (ch1 == 4) {
            int index = 0; // ���������������Ƿ���ڿ��ലλ
            printf("��ѯ������£�\n");
            for (int i = 0; i < count; i++) {
                if (apart[i].sparebed > 0) {
                    printf("%d\t%s\t%s\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("�������п��ലλ�ķ��䣡\n");
            }
        }
        else if (ch1 == 5) {
            char ch4[10]; // ������Ҫ��ѯ��ѧԺ
            printf("��������Ҫ��ѯѧԺ��");
            int index = 0; // �������������ѡ��ķ�������Ƿ���ֻ���ȷ
            scanf("%s", ch4);
            printf("��ѯ������£�\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].college, ch4) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed);
                    index++;
                }
            }
            if (index == 0) {
                printf("��ѯ��ѧԺ�����ڣ�\n");
            }
        } else {
            printf("��ѡ���������ڣ�\n");
        }
    } else if (choose == 2) {
        char ch1[10]; // ����ѡ���ѧԺ
        char ch2[3];  // ����ѡ��ķ������
        printf("����Ҫ���ҵ�ѧԺ��");
        scanf("%s", ch1);
        printf("����Ҫ���ҵķ������");
        scanf("%s", ch2);
        int index = 0; // ���Ҫ���ҵ�Ŀ���Ƿ����
        printf("��ѯ�������:\n");
        for (int i = 0; i < count; i++) {
            if (strcmp(ch1, apart[i].college) == 0 && strcmp(ch2, apart[i].roomcategory) == 0) {
                printf("%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                index++;
            }
        }
        if (index == 0) {
            printf("��ѯ��Ŀ�겻���ڣ�\n");
        }
    }
    fclose(fp);
}
