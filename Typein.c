#include <stdio.h>
#include<string.h>
#include <windows.h>
#include "main.h"
void Typein(){
FILE *fp;
if((fp=fopen("room.txt","r+"))==NULL){
    perror("���ļ�ʧ��");
    return;
}
    fseek(fp, 0, SEEK_END);
    int count=0;                                                 //��¼�ṹ������
    while(fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        count++;
    }

    char ch[2];//����ѡ���Ƿ����������Ϣ
     printf("�Ƿ�Ҫ���������Ϣ����y/n��");
    scanf("%s",ch);
    while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){
        printf("��ţ�");
        scanf("%d",&apart[count].number);                                  //���
        printf("�����:");
        scanf("%s",apart[count].roomnumber);                                  //�����
        printf("�������(������Ů��)��");                   //�������
        scanf("%s",apart[count].roomcategory);
        printf("��λ��");                                                  //��λ
        scanf("%d",&apart[count].bed);
        printf("�ѷ��䴲λ��");                 //�ѷ��䴲λ
        scanf("%d",&apart[count].allocatedbed);
        printf("ѧԺ��");                                                   //ѧԺ
        scanf("%s",apart[count].college);
        fprintf(fp, "%d %s %s %d %d  %s\n", apart[count].number, apart[count].roomnumber,
                apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].college);
        count++;
    printf("�Ƿ����������Ϣ����y/n)");
    scanf("%s",ch);
}
    fclose(fp);
}