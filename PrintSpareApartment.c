#include"main.h"
#include<stdio.h>
#include<windows.h>
void PrintSpareApartment(){
    FILE *fp;
    if((fp=fopen("room.txt","r"))==NULL){
        perror("���ļ�ʧ��");
        return;
    }
    fseek(fp,0,SEEK_SET);
    int count=0;                                                 //��¼�ṹ������
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    printf("�п��ലλ�Ĺ�Ԣ:\n");
    for(int i=0;i<count;i++){
        if(apart[i].sparebed>0){
            printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n",apart[i].number,apart[i].roomnumber,apart[i].roomcategory,apart[i].bed,apart[i].allocatedbed,apart[i].sparebed,apart[i].college);
        }
    }
    fclose(fp);
    }