#include<stdio.h>
#include<windows.h>
#include"CountSparedBed.c"
#include"Sort.c"
#include"Sort2.c"
#include"Delete.c"
#include"Change.c"
#include"FindAndPrint.c"
#include"Backup.c"
#include"AddBedInformation.c"
#include"MultipleClassificationStatistics.c"
#include"StatisticsOfFreeBedInACollege.c"
#include"PrintSpareApartment.c"

struct apartment apart[20];
int main() {
    printf("\t\t\t\t\t\t��ӭʹ��ѧ����Ԣ��λ����ϵͳ\n");
    printf("��ѡ�õĹ������£�\n");
    printf("1.¼�벢������Ϣ\n");
    printf("2.���㴲λ���������������Ϣ\n");
    printf("3.��ʾ�п��ലλ�Ĺ�Ԣ��Ϣ\n");
    printf("4.�����ലλ���ɶൽ������\n");
    printf("5.���ӷ����д�λ����Ϣ\n");
    printf("6.���Ĵ�λ��Ϣ\n");
    printf("7.�ṩ���ֲ�ѯ��������\n");
    printf("8.ͳ��ĳѧԺ���ലλ���\n");
    printf("9.ɾ��ָ������Ĵ�λ\n");
    printf("10.�����ļ�\n");
    printf("11.�ṩ���ַ����ͳ��\n");
    printf("12.�Ȱ���������ٰ����ലλ��������\n");
    printf("13.����\n");
    printf("14.�˳�ϵͳ\n");
    printf("\n\n");
    int selection;
    printf("������Ҫʹ�ù��ܵ���ţ�");
    scanf("%d",&selection);
    while(selection>0&&selection<14){
        switch(selection) {
            case 1:
                Typein();
                break;
            case 2:
            	CountSparedBed();
                break;
            case 3:
                PrintSpareApartment();
                break;
            case 4:
                Sort();
                break;
            case 5:
                AddBedInformation();
                break;
            case 6:
                Change();
                break;
            case 7:
                FindAndPrint();
                break;
            case 8:
                StatisticsOfFreeBedInACollege();
                break;
            case 9:
                Delete();
                break;
            case 10:
                Backup();
                break;
            case 11:
                MultipleClassificationStatistics();
                break;
            case 12:
                Sort2();
                break;
            case 13:
                system("cls");
                printf("��ѡ�õĹ������£�\n");
                printf("1.¼�벢������Ϣ\n");
    			printf("2.���㴲λ���������������Ϣ\n");
    			printf("3.��ʾ�п��ലλ�Ĺ�Ԣ��Ϣ\n");
    			printf("4.�����ലλ���ɶൽ������\n");
    			printf("5.���ӷ����д�λ����Ϣ\n");
    			printf("6.���Ĵ�λ��Ϣ\n");
    			printf("7.�ṩ���ֲ�ѯ��������\n");
    			printf("8.ͳ��ĳѧԺ���ലλ���\n");
    			printf("9.ɾ��ָ������Ĵ�λ\n");
    			printf("10.�����ļ�\n");
    			printf("11.�ṩ���ַ����ͳ��\n");
    			printf("12.�Ȱ���������ٰ����ലλ��������\n");
    			printf("13.����\n");
    			printf("14.�˳�ϵͳ\n");
    			printf("\n\n");
                break;
        }
        printf("\n���������ѡ�����ʹ�õĹ��ܻ��˳�ϵͳ��");
        scanf("%d",&selection);
    }
    if(selection>13||selection<0){
        printf("�˳�ϵͳ");
        system("pause");
        return 0;
    }


}

