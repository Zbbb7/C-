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
    printf("\t\t\t\t\t\t欢迎使用学生公寓床位分配系统\n");
    printf("可选用的功能如下：\n");
    printf("1.录入并保存信息\n");
    printf("2.计算床位空余情况并保存信息\n");
    printf("3.显示有空余床位的公寓信息\n");
    printf("4.按空余床位数由多到少排序\n");
    printf("5.增加房间中床位的信息\n");
    printf("6.更改床位信息\n");
    printf("7.提供多种查询并输出结果\n");
    printf("8.统计某学院空余床位情况\n");
    printf("9.删除指定房间的床位\n");
    printf("10.备份文件\n");
    printf("11.提供多种分类的统计\n");
    printf("12.先按类别排序，再按空余床位多少排序\n");
    printf("13.清屏\n");
    printf("14.退出系统\n");
    printf("\n\n");
    int selection;
    printf("请输入要使用功能的序号：");
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
                printf("可选用的功能如下：\n");
                printf("1.录入并保存信息\n");
    			printf("2.计算床位空余情况并保存信息\n");
    			printf("3.显示有空余床位的公寓信息\n");
    			printf("4.按空余床位数由多到少排序\n");
    			printf("5.增加房间中床位的信息\n");
    			printf("6.更改床位信息\n");
    			printf("7.提供多种查询并输出结果\n");
    			printf("8.统计某学院空余床位情况\n");
    			printf("9.删除指定房间的床位\n");
    			printf("10.备份文件\n");
    			printf("11.提供多种分类的统计\n");
    			printf("12.先按类别排序，再按空余床位多少排序\n");
    			printf("13.清屏\n");
    			printf("14.退出系统\n");
    			printf("\n\n");
                break;
        }
        printf("\n请输入序号选择继续使用的功能或退出系统：");
        scanf("%d",&selection);
    }
    if(selection>13||selection<0){
        printf("退出系统");
        system("pause");
        return 0;
    }


}

