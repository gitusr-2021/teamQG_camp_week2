/***************************************************************************************
 *	File Name				:LinkStack
 *	CopyRight				:
 *	ModuleName				:
 *
 *	CPU			:
 *	RTOS			:
 *
 *	Create Data		:
 *	Author/Corportation	:QiWeidong
 *
 *	Abstract Description	:	this will be used for QG第二周大组任务
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021年4月4日	QiWeidong							完成主题部分
 *
 ***************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/
//打印函数状态宏定义
#define Function_Status_PRINT(a,error,success) { if(!a) \
printf("%s\n",error); \
else \
printf("%s\n",success);}

/**************************************************************
*	Enum Define Section
**************************************************************/
typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

/**************************************************************
*	Type Define Section
**************************************************************/
typedef int ElemType;

/**************************************************************
*	Struct Define Section
**************************************************************/
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


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


//链栈

/**
 *@name			:initLStack(LinkStack *s)
 *@description	:初始化栈
 *@param		:*s
 *@return		:Status
 *@notice		:none
*/
Status initLStack(LinkStack *s);

/**
 *@name			:isEmptyLStack(LinkStack *s)
 *@description	:判断栈是否为空
 *@param		:*s(栈结构体的指针)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyLStack(LinkStack *s);

/**
 *@name			:pushLStack(LinkStack *s,ElemType data)
 *@description	:入栈
 *@param		:*s(栈结构的指针),data
 *@return		:Status
 *@notice		:none
*/
Status pushLStack(LinkStack *s,ElemType data);

/**
 *@name			:popLStack(LinkStack *s,ElemType *data)
 *@description	:输出栈顶数据并下移栈顶
 *@param		:*s(栈结构的指针),*data(输出的数据)
 *@return		:Status
 *@notice		:none
*/
Status popLStack(LinkStack *s,ElemType *data);

/**
 *@name			:getTopLStack(LinkStack *s,ElemType *e)
 *@description	:得到栈顶元素
 *@param		:*s(栈结构的指针),*e(输出的数据)
 *@return		:Status
 *@notice		:none
*/
Status getTopLStack(LinkStack *s,ElemType *e);

/**
 *@name			:LStackLength(LinkStack *s,int *length)
 *@description	:检测栈长度
 *@param		:*s(栈结构的指针),*length
 *@return		:Status
 *@notice		:none
*/
Status LStackLength(LinkStack *s,int *length);//检测栈长度

/**
 *@name			:clearLStack(LinkStack *s)
 *@description	:清空栈
 *@param		:*s(栈结构的指针)
 *@return		:Status
 *@notice		:none
*/
Status clearLStack(LinkStack *s);

/**
 *@name			:destroyLStack(LinkStack *s)
 *@description	:销毁栈
 *@param		:*s(栈结构的指针)
 *@return		:Status
 *@notice		:none
*/
Status destroyLStack(LinkStack *s);//销毁栈

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
