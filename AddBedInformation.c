#include<stdio.h>
#include"main.h"
#include<windows.h>
#include<string.h>
void AddBedInformation(){
    FILE *fp;
    if((fp= fopen("room.txt", "a+"))==NULL){
        perror("���ļ�ʧ��");
        return;
    }

    int count = 0; // ��¼�ṹ������
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF) {
        count++;
    }

    char ch[2];
    printf("�Ƿ�Ҫ������Ϣ����y/n��");
    scanf("%s",ch);
    while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){
        printf("��ţ�");
        scanf("%d",&apart[count].number);                                  //���
        printf("�����:");
        scanf("%s",apart[count].roomnumber);                               //�����
        printf("�������");                                               //�������
        scanf("%s",apart[count].roomcategory);
        printf("��λ��");                                                  //��λ
        scanf("%d",&apart[count].bed);
        printf("�ѷ��䴲λ��");                                             //�ѷ��䴲λ
        scanf("%d",&apart[count].allocatedbed);
        printf("ѧԺ��");                                                   //ѧԺ
        scanf("%s",apart[count].college);
        apart[count].sparebed=apart[count].bed-apart[count].allocatedbed;  //������ലλ
        if(fprintf(fp,"%d %s %s %d %d %d %s\n",apart[count].number,apart[count].roomnumber,apart[count].roomcategory,apart[count].bed,apart[count].allocatedbed,apart[count].sparebed,apart[count].college)!=EOF){
            printf("����ɹ���\n");
            getchar();
            count++;
        }                                                                   //������Ϣ
        else{
            printf("����ʧ�ܣ�\n");
            getchar();
        }
        printf("�Ƿ����������Ϣ����y/n)");
        scanf("%s",ch);
    }
    fseek(fp,0,SEEK_SET);                  //������һ����ȷ��ȡ�ļ�
    fclose(fp);
}
