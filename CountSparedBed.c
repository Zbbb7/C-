#include<stdio.h>
#include"main.h"
#include"Typein.c"
void CountSparedBed(){
    FILE *fp,*newFp;
    if((fp=fopen("room.txt","r+"))==NULL){
        perror("���ļ�ʧ��");
        return;
    }
    if ((newFp = fopen("newroom.txt", "w")) == NULL) {
        perror("�������ļ�ʧ��");
        fclose(fp);
        return;
    }
    int count=0;                                                 //��¼�ṹ������
    while (fscanf(fp, "%d %s %s %d %d %s\n", &apart[count].number, apart[count].roomnumber,
                  apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, apart[count].college) != EOF){
        apart[count].sparebed = apart[count].bed - apart[count].allocatedbed;
        fprintf(newFp, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber,
                apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed,apart[count].college);
        count++;
    }
    fclose(fp);
    fclose(newFp);
    if (remove("room.txt") != 0) {
        perror("ɾ��ԭʼ�ļ�ʧ��");
    }

    if (rename("newroom.txt", "room.txt") != 0) {
        perror("�������ļ�ʧ��");
    }
    printf("����ɹ���\n");
}