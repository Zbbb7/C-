#include"main.h"
#include<stdio.h>

void Print(){
    FILE *fp;
    if((fp=fopen("room.txt","r+"))==NULL){
        printf("�ļ���ʧ��!");
        return;
    }
    int count=0;                                                 //��¼�ṹ������
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }
    printf("���\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
    for(int i=0;i<count;i++){
printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n",apart[i].number,apart[i].roomnumber,apart[i].roomcategory,apart[i].bed,apart[i].allocatedbed,apart[i].sparebed,apart[i].college);
    }

}
