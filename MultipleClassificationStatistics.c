#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void MultipleClassificationStatistics() {
    FILE *fp;
    if ((fp = fopen("room.txt", "r+")) == NULL) {
        perror("���ļ�ʧ��");
        return;
    }
    int count = 0;                                                 //��¼�ṹ������
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber,
                  apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed,
                  apart[count].college) !=EOF) {
        count++;
    }

    char ch[2];
    printf("�Ƿ�Ҫ���ö�������ͳ�ƹ��ܣ���y/n��");
    scanf("%s", ch);
    if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0) {
        int ch1;                                               //ѡ��ͳ�Ƶ�����
        char ch2[10];                                           //ѧԺ
        char ch3[3];                                          //�������
        printf("��ѡ����Ҫͳ�Ƶ����ݣ�\n");
        printf("1����λ\n");
        printf("2���ѷ��䴲λ\n");
        printf("3�����ലλ\n");
        printf("��������ţ�");
        scanf("%d", &ch1);
        printf("��������Ҫͳ�Ƶ�ѧԺ��");
        scanf("%s", ch2);
        printf("��������Ҫͳ�Ƶķ������");
        scanf("%s", ch3);
        int sum = 0;
        for (int i = 0; i <count; i++) {
            if (strcmp(apart[i].college, ch2) == 0 && strcmp(apart[i].roomcategory, ch3) == 0) {
                switch (ch1) {
                    case 1:
                        sum += apart[i].bed;
                        break;
                    case 2:
                        sum += apart[i].allocatedbed;
                        break;
                    case 3:
                        sum += apart[i].sparebed;
                        break;
                }
            }
        }
        printf("ͳ�ƽ��Ϊ��%d\n", sum);


    }
    fclose(fp);
}
