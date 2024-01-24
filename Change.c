#include"main.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
void Change() {
    FILE *fp, *newFp;
    if ((fp = fopen("room.txt", "rb+")) == NULL) {
        perror("���ļ�ʧ��");
        return;
    }
    if ((newFp = fopen("newroom.txt", "w")) == NULL) {
        perror("�������ļ�ʧ��");
        fclose(fp);
        return;
    }
    fseek(fp, 0, SEEK_SET);
    int count = 0; // ��¼�ṹ������
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college) ==7) {
        count++;
    }
    if (count==0) {
        printf("���ݶ�ȡ��������ʹ�ù���3������ലλ����ʹ�ô˹��ܣ�\n");
        return;
    }
    char ch1[2];
    printf("��ѡ���Ƿ�Ҫ�޸Ĵ�λ��Ϣ(y/n)��");
    scanf("%s", ch1);
    while (strcmp(ch1, "y") == 0 || strcmp(ch1, "Y") == 0) {
        char ch2[10];
        printf("������Ҫ�޸Ĵ�λ��Ϣ�ķ���ķ���ţ�");
        scanf("%s", ch2);
        int index = -1;                                            //ȷ����Ҫ���ҵķ�����Ƿ����
        for (int i = 0; i < count; i++) {
            if (strcmp(ch2, apart[i].roomnumber) == 0) {
                index = i;
                break;
            }
        }                                                          //�����Ƿ����Ҫ�ı���Ϣ�ķ����
        if (index == -1) {
            printf("������ķ���Ų����ڣ�\n");
            return;
        }
        if (index != -1) {
            fseek(fp, index * len, SEEK_SET);
            printf("���������ѡ�����ӻ�����ѷ��䴲λ\n");
            printf("1�������ѷ��䴲λ\n");
            printf("2�������ѷ��䴲λ\n");
            int ch3;                                        //��ʾѡ�����ӻ��Ǽ����ѷ��䴲λ
            scanf("%d", &ch3);
            int ch4;                                        //��ʾҪ�ı���ѷ��䴲λ��
                if (ch3 == 1) {
                    printf("������Ҫ���ӵĴ�λ����");
                    scanf("%d", &ch4);
                    if (ch4 > apart[index].sparebed) {
                        printf("���ലλ���㣡");
                    }
                    else {
                        apart[index].allocatedbed = apart[index].allocatedbed + ch4;
                        apart[index].sparebed = apart[index].bed - apart[index].allocatedbed;
                    }
                }
                if (ch3 == 2) {
                    printf("������Ҫ���ٵĴ�λ����");
                    scanf("%d", &ch4);
                    if (ch4 > apart[index].allocatedbed) {
                        printf("Ҫ���ٵĴ�λ���࣡");
                    }
                    else {
                        apart[index].allocatedbed = apart[index].allocatedbed - ch4;
                        apart[index].sparebed = apart[index].bed - apart[index].allocatedbed;
                    }
                }
            if (ch3 != 1 && ch3 != 2) {
                printf("����ѡ�����");
            }
    }
        printf("�Ƿ�Ҫ�����޸ģ���y/n��");
        scanf("%s",ch1);
}
    for(int i=0;i<count;i++){
        fprintf(newFp, "%d %s %s %d %d %d %s\n", apart[i].number, apart[i].roomnumber,
                apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed,apart[i].college);
    }
    fclose(fp);
    fclose(newFp);
    if (remove("room.txt") != 0) {
        perror("ɾ��ԭʼ�ļ�ʧ��");
    }

    if (rename("newroom.txt", "room.txt") != 0) {
        perror("�������ļ�ʧ��");
    }
    printf("�޸ĳɹ���\n");
}