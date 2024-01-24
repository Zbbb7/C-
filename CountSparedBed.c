#include<stdio.h>
#include"main.h"
#include"Typein.c"
void CountSparedBed(){
    FILE *fp,*newFp;
    if((fp=fopen("room.txt","r+"))==NULL){
        perror("打开文件失败");
        return;
    }
    if ((newFp = fopen("newroom.txt", "w")) == NULL) {
        perror("创建新文件失败");
        fclose(fp);
        return;
    }
    int count=0;                                                 //记录结构体数量
    while (fscanf(fp, "%d %s %s %d %d %s\n", &apart[count].number, apart[count].roomnumber,
                  apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, apart[count].college) != EOF){
        apart[count].sparebed = apart[count].bed - apart[count].allocatedbed;
        fprintf(newFp, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber,
                apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed,apart[count].college);
        count++;
    }
    fclose(fp);
    fclose(newFp);
    if (remove("room.txt") != 0) {
        perror("删除原始文件失败");
    }

    if (rename("newroom.txt", "room.txt") != 0) {
        perror("重命名文件失败");
    }
    printf("计算成功！\n");
}