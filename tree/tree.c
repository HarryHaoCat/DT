/**************************************************
	> File Name: tree.c
	> Author: HarryHao
	> Mail: 954487858@qq.com 
	> Created Time: 2018年07月11日 星期三 10时48分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tree.h"

TRAINING* trainingInit(TRAINING trainingSet[])
{
    TRAINING* p = (TRAINING*)malloc(sizeof(TRAINING));
    p->outLook = trainingSet[0].outLook;
    p->temperature = trainingSet[0].temperature;
    p->humidity = trainingSet[0].humidity;
    p->windy = trainingSet[0].windy;
    p->play = trainingSet[0].play;
    TRAINING* head = p;
    for (int i = 1; i < 14; i++)
    {
        p->next = (TRAINING*)malloc(sizeof(TRAINING));
        p = p -> next;
        p->outLook = trainingSet[i].outLook;
        p->temperature = trainingSet[i].temperature;
        p->humidity = trainingSet[i].humidity;
        p->windy = trainingSet[i].windy;
        p->play = trainingSet[i].play;
    }
    return head;
} 

//按照属性值划分数据集
TRAINING* splitData(int feature, int class, TRAINING* head)
{

    TRAINING* p = head;
    TRAINING* subHead = (TRAINING*)malloc(sizeof(TRAINING));
    TRAINING* temp = subHead;
    temp->next = NULL;
    while(p != NULL)
    {
        if(feature == OUTLOOK)
        {
         if(p->outLook == class)
         {
                
            temp->next = (TRAINING*)malloc(sizeof(TRAINING));
            temp = temp->next;
            temp->outLook = 0;
            temp->temperature = p->temperature;
            temp->humidity = p->humidity;
            temp->windy = p->windy;
            temp->play = p->play;
            temp->next = NULL;
         }
         p = p->next;
        }
        else if(feature == TEMPERATURE)
        {
         if(p->temperature == class)
         {
                
            temp->next = (TRAINING*)malloc(sizeof(TRAINING));
            temp = temp->next;
            temp->outLook = p->outLook;
            temp->temperature = 0;
            temp->humidity = p->humidity;
            temp->windy = p->windy;
            temp->play = p->play;
            temp->next = NULL;
         }
         p = p->next;
        }
        else if(feature == HUMIDITY)
        {
         if(p->humidity == class)
         {
                
            temp->next = (TRAINING*)malloc(sizeof(TRAINING));
            temp = temp->next;
            temp->outLook = p->outLook;
            temp->temperature = p->temperature;
            temp->humidity = 0;
            temp->windy = p->windy;
            temp->play = p->play;
            temp->next = NULL;
         }
         p = p->next;
        }    
        else if(feature == WINDY)
        {
         if(p->windy == class)
         {
                
            temp->next = (TRAINING*)malloc(sizeof(TRAINING));
            temp = temp->next;
            temp->outLook = p->outLook;
            temp->temperature = p->temperature;
            temp->humidity = p->humidity;
            temp->windy = 0;
            temp->play = p->play;
            temp->next = NULL;
         }
         p = p->next;

        }
    }
    subHead = subHead->next;
    return subHead;

}

//计算某个划分子集的信息熵
double calEntropy(TRAINING* head)
{
    double num = 0.0;
    double play = 0.0;
    double not_play = 0.0;
    TRAINING* p = head;
    while(p != NULL)
    {
        if(p->play == CAN_PLAY)
        {
            play++;
        }
        else not_play++;
        num++;
        p = p->next;
    }
    printf("play/num = %f, not_play/num= %f", (double)(play/num), (double)(not_play/num));
    printf("num = %f\n", num);
    return Entropy((double)(play/num), (double)(not_play/num));

}

//计算某个属性的信息熵,选取最好的划分属性
int choseBestFeature(TRAINING* p)
{
    double max1 = 0.0, max2 = 0.0, max3 = 0.0, max4 = 0.0; 
    if(p->outLook)
    {
        TRAINING* sunny = splitData(OUTLOOK, SUNNY, p);
        TRAINING* rain = splitData(OUTLOOK, RAIN, p);
        TRAINING* voercast = splitData(OUTLOOK, VOERCAST, p);
        max1 = calEntropy(sunny) + calEntropy(rain) + calEntropy(voercast);
    }

    if(p->temperature)
    {
        TRAINING* high_temperature = splitData(TEMPERATURE, HIGH_TEMPERATURE, p);
        TRAINING* mid = splitData(TEMPERATURE, MID_TEMPERATURE, p);
        TRAINING* cold = splitData(TEMPERATURE, COLD_TEMPERATURE, p);
        max2 = calEntropy(high_temperature) + calEntropy(mid) + calEntropy(cold);
    }

    if(p->humidity)
    {
        TRAINING* high_temperature = splitData(HUMIDITY, HIGH_HUMIDITY, p);
        TRAINING* normal = splitData(HUMIDITY, NORMAL_HUMIDITY, p);
        max3 = calEntropy(high_temperature) + calEntropy(normal);
    }
 
    if(p->windy)
    {
        TRAINING* wind = splitData(WINDY, WIND, p);
        TRAINING* no_wind = splitData(WINDY, NO_WIND, p);
        max4 = calEntropy(wind) + calEntropy(no_wind);
    }
    int m1 = max1>max2?OUTLOOK:TEMPERATURE;
    int m2 = max3>max4?HUMIDITY:WINDY;
    return m1>m2?m1:m2; 
}

double log2(double x)
{
    if(x < 0.0)
        return -1.0;
    return (double)log(x)/log(2.0);
}

double Entropy(double p1, double p2)
{
   if(p1 > 0.0 && p2 > 0.0)
        return -p1 * log2(p1) - p2 * log2(p2); 
    else
        return -1.0;
}
int main()
{
 TRAINING trainingSet[TRAINING_NUMBER] =
{
{ SUNNY   ,HIGH_TEMPERATURE,HIGH_HUMIDITY,NO_WIND,NOT_PLAY,NULL },
{ SUNNY   ,HIGH_TEMPERATURE,HIGH_HUMIDITY,WIND ,NOT_PLAY,NULL },
{ VOERCAST,HIGH_TEMPERATURE,NORMAL_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ RAIN    ,MID_TEMPERATURE,HIGH_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ RAIN    ,COLD_TEMPERATURE,NORMAL_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ RAIN    ,COLD_TEMPERATURE,NORMAL_HUMIDITY,WIND ,NOT_PLAY,NULL },
{ VOERCAST,COLD_TEMPERATURE,NORMAL_HUMIDITY,WIND ,CAN_PLAY,NULL },
{ SUNNY   ,MID_TEMPERATURE,HIGH_HUMIDITY,NO_WIND,NOT_PLAY,NULL },
{ SUNNY   ,COLD_TEMPERATURE,NORMAL_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ RAIN    ,MID_TEMPERATURE,NORMAL_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ SUNNY   ,MID_TEMPERATURE,NORMAL_HUMIDITY,WIND ,CAN_PLAY,NULL },
{ VOERCAST,MID_TEMPERATURE,HIGH_HUMIDITY,WIND ,CAN_PLAY,NULL },
{ VOERCAST,HIGH_TEMPERATURE,NORMAL_HUMIDITY,NO_WIND,CAN_PLAY,NULL },
{ RAIN    ,MID_TEMPERATURE,NORMAL_HUMIDITY,WIND ,NOT_PLAY,NULL }
};
 TRAINING* head =  trainingInit(trainingSet);
 TRAINING* sub = splitData(TEMPERATURE, MID_TEMPERATURE, head); 
 printf("信息熵为%f\n", calEntropy(sub));
 //printf("最好的划分为%d\n", choseBestFeature(sub));
    return 0;
}
