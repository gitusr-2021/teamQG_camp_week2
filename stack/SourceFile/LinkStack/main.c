#include <stdio.h>
#include <stdlib.h>
#include"head/LinkStack.h"

/***************************************************************************************
 *	FileName					:LinkStack
 *	CopyRight					:
 *	ModuleName					:
 *
 *	CPU							:
 *	RTOS						:Win10
 *
 *	Create Date					:2021年4月4日
 *	Author/Corportation			:QiWeidong
 *
 *	Abstract Description		:QG训练营第二周大组任务，链栈
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021年4月4日	QiWeidong							完成主题部分
 *
 ***************************************************************************************/
int main()
{
	char option;		//用户输入的选项
	ElemType data;		//栈存放的数据
    int FctStatus;      //存放函数返回值的变量
    int length; 		//当前栈的长度

    LinkStack *LStackStrPtr = NULL;	//栈结构体的指针

	while(1)
	{
		menu();
        optionInput(&option);

        if(LStackStrPtr == NULL)	//栈不存在时，只能执行栈的初始化
		{
            switch(option)
            {
				case 'a':
					LStackStrPtr = (LinkStack *)malloc(sizeof(LinkStack));	//为栈结构体申请空间
					FctStatus = initLStack(LStackStrPtr);	//初始化栈并接收返回值

                    Function_Status_PRINT(FctStatus,"初始化失败","初始化成功");		//打印函数运行情况

					break;

				default:
					printf("还未初始化栈，请先初始化\n");
					break;
            }
		}
		else		//栈存在时，执行初始化以外的其他操作
		{
            switch(option)
            {
				case 'a':
                    printf("栈已存在，请勿重复初始化\n");
                    break;

                case 'b':
                    FctStatus = isEmptyLStack(LStackStrPtr);	//进入判断函数并接收结果

                    Function_Status_PRINT(FctStatus,"栈不空","栈空");	//打印结果
                    break;

				case 'c':
						printf("请输入数据：\n");
						numberInput(&data);

						FctStatus = pushLStack(LStackStrPtr,data);
						Function_Status_PRINT(FctStatus,"入栈失败","入栈成功");

					break;


				case 'd':
                    if(LStackStrPtr->top == NULL)
					{
						printf("栈已空，无法出栈\n");
					}
					else		//栈不空时，数据出栈
					{
                        popLStack(LStackStrPtr, &data);
                        printf("出栈的数据为%d\n",data);
					}

					break;


				case 'e':
					if(LStackStrPtr->top == NULL)
					{
						printf("栈已空，无数据\n");
					}
					else		//栈不空时，读取数据并打印
					{
                        getTopLStack(LStackStrPtr, &data);
                        printf("当前栈顶数据为%d\n",data);
					}

					break;


				case 'f':
					LStackLength(LStackStrPtr,&length);		//得到当前栈的长度并打印
					printf("当前栈长度为%d\n",length);

					break;


				case 'g':
                    clearLStack(LStackStrPtr);
                    printf("栈已清空\n");

                    break;

                case 'h':
                	destroyLStack(LStackStrPtr);
                	LStackStrPtr = NULL;
                	printf("栈已销毁\n");

					break;

				default:
					printf("选项无效，请输入有效选项\n");
					break;

			}
		}

	}





}
