#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void StatisticsOfFreeBedInACollege(){
    FILE *fp;
    if((fp=fopen("room.txt","r+"))==NULL){
        perror("打开文件失败");
        return;
    }
    fseek(fp,0,SEEK_SET);
    int count=0;                                                 //记录结构体数量
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    char ch[20];                                   //选择要查询的学院
    int sum=0;
    printf("请输入要查询的学院:");
    scanf("%s",ch);
    for(int i=0;i<count;i++){
        if(strcmp(apart[i].college,ch)==0){
            sum=sum+apart[i].sparebed;
        }
    }
    printf("该学院的空余床位有%d个\n",sum);
    fclose(fp);
}