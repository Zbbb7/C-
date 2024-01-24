#include"main.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
void Change() {
    FILE *fp, *newFp;
    if ((fp = fopen("room.txt", "rb+")) == NULL) {
        perror("打开文件失败");
        return;
    }
    if ((newFp = fopen("newroom.txt", "w")) == NULL) {
        perror("创建新文件失败");
        fclose(fp);
        return;
    }
    fseek(fp, 0, SEEK_SET);
    int count = 0; // 记录结构体数量
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college) ==7) {
        count++;
    }
    if (count==0) {
        printf("数据读取错误！请先使用功能3计算空余床位后再使用此功能！\n");
        return;
    }
    char ch1[2];
    printf("请选择是否要修改床位信息(y/n)：");
    scanf("%s", ch1);
    while (strcmp(ch1, "y") == 0 || strcmp(ch1, "Y") == 0) {
        char ch2[10];
        printf("请输入要修改床位信息的房间的房间号：");
        scanf("%s", ch2);
        int index = -1;                                            //确认所要查找的房间号是否存在
        for (int i = 0; i < count; i++) {
            if (strcmp(ch2, apart[i].roomnumber) == 0) {
                index = i;
                break;
            }
        }                                                          //计算是否存在要改变信息的房间号
        if (index == -1) {
            printf("所输入的房间号不存在！\n");
            return;
        }
        if (index != -1) {
            fseek(fp, index * len, SEEK_SET);
            printf("请输入序号选择增加或减少已分配床位\n");
            printf("1、增加已分配床位\n");
            printf("2、减少已分配床位\n");
            int ch3;                                        //表示选择增加还是减少已分配床位
            scanf("%d", &ch3);
            int ch4;                                        //表示要改变的已分配床位数
                if (ch3 == 1) {
                    printf("请输入要增加的床位数：");
                    scanf("%d", &ch4);
                    if (ch4 > apart[index].sparebed) {
                        printf("空余床位不足！");
                    }
                    else {
                        apart[index].allocatedbed = apart[index].allocatedbed + ch4;
                        apart[index].sparebed = apart[index].bed - apart[index].allocatedbed;
                    }
                }
                if (ch3 == 2) {
                    printf("请输入要减少的床位数：");
                    scanf("%d", &ch4);
                    if (ch4 > apart[index].allocatedbed) {
                        printf("要减少的床位过多！");
                    }
                    else {
                        apart[index].allocatedbed = apart[index].allocatedbed - ch4;
                        apart[index].sparebed = apart[index].bed - apart[index].allocatedbed;
                    }
                }
            if (ch3 != 1 && ch3 != 2) {
                printf("功能选择错误！");
            }
    }
        printf("是否要继续修改：（y/n）");
        scanf("%s",ch1);
}
    for(int i=0;i<count;i++){
        fprintf(newFp, "%d %s %s %d %d %d %s\n", apart[i].number, apart[i].roomnumber,
                apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed,apart[i].college);
    }
    fclose(fp);
    fclose(newFp);
    if (remove("room.txt") != 0) {
        perror("删除原始文件失败");
    }

    if (rename("newroom.txt", "room.txt") != 0) {
        perror("重命名文件失败");
    }
    printf("修改成功！\n");
}