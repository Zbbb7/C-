#include"main.h"
#include<stdio.h>
#include<windows.h>
void PrintSpareApartment(){
    FILE *fp;
    if((fp=fopen("room.txt","r"))==NULL){
        perror("打开文件失败");
        return;
    }
    fseek(fp,0,SEEK_SET);
    int count=0;                                                 //记录结构体数量
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    printf("有空余床位的公寓:\n");
    for(int i=0;i<count;i++){
        if(apart[i].sparebed>0){
            printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n",apart[i].number,apart[i].roomnumber,apart[i].roomcategory,apart[i].bed,apart[i].allocatedbed,apart[i].sparebed,apart[i].college);
        }
    }
    fclose(fp);
    }