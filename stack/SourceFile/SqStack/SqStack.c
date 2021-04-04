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
 *	Abstract Description		:function for SqStack
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021年4月3日	QiWeidong							完成所有函数
 *
 ***************************************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include<stdio.h>
#include"head/SqStack.h"
#include<stdlib.h>

/**************************************************************
*	Function Define Section
**************************************************************/

/**
 *@name			:menu()
 *@description	:打印菜单
 *@param		:none
 *@return		:none
 *@notice		:none
*/
void menu()
{
	printf(	"\n——————————————————————————————\n"
			"a,初始化栈\n"
			"b,判断栈是否为空\n"
			"c,入栈\n"
			"d,出栈\n"
			"e,打印栈顶元素\n"
			"f,打印栈长度\n"
			"g,清空栈\n"
			"h,销毁栈\n"
			"——————————————————————————————\n");
}

/**
 *@name			:optionInput(char *option)
 *@description	:处理选项输入，将长字符串存入数组，将第一个字符
后面的从缓存区清走
 *@param		:option
 *@return		:none
 *@notice		:none
*/
void optionInput(char *option)
{
    char c[80];

    printf("请输入选项，长字符串只有首字母会被作为选项：\n");
    scanf("%s",c);

    *option = c[0];		//将输入的首字母存入option
}


/**
 *  @name        : void numberInput
 *	@description : 检测是否有非整形输入并将整数存入传入指针所指的变量
 *	@param		 : p
 *	@return		 : none
 *  @notice      : None
*/
void numberInput(int *p)
{
    int isLoop = 1;      //用于判断变量是否存入了有效值，决定循环是否继续
    char c[80];         //用于存放错误输入

    while(isLoop){    //将输入的数字存入数组

        if(scanf("%d", p)){   //输入的值有效，则isLoop=0
            isLoop = 0;
        }
        else{    //若无效，则用存入字符变量防止产生死循环
            printf("你脸在键盘上滚吗（狗头），请输入整数，字符将被跳过，小数将被取整\n");
            scanf("%s",c);
        }
    }
}

/**
 *@name			:initStack
 *@description	:初始化栈
 *@param		:*s(the *elem), sizes
 *@return		:Status
 *@notice		:none
*/
Status initStack(SqStack *s,int sizes)
{
	if(s == NULL)		//如果主函数为结构体申请空间失败，返回ERROR
	{
		return ERROR;
	}
	else
	{
		s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));	//根据用户输入的大小为栈申请空间

		if(s->elem == NULL)		//如果申请失败，返回ERROR
		{
			return ERROR;
		}
		else					//申请成功，则初始化栈并返回SUCCESS
		{
			(*s).top = -1;
			(*s).size = sizes;
			return SUCCESS;
		}
	}
}

/**
 *@name			:isEmptyStack(SqStack *s)
 *@description	:判断栈是否为空
 *@param		:*s(the StackStruct)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyStack(SqStack *s)
{
    if((*s).top == -1)		//如果栈空，返回1
	{
        return 1;
	}
	else 					//栈不空，返回0
	{
        return 0;
	}
}

/**
 *@name			:pushStack(SqStack *s,ElemType data)
 *@description	:在栈顶输入数据
 *@param		:*s(the *elem), data
 *@return		:Status
 *@notice		:none
*/
Status pushStack(SqStack *s,ElemType data)
{
    (*s).top++;		//顶上移
    s->elem[(*s).top] = data;

    return SUCCESS;
}

/**
 *@name			:popStack(SqStack *s,ElemType *data)
 *@description	:输出栈顶数据并下移栈顶
 *@param		:*s(the *elem), *data
 *@return		:Status
 *@notice		:none
*/
Status popStack(SqStack *s,ElemType *data)
{
    *data = s->elem[(*s).top];		//将栈顶数据存入data
    (*s).top--;						//下移栈顶

    return SUCCESS;
}

/**
 *@name			:getTopStack(SqStack *s,ElemType *e)
 *@description	:得到栈顶元素
 *@param		:*s(StackStruct),*e(data)
 *@return		:Status
 *@notice		:none
*/
Status getTopStack(SqStack *s,ElemType *e)
{
	*e = s->elem[(*s).top];		//将当前栈顶数据存入*e

	return SUCCESS;
}

/**
 *@name			:stackLength(SqStack *s,int *length)
 *@description	:检测栈的当前长度
 *@param		:*s(StackStruct), *length
 *@return		:Status
 *@notice		:none
*/
Status stackLength(SqStack *s,int *length)
{
    *length = (*s).top + 1;

    return 1;
}

/**
 *@name			:clearStack(SqStack *s)
 *@description	:清空栈
 *@param		:*s(the StackStruct)
 *@return		:Status
 *@notice		:none
*/
Status clearStack(SqStack *s)
{
    (*s).top = -1;

    return SUCCESS;
}

/**
 *@name			:destroyStack(SqStack *s)
 *@description	:销毁栈
 *@param		:*s(StackPtr)
 *@return		:Status
 *@notice		:none
*/
Status destroyStack(SqStack *s)
{
    free(s->elem);
    free(s);

    return SUCCESS;
}


 #ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{
          /* User can add his own implementation to report the file name and line number,
             ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

          while (1)
          {}
}
#endif

