#include<stdio.h>
#include"main.h"
#include<string.h>
#include<windows.h>
void Delete(){
    FILE *sourceFile;
    FILE *tempFile;

    sourceFile = fopen("room.txt", "r+");
    if (sourceFile == NULL) {
        perror("ԭʼ�ļ���ʧ��");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("��ʱ�ļ���ʧ��");
        fclose(sourceFile);
        return;
    }
    char ch[10];
    printf("������Ҫɾ����λ�ķ���ĵķ���ţ�");
    scanf("%s",ch);
    int count = 0;
    while (fscanf(sourceFile, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        // �������Ų�ƥ�䣬д�뵽��ʱ�ļ�
        if (strcmp(apart[count].roomnumber, ch) != 0) {
            fprintf(tempFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        }
        if(strcmp(apart[count].roomnumber,ch)==0){
            apart[count].bed=0;
            apart[count].allocatedbed=0;
            apart[count].sparebed=0;
            fprintf(tempFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        }
        count++;
    }
    fclose(sourceFile);
    fclose(tempFile);

    // ɾ��ԭ�ļ�
    if (remove("room.txt") != 0) {
        perror("ɾ��ԭʼ�ļ�ʧ��");
        return;
    }

    // ��������ʱ�ļ�Ϊԭ�ļ�
    if (rename("temp.txt", "room.txt") != 0) {
        perror("�������ļ�ʧ��");
        return;
    }

    printf("ɾ�����䴲λ��Ϣ�ɹ���\n");
}