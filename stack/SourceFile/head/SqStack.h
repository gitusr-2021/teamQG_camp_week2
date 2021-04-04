/***************************************************************************************
 *	File Name				:SqStack
 *	CopyRight				:
 *	ModuleName				:
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Date				:2021 Apr. 3
 *	Author/Corportation		:QiWeidong
 *
 *	Abstract Description	:	this will be used for	QG第二周大组任务
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021年4月3日	QiWeidong							完成主体部分
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/**************************************************************
*	Enum Define Section
**************************************************************/
typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;

/**************************************************************
*	Macro Define Section
**************************************************************/
//打印函数状态宏定义
#define Function_Status_PRINT(a,error,success) { if(!a) \
printf("%s\n",error); \
else \
printf("%s\n",success);}

/**************************************************************
*	Type Define Section
**************************************************************/
typedef int ElemType;

/**************************************************************
*	Struct Define Section
**************************************************************/
typedef struct SqStack
{
	ElemType *elem;
	int top;
	int size;
} SqStack;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *@name			:menu()
 *@description	:打印菜单
 *@param		:none
 *@return		:none
 *@notice		:none
*/
void menu();

/**
 *@name			:optionInput(char *option)
 *@description	:处理选项输入，将长字符串存入数组，将第一个字符
后面的从缓存区清走
 *@param		:option
 *@return		:none
 *@notice		:none
*/
void optionInput(char *option);

/**
 *  @name        : void numberInput
 *	@description : 检测是否有非整形输入并将整数存入传入指针所指的变量
 *	@param		 : p
 *	@return		 : none
 *  @notice      : None
*/
void numberInput(int *p);

//基于数组的顺序栈

/**
 *@name			:initStack
 *@description	:初始化栈
 *@param		:*s(the *elem), sizes
 *@return		:Status
 *@notice		:none
*/
Status initStack(SqStack *s,int sizes);

/**
 *@name			:isEmptyStack(SqStack *s)
 *@description	:判断栈是否为空
 *@param		:*s(the *elem)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyStack(SqStack *s);

/**
 *@name			:pushStack(SqStack *s,ElemType data)
 *@description	:在栈顶输入数据
 *@param		:*s(the *elem), data
 *@return		:Status
 *@notice		:none
*/
Status pushStack(SqStack *s,ElemType data);

/**
 *@name			:popStack(SqStack *s,ElemType *data)
 *@description	:输出栈顶数据并下移栈顶
 *@param		:*s(the *elem), *data
 *@return		:Status
 *@notice		:none
*/
Status popStack(SqStack *s,ElemType *data);

/**
 *@name			:getTopStack(SqStack *s,ElemType *e)
 *@description	:得到栈顶元素
 *@param		:*s(StackStruct),*e(data)
 *@return		:Status
 *@notice		:none
*/
Status getTopStack(SqStack *s,ElemType *e);

/**
 *@name			:stackLength(SqStack *s,int *length)
 *@description	:检测栈的当前长度
 *@param		:*s(StackStruct), *length
 *@return		:Status
 *@notice		:none
*/
Status stackLength(SqStack *s,int *length);

/**
 *@name			:clearStack(SqStack *s)
 *@description	:清空栈
 *@param		:*s(the StackStruct)
 *@return		:Status
 *@notice		:none
*/
Status clearStack(SqStack *s);

/**
 *@name			:destroyStack(SqStack *s)
 *@description	:销毁栈
 *@param		:*s(StackPtr)
 *@return		:Status
 *@notice		:none
*/
Status destroyStack(SqStack *s);




/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
