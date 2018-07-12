/*************************************************************************
	> File Name: tree.h
	> Author: HarryHao
	> Mail: 95487858@qq.com 
	> Created Time: 2018年07月11日 星期三 10时48分10秒
 ************************************************************************/

#ifndef _TREE_H_
#define _TREE_H_
#define NOTHING 111
//天气值域
#define SUNNY     11
#define VOERCAST     12
#define RAIN 13
//风值域
#define WIND  2
#define NO_WIND     3
//类别属性值域
#define CAN_PLAY      14
#define NOT_PLAY      15
//非类别属性值域
#define OUTLOOK       16
#define TEMPERATURE      17
#define HUMIDITY      18
#define WINDY     19
//将温度分三个类
#define HIGH_TEMPERATURE  8
#define MID_TEMPERATURE    7
#define COLD_TEMPERATURE  6
//将湿度分两个类
#define HIGH_HUMIDITY          75
#define NORMAL_HUMIDITY    74
#define TRAINING_NUMBER    14
//训练数据集结构
typedef struct TRAINING
{

int outLook;
int temperature;
int humidity;
int windy;
int play;
struct TRAINING *next;  //定义下一结点的指针
}TRAINING;
//温度和湿度增益结构
typedef struct TEMPER_HUMID_GAIN
{
int value;
int playCount;
int c;
}TEM_HUM_GAIN;
//非类属性集结构
typedef struct SET
{
int item;
struct SET *next;
}SET;
//决策树结构
typedef struct TREE
{
int attribute;
struct TREE *left;
struct TREE *mid;
struct TREE *right;
}TREENODE, *TREE;
//TRAINING *trainHead;
SET *noClassSetHead;
//TREE *treeT;


//非类集合和类集合
int labels[4] = { OUTLOOK,TEMPERATURE,HUMIDITY,WINDY };
int classSet[2] = { CAN_PLAY,NOT_PLAY };

//初始化训练数据的结构体
TRAINING* trainingSetInit();
//定义log2函数
double log2(double p);
//定义计算信息熵
double Entropy(double p1, double p2);
//
#endif





