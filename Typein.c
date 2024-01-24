#include <stdio.h>
#include<string.h>
#include <windows.h>
#include "main.h"
void Typein(){
FILE *fp;
if((fp=fopen("room.txt","r+"))==NULL){
    perror("打开文件失败");
    return;
}
    fseek(fp, 0, SEEK_END);
    int count=0;                                                 //记录结构体数量
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    char ch[2];//用来选择是否继续输入信息
     printf("是否要输入相关信息：（y/n）");
    scanf("%s",ch);
    while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){
        printf("编号：");
        scanf("%d",&apart[count].number);                                  //编号
        printf("房间号:");
        scanf("%s",apart[count].roomnumber);                                  //房间号
        printf("房间类别(男生或女生)：");                   //房间类别
        scanf("%s",apart[count].roomcategory);
        printf("床位：");                                                  //床位
        scanf("%d",&apart[count].bed);
        printf("已分配床位：");                 //已分配床位
        scanf("%d",&apart[count].allocatedbed);
        printf("学院：");                                                   //学院
        scanf("%s",apart[count].college);
        fprintf(fp, "%d %s %s %d %d  %s\n", apart[count].number, apart[count].roomnumber,
                apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].college);
        count++;
    printf("是否继续输入信息：（y/n)");
    scanf("%s",ch);
}
    fclose(fp);
}