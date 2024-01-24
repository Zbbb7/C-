#include<stdio.h>
#include"main.h"
#include<windows.h>
#include<string.h>
void AddBedInformation(){
    FILE *fp;
    if((fp= fopen("room.txt", "a+"))==NULL){
        perror("打开文件失败");
        return;
    }

    int count = 0; // 记录结构体数量
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF) {
        count++;
    }

    char ch[2];
    printf("是否要增加信息：（y/n）");
    scanf("%s",ch);
    while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){
        printf("编号：");
        scanf("%d",&apart[count].number);                                  //编号
        printf("房间号:");
        scanf("%s",apart[count].roomnumber);                               //房间号
        printf("房间类别：");                                               //房间类别
        scanf("%s",apart[count].roomcategory);
        printf("床位：");                                                  //床位
        scanf("%d",&apart[count].bed);
        printf("已分配床位：");                                             //已分配床位
        scanf("%d",&apart[count].allocatedbed);
        printf("学院：");                                                   //学院
        scanf("%s",apart[count].college);
        apart[count].sparebed=apart[count].bed-apart[count].allocatedbed;  //计算空余床位
        if(fprintf(fp,"%d %s %s %d %d %d %s\n",apart[count].number,apart[count].roomnumber,apart[count].roomcategory,apart[count].bed,apart[count].allocatedbed,apart[count].sparebed,apart[count].college)!=EOF){
            printf("保存成功！\n");
            getchar();
            count++;
        }                                                                   //保存信息
        else{
            printf("保存失败！\n");
            getchar();
        }
        printf("是否继续输入信息：（y/n)");
        scanf("%s",ch);
    }
    fseek(fp,0,SEEK_SET);                  //方便下一次正确读取文件
    fclose(fp);
}
