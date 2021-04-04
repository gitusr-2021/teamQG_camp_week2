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
 *	Abstract Description	:	this will be used for QG�ڶ��ܴ�������
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021��4��4��	QiWeidong							������ⲿ��
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
//��ӡ����״̬�궨��
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


//��ջ

/**
 *@name			:initLStack(LinkStack *s)
 *@description	:��ʼ��ջ
 *@param		:*s
 *@return		:Status
 *@notice		:none
*/
Status initLStack(LinkStack *s);

/**
 *@name			:isEmptyLStack(LinkStack *s)
 *@description	:�ж�ջ�Ƿ�Ϊ��
 *@param		:*s(ջ�ṹ���ָ��)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyLStack(LinkStack *s);

/**
 *@name			:pushLStack(LinkStack *s,ElemType data)
 *@description	:��ջ
 *@param		:*s(ջ�ṹ��ָ��),data
 *@return		:Status
 *@notice		:none
*/
Status pushLStack(LinkStack *s,ElemType data);

/**
 *@name			:popLStack(LinkStack *s,ElemType *data)
 *@description	:���ջ�����ݲ�����ջ��
 *@param		:*s(ջ�ṹ��ָ��),*data(���������)
 *@return		:Status
 *@notice		:none
*/
Status popLStack(LinkStack *s,ElemType *data);

/**
 *@name			:getTopLStack(LinkStack *s,ElemType *e)
 *@description	:�õ�ջ��Ԫ��
 *@param		:*s(ջ�ṹ��ָ��),*e(���������)
 *@return		:Status
 *@notice		:none
*/
Status getTopLStack(LinkStack *s,ElemType *e);

/**
 *@name			:LStackLength(LinkStack *s,int *length)
 *@description	:���ջ����
 *@param		:*s(ջ�ṹ��ָ��),*length
 *@return		:Status
 *@notice		:none
*/
Status LStackLength(LinkStack *s,int *length);//���ջ����

/**
 *@name			:clearLStack(LinkStack *s)
 *@description	:���ջ
 *@param		:*s(ջ�ṹ��ָ��)
 *@return		:Status
 *@notice		:none
*/
Status clearLStack(LinkStack *s);

/**
 *@name			:destroyLStack(LinkStack *s)
 *@description	:����ջ
 *@param		:*s(ջ�ṹ��ָ��)
 *@return		:Status
 *@notice		:none
*/
Status destroyLStack(LinkStack *s);//����ջ

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
