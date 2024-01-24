#include "main.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

void FindAndPrint() {
    FILE *fp;
    if ((fp = fopen("room.txt", "r")) == NULL) {
        perror("打开文件失败");
    }
    int count = 0; // 记录结构体数量
    while (fscanf(fp, "%d %s %s %d %d %d %s\n", &apart[count].number, apart[count].roomnumber, apart[count].roomcategory, &apart[count].bed, &apart[count].allocatedbed, &apart[count].sparebed, apart[count].college)!=EOF) {
        count++;
    }


    printf("可使用的查询功能如下：\n");
    printf("1、单一条件查询\n");
    printf("2、多重条件查询(学院、房间类别)\n");
    printf("3、退出\n");
    printf("请输入要使用功能的序号：");

    int choose;
    scanf("%d", &choose);

    if (choose != 1 && choose != 2) {
        printf("无效输入！\n");
        return;
    } else if (choose == 1) {
        printf("可选择查询的条件如下\n");
        printf("1、房间号\n");
        printf("2、房间类别\n");
        printf("3、已分配床位情况\n");
        printf("4、有空余床位的房间\n");
        printf("5、学院\n");

        int ch1 = 0; // 代表想要查询的一个条件
        printf("请选择：");
        scanf("%d", &ch1);

        if (ch1 == 1) {
            char ch2[10]; // 代表想要查询的房间号
            printf("请输入想要查询的房间号：");
            scanf("%s", ch2);
            int index = 0; // 用作计数器计算要查询的房间号是否出现
            printf("查询结果如下：\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].roomnumber, ch2) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("查询的房间号不存在！\n");
            }
        }
        else if (ch1 == 2) {
            char ch3[3]; // 代表想要房间类别
            printf("请输入想要查询的房间类别：");
            int index = 0; // 用作计数器检查选择的房间类别是否出现或正确
            scanf("%s", ch3);
            printf("查询结果如下：\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].roomcategory, ch3) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("查询的房间类别错误！\n");
            }
        }
        else if (ch1 == 3) {
            int index = 0;
            printf("分配情况如下：\n");
            for (int i = 0; i < count; i++) {
                printf("%d\t%s\t%s\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].allocatedbed, apart[i].college);
                index++;
            }
            if (index == 0) {
                printf("未查询到已分配房间\n");
            }
        }
        else if (ch1 == 4) {
            int index = 0; // 用作计数器计算是否存在空余床位
            printf("查询结果如下：\n");
            for (int i = 0; i < count; i++) {
                if (apart[i].sparebed > 0) {
                    printf("%d\t%s\t%s\t%d\t%s\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].sparebed, apart[i].college);
                    index++;
                }
            }
            if (index == 0) {
                printf("不存在有空余床位的房间！\n");
            }
        }
        else if (ch1 == 5) {
            char ch4[10]; // 代表想要查询的学院
            printf("请输入想要查询学院：");
            int index = 0; // 用作计数器检查选择的房间类别是否出现或正确
            scanf("%s", ch4);
            printf("查询结果如下：\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(apart[i].college, ch4) == 0) {
                    printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", apart[i].number, apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed);
                    index++;
                }
            }
            if (index == 0) {
                printf("查询的学院不存在！\n");
            }
        } else {
            printf("所选条件不存在！\n");
        }
    } else if (choose == 2) {
        char ch1[10]; // 代表选择的学院
        char ch2[3];  // 代表选择的房间类别
        printf("输入要查找的学院：");
        scanf("%s", ch1);
        printf("输入要查找的房间类别：");
        scanf("%s", ch2);
        int index = 0; // 检查要查找的目标是否出现
        printf("查询结果如下:\n");
        for (int i = 0; i < count; i++) {
            if (strcmp(ch1, apart[i].college) == 0 && strcmp(ch2, apart[i].roomcategory) == 0) {
                printf("%s\t%s\t%d\t%d\t%d\t%s\t\n", apart[i].roomnumber, apart[i].roomcategory, apart[i].bed, apart[i].allocatedbed, apart[i].sparebed, apart[i].college);
                index++;
            }
        }
        if (index == 0) {
            printf("查询的目标不存在！\n");
        }
    }
    fclose(fp);
}
