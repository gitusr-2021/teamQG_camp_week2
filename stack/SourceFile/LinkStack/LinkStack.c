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

/**************************************************************
*	Include File Section
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"head/LinkStack.h"


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
 *@name			:initLStack(LinkStack *s)
 *@description	:初始化栈
 *@param		:*s(栈结构体的指针)
 *@return		:Status
 *@notice		:none
*/
Status initLStack(LinkStack *s)
{
    if(s == NULL)		//如果主函数为结构体申请空间失败，返回ERROR
	{
		return ERROR;
	}
	else
	{
		(*s).count = 0;		//初始元素个数为0
		s->top = NULL;		//无元素，指向空
		return SUCCESS;
	}
}

/**
 *@name			:isEmptyLStack(LinkStack *s)
 *@description	:判断栈是否为空
 *@param		:*s(栈结构体的指针)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyLStack(LinkStack *s)
{
    if(s->top == NULL)	//栈空，返回1，否则返回0
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 *@name			:pushLStack(LinkStack *s,ElemType data)
 *@description	:上移栈顶结点并输入数据
 *@param		:*s(栈结构的指针),data
 *@return		:Status
 *@notice		:none
*/
Status pushLStack(LinkStack *s,ElemType data)
{
    StackNode *assistPtr;		//辅助指针

    assistPtr = (StackNode *)malloc(sizeof(StackNode));	//申请新结点

    if(assistPtr == NULL)	//申请失败，返回error
	{
		return ERROR;
	}
	else	//申请成功，则设置新结点，返回success
	{
        assistPtr->next = s->top;		//新结点指向旧栈顶
        (*assistPtr).data = data;			//输入数据
        s->top = assistPtr;				//顶指针指向新栈顶

        (*s).count++;					//计数器+1
        return SUCCESS;
	}
}

/**
 *@name			:popLStack(LinkStack *s,ElemType *data)
 *@description	:输出栈顶数据并下移栈顶
 *@param		:*s(栈结构的指针),*data(输出的数据)
 *@return		:Status
 *@notice		:none
*/
Status popLStack(LinkStack *s,ElemType *data)
{
    StackNode *assistPtr;		//辅助指针

    *data = (*(s->top)).data;	//输出数据

    assistPtr = s->top;			//下移栈顶，删除旧栈顶
    s->top = s->top->next;
    free(assistPtr);

    (*s).count--;			//计数器减一

    return SUCCESS;
}

/**
 *@name			:getTopLStack(LinkStack *s,ElemType *e)
 *@description	:得到栈顶元素
 *@param		:*s(栈结构的指针),*e(输出的数据)
 *@return		:Status
 *@notice		:none
*/
Status getTopLStack(LinkStack *s,ElemType *e)
{
	*e = (*(s->top)).data;		//将栈顶数据复制给*e
	return SUCCESS;
}

/**
 *@name			:LStackLength(LinkStack *s,int *length)
 *@description	:检测栈长度
 *@param		:*s(栈结构的指针),*length
 *@return		:Status
 *@notice		:none
*/
Status LStackLength(LinkStack *s,int *length)
{
	int amount;		//计数器
    StackNode *assitPtr;	//辅助指针

    assitPtr = s->top;
    for(amount = 0;assitPtr != NULL; amount++)	//辅助指针不指向空时，计数器+1，辅助指针下移
	{
		assitPtr = assitPtr->next;
	}

	*length = amount;

	return SUCCESS;
}

/**
 *@name			:clearLStack(LinkStack *s)
 *@description	:清空栈
 *@param		:*s(栈结构的指针)
 *@return		:Status
 *@notice		:none
*/
Status clearLStack(LinkStack *s)
{
	StackNode *assistPtr;	//辅助指针

    while(s->top != NULL)	//栈不空时，消除当前栈顶并下移栈顶
	{
        assistPtr = s->top;
        s->top = s->top->next;

        free(assistPtr);
	}

    return SUCCESS;
}

/**
 *@name			:destroyLStack(LinkStack *s)
 *@description	:销毁栈
 *@param		:*s(栈结构的指针)
 *@return		:Status
 *@notice		:none
*/
Status destroyLStack(LinkStack *s)
{
	StackNode *assistPtr;	//辅助指针

    while(s->top != NULL)	//栈不空时，消除当前栈顶并下移栈顶
	{
        assistPtr = s->top;
        s->top = s->top->next;

        free(assistPtr);
	}

    free(s);		//消除栈的结构体

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

