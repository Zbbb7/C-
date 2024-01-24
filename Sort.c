#include<stdio.h>
#include"main.h"
#include<windows.h>
void Sort(){
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

    struct apartment temp;
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++) {
            if (apart[i].sparebed < apart[j].sparebed) {
                temp = apart[i];
                apart[i] = apart[j];
                apart[j] = temp;
            }
        }
    }
    printf("�����ലλ���жൽ�������Ľ����\n");
    for(int i=0;i<count;i++){
        printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%s\n",i+1,apart[i].number,apart[i].roomnumber,apart[i].roomcategory,apart[i].bed,apart[i].allocatedbed,apart[i].sparebed,apart[i].college);
    }
    fclose(fp);
}
