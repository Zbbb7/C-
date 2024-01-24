#include<stdio.h>
#include"main.h"
#include<windows.h>
int Backup(){
    FILE *sourceFile;
    FILE *backupFile;
    sourceFile = fopen("room.txt", "r+");
    if (sourceFile == NULL) {
        perror("ԭʼ�ļ���ʧ��");
        return 1;
    }
    backupFile = fopen("backup.txt", "w");
    if (backupFile == NULL) {
        perror("�����ļ���ʧ��");
        fclose(sourceFile);
        return 1;
    }

    fseek(backupFile, 0, SEEK_SET);                   // �������ļ����ļ�ָ�����õ��ļ���ͷ
    int count=0;                                                 //��¼�ṹ������
    while(fscanf(sourceFile, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF){
        fprintf(backupFile, "%d %s %s %d %d %d %s\n", apart[count].number, apart[count].roomnumber, apart[count].roomcategory, apart[count].bed, apart[count].allocatedbed, apart[count].sparebed, apart[count].college);
        count++;
    }
    if (count==0) {
        printf("���ݶ�ȡ��������ʹ�ù���3������ലλ����ʹ�ô˹��ܣ�\n");
        return 0;
    }
    fclose(sourceFile);
    fclose(backupFile);
    printf("�ļ����ݳɹ���\n");
    return 0;
}
