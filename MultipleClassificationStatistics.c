#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void MultipleClassificationStatistics() {
    FILE *fp;
    if ((fp = fopen("room.txt", "r+")) == NULL) {
        perror("打开文件失败");
        return;
    }
    int count = 0;                                                 //记录结构体数量
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber,
                  apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed,
                  apart[count].college) !=EOF) {
        count++;
    }

    char ch[2];
    printf("是否要调用多个分类的统计功能：（y/n）");
    scanf("%s", ch);
    if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0) {
        int ch1;                                               //选择统计的数据
        char ch2[10];                                           //学院
        char ch3[3];                                          //房间类别
        printf("请选择想要统计的数据：\n");
        printf("1、床位\n");
        printf("2、已分配床位\n");
        printf("3、空余床位\n");
        printf("请输入序号：");
        scanf("%d", &ch1);
        printf("请输入想要统计的学院：");
        scanf("%s", ch2);
        printf("请输入想要统计的房间类别：");
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
        printf("统计结果为：%d\n", sum);


    }
    fclose(fp);
}
