#include<stdio.h>
#include"main.h"
#include<windows.h>
int Backup(){
    FILE *sourceFile;
    FILE *backupFile;
    sourceFile = fopen("room.txt", "r+");
    if (sourceFile == NULL) {
        perror("原始文件打开失败");
        return 1;
    }
    backupFile = fopen("backup.txt", "w");
    if (backupFile == NULL) {
        perror("备份文件打开失败");
        fclose(sourceFile);
        return 1;
    }

    fseek(backupFile, 0, SEEK_SET);                   // 将备份文件的文件指针设置到文件开头
    int count=0;                                                 //记录结构体数量
    while(fscanf(sourceFile, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        fprintf(backupFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        count++;
    }
    if (count==0) {
        printf("数据读取错误！请先使用功能3计算空余床位后再使用此功能！\n");
        return 0;
    }
    fclose(sourceFile);
    fclose(backupFile);
    printf("文件备份成功！\n");
    return 0;
}
