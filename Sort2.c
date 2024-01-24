#include<stdio.h>
#include<string.h>
#include"main.h"
#include<stdlib.h>
#include<windows.h>

void Sort2(){
    FILE *fp;
    if((fp=fopen("room.txt","r+"))==NULL){
        perror("打开文件失败");
        return;
    }
    fflush(fp);
    fseek(fp,0,SEEK_SET);
    int count=0;                                                 //记录结构体数量
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    struct apartment *temp = malloc(count * sizeof(struct apartment));
    int index=0;                           //用于计算男生有多少个
    for(int i=0;i<count;i++){
        if(strcmp(apart[i].roomcategory,"男生")==0){
            temp[index]=apart[i];
            index++;
        }
    }
    int index1=index;
    for(int i=0;i<count;i++){
        if(strcmp(apart[i].roomcategory,"女生")==0){
            temp[index1]=apart[i];
            index1++;
        }
    }
    struct apartment temp1;
    for(int i=0;i<index;i++){
        for(int j=i+1;j<index;j++){
            if(temp[i].sparebed<temp[j].sparebed){
                temp1=temp[i];
                temp[i]=temp[j];
                temp[j]=temp1;
            }
        }
    }
    for(int i=index;i<index1;i++){
        for(int j=i+1;j<index1;j++){
            if(temp[i].sparebed<temp[j].sparebed){
                temp1=temp[i];
                temp[i]=temp[j];
                temp[j]=temp1;
            }
        }
    }
    printf("先按类别排序，再按空余床位数排序的结果为\n");

    for(int i=0;i<index1;i++){
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n",temp[i].number,temp[i].roomnumber,temp[i].roomcategory,temp[i].bed,temp[i].allocatedbed,temp[i].sparebed,temp[i].college);
    }
    free(temp);
    fclose(fp);
}