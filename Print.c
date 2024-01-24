#include"main.h"
#include<stdio.h>

void Print(){
    FILE *fp;
    if((fp=fopen("room.txt","r+"))==NULL){
        printf("文件打开失败!");
        return;
    }
    int count=0;                                                 //记录结构体数量
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }
    printf("编号\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
    for(int i=0;i<count;i++){
printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n",apart[i].number,apart[i].roomnumber,apart[i].roomcategory,apart[i].bed,apart[i].allocatedbed,apart[i].sparebed,apart[i].college);
    }

}
