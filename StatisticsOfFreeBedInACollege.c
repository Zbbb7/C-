#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void StatisticsOfFreeBedInACollege(){
    FILE *fp;
    if((fp=fopen("room.txt","r+"))==NULL){
        perror("���ļ�ʧ��");
        return;
    }
    fseek(fp,0,SEEK_SET);
    int count=0;                                                 //��¼�ṹ������
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    char ch[20];                                   //ѡ��Ҫ��ѯ��ѧԺ
    int sum=0;
    printf("������Ҫ��ѯ��ѧԺ:");
    scanf("%s",ch);
    for(int i=0;i<count;i++){
        if(strcmp(apart[i].college,ch)==0){
            sum=sum+apart[i].sparebed;
        }
    }
    printf("��ѧԺ�Ŀ��ലλ��%d��\n",sum);
    fclose(fp);
}