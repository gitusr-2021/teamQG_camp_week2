#include <stdio.h>
#include <stdlib.h>
#include"head/SqStack.h"

/***************************************************************************************
 *	FileName					:SqStack
 *	CopyRight					:
 *	ModuleName					:
 *
 *	CPU				:
 *	RTOS				:
 *
 *	Create Date			:
 *	Author/Corportation		:QiWeidong
 *
 *	Abstract Description		:function of SqStack
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021年4月3日	QiWeidong							完成所有函数
 *
 ***************************************************************************************/
int main()
{
	char option;		//用户输入的选项
	ElemType data;		//栈存放的数据
    int FctStatus;      //存放函数返回值的变量
    int isStack = 0;   	//表明栈是否存在
    int sizes;			//栈的总长
    int length; 		//当前栈的长度

	SqStack *StackPtr = NULL;	//栈的结构体的指针

	while(1)
	{
		menu();
        optionInput(&option);

        if(isStack == 0)	//栈不存在时，只能执行栈的初始化
		{
            switch(option)
            {
				case 'a':
					printf("请输入栈的总长：\n");
					numberInput(&sizes);

					StackPtr = (SqStack *)malloc(sizeof(SqStack));	//为栈结构体申请空间
					FctStatus = initStack(StackPtr,sizes);	//初始化栈并接收返回值

                    Function_Status_PRINT(FctStatus,"初始化失败","初始化成功");		//打印函数运行情况

                    if(FctStatus)		//初始化成功则将isStack置1
					{
						isStack = 1;
					}

					break;

				default:
					printf("还未初始化栈，请先初始化\n");
					break;
            }
		}
		else
		{
            switch(option)
            {
				case 'a':
                    printf("栈已存在，请勿重复初始化\n");
                    break;

                case 'b':
                    FctStatus = isEmptyStack(StackPtr);	//进入判断函数并接收结果

                    Function_Status_PRINT(FctStatus,"栈不空","栈空");	//打印结果
                    break;

				case 'c':
                    if((*StackPtr).top < ((*StackPtr).size-1))	//栈未满时，提示用户输入
					{
						printf("请输入数据：\n");
						numberInput(&data);

                        pushStack(StackPtr,data);
                        printf("数据已输入\n");
					}
					else
					{
						printf("栈已满\n");
					}

					break;

				case 'd':
                    if((*StackPtr).top == -1)
					{
						printf("栈已空，无法出栈\n");
					}
					else		//栈不空时，数据出栈
					{
                        popStack(StackPtr, &data);
                        printf("出栈的数据为%d\n",data);
					}

					break;

				case 'e':
					if((*StackPtr).top == -1)
					{
						printf("栈已空，无数据\n");
					}
					else		//栈不空时，读取数据并打印
					{
                        getTopStack(StackPtr, &data);
                        printf("当前栈顶数据为%d\n",data);
					}

					break;

				case 'f':
					stackLength(StackPtr,&length);		//得到当前栈的长度并打印
					printf("当前栈长度为%d\n",length);

					break;

				case 'g':
                    clearStack(StackPtr);
                    printf("栈已清空\n");

                    break;

                case 'h':
                	destroyStack(StackPtr);
                	StackPtr = NULL;
                	isStack = 0;
                	printf("栈已销毁\n");

					break;

				default:
					printf("选项无效，请输入有效选项\n");
					break;

			}
		}

	}




}
