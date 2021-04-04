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
 *	Abstract Description	:	this will be used for	QG�ڶ��ܴ�������
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021��4��3��	QiWeidong							������岿��
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
//��ӡ����״̬�궨��
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
 *@description	:��ӡ�˵�
 *@param		:none
 *@return		:none
 *@notice		:none
*/
void menu();

/**
 *@name			:optionInput(char *option)
 *@description	:����ѡ�����룬�����ַ����������飬����һ���ַ�
����Ĵӻ���������
 *@param		:option
 *@return		:none
 *@notice		:none
*/
void optionInput(char *option);

/**
 *  @name        : void numberInput
 *	@description : ����Ƿ��з��������벢���������봫��ָ����ָ�ı���
 *	@param		 : p
 *	@return		 : none
 *  @notice      : None
*/
void numberInput(int *p);

//���������˳��ջ

/**
 *@name			:initStack
 *@description	:��ʼ��ջ
 *@param		:*s(the *elem), sizes
 *@return		:Status
 *@notice		:none
*/
Status initStack(SqStack *s,int sizes);

/**
 *@name			:isEmptyStack(SqStack *s)
 *@description	:�ж�ջ�Ƿ�Ϊ��
 *@param		:*s(the *elem)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyStack(SqStack *s);

/**
 *@name			:pushStack(SqStack *s,ElemType data)
 *@description	:��ջ����������
 *@param		:*s(the *elem), data
 *@return		:Status
 *@notice		:none
*/
Status pushStack(SqStack *s,ElemType data);

/**
 *@name			:popStack(SqStack *s,ElemType *data)
 *@description	:���ջ�����ݲ�����ջ��
 *@param		:*s(the *elem), *data
 *@return		:Status
 *@notice		:none
*/
Status popStack(SqStack *s,ElemType *data);

/**
 *@name			:getTopStack(SqStack *s,ElemType *e)
 *@description	:�õ�ջ��Ԫ��
 *@param		:*s(StackStruct),*e(data)
 *@return		:Status
 *@notice		:none
*/
Status getTopStack(SqStack *s,ElemType *e);

/**
 *@name			:stackLength(SqStack *s,int *length)
 *@description	:���ջ�ĵ�ǰ����
 *@param		:*s(StackStruct), *length
 *@return		:Status
 *@notice		:none
*/
Status stackLength(SqStack *s,int *length);

/**
 *@name			:clearStack(SqStack *s)
 *@description	:���ջ
 *@param		:*s(the StackStruct)
 *@return		:Status
 *@notice		:none
*/
Status clearStack(SqStack *s);

/**
 *@name			:destroyStack(SqStack *s)
 *@description	:����ջ
 *@param		:*s(StackPtr)
 *@return		:Status
 *@notice		:none
*/
Status destroyStack(SqStack *s);




/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
