//
// Created by XZBbb on 2023/12/30.
//

#ifndef C_MAIN_H
#define C_MAIN_H
struct apartment{
    int number;                    //编号
    char roomnumber[10];           //房间号
    char roomcategory[3];          //房间类别
    int bed;                       //床位
    int allocatedbed;              //已分配床位
    int sparebed;                  //空余床位
    char college[10];               //学院
};
extern struct apartment apart[];
#endif //C_MAIN_H
#define len sizeof(struct apartment)
