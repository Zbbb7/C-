#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void Delete(){
    FILE *sourceFile;
    FILE *tempFile;

    sourceFile = fopen("room.txt", "r+");
    if (sourceFile == NULL) {
        perror("原始文件打开失败");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("临时文件打开失败");
        fclose(sourceFile);
        return;
    }
    char ch[10];
    printf("请输入要删除床位的房间的的房间号：");
    scanf("%s",ch);
    int count = 0;
    while (fscanf(sourceFile, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        // 如果房间号不匹配，写入到临时文件
        if (strcmp(apart[count].roomnumber, ch) != 0) {
            fprintf(tempFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        }
        if(strcmp(apart[count].roomnumber,ch)==0){
            apart[count].bed=0;
            apart[count].allocatedbed=0;
            apart[count].sparebed=0;
            fprintf(tempFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        }
        count++;
    }
    fclose(sourceFile);
    fclose(tempFile);

    // 删除原文件
    if (remove("room.txt") != 0) {
        perror("删除原始文件失败");
        return;
    }

    // 重命名临时文件为原文件
    if (rename("temp.txt", "room.txt") != 0) {
        perror("重命名文件失败");
        return;
    }

    printf("删除房间床位信息成功！\n");
}