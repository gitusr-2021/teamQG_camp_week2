/***************************************************************************************
 *	FileName					:LinkStack
 *	CopyRight					:
 *	ModuleName					:
 *
 *	CPU							:
 *	RTOS						:Win10
 *
 *	Create Date					:2021��4��4��
 *	Author/Corportation			:QiWeidong
 *
 *	Abstract Description		:QGѵ��Ӫ�ڶ��ܴ���������ջ
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1.0				2021��4��4��	QiWeidong							������ⲿ��
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
 *@description	:��ӡ�˵�
 *@param		:none
 *@return		:none
 *@notice		:none
*/
void menu()
{
	printf(	"\n������������������������������������������������������������\n"
			"a,��ʼ��ջ\n"
			"b,�ж�ջ�Ƿ�Ϊ��\n"
			"c,��ջ\n"
			"d,��ջ\n"
			"e,��ӡջ��Ԫ��\n"
			"f,��ӡջ����\n"
			"g,���ջ\n"
			"h,����ջ\n"
			"������������������������������������������������������������\n");
}

/**
 *@name			:optionInput(char *option)
 *@description	:����ѡ�����룬�����ַ����������飬����һ���ַ�
����Ĵӻ���������
 *@param		:option
 *@return		:none
 *@notice		:none
*/
void optionInput(char *option)
{
    char c[80];

    printf("������ѡ����ַ���ֻ������ĸ�ᱻ��Ϊѡ�\n");
    scanf("%s",c);

    *option = c[0];		//�����������ĸ����option
}


/**
 *  @name        : void numberInput
 *	@description : ����Ƿ��з��������벢���������봫��ָ����ָ�ı���
 *	@param		 : p
 *	@return		 : none
 *  @notice      : None
*/
void numberInput(int *p)
{
    int isLoop = 1;      //�����жϱ����Ƿ��������Чֵ������ѭ���Ƿ����
    char c[80];         //���ڴ�Ŵ�������

    while(isLoop){    //����������ִ�������

        if(scanf("%d", p)){   //�����ֵ��Ч����isLoop=0
            isLoop = 0;
        }
        else{    //����Ч�����ô����ַ�������ֹ������ѭ��
            printf("�����ڼ����Ϲ��𣨹�ͷ�����������������ַ�����������С������ȡ��\n");
            scanf("%s",c);
        }
    }
}

/**
 *@name			:initLStack(LinkStack *s)
 *@description	:��ʼ��ջ
 *@param		:*s(ջ�ṹ���ָ��)
 *@return		:Status
 *@notice		:none
*/
Status initLStack(LinkStack *s)
{
    if(s == NULL)		//���������Ϊ�ṹ������ռ�ʧ�ܣ�����ERROR
	{
		return ERROR;
	}
	else
	{
		(*s).count = 0;		//��ʼԪ�ظ���Ϊ0
		s->top = NULL;		//��Ԫ�أ�ָ���
		return SUCCESS;
	}
}

/**
 *@name			:isEmptyLStack(LinkStack *s)
 *@description	:�ж�ջ�Ƿ�Ϊ��
 *@param		:*s(ջ�ṹ���ָ��)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyLStack(LinkStack *s)
{
    if(s->top == NULL)	//ջ�գ�����1�����򷵻�0
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
 *@description	:����ջ����㲢��������
 *@param		:*s(ջ�ṹ��ָ��),data
 *@return		:Status
 *@notice		:none
*/
Status pushLStack(LinkStack *s,ElemType data)
{
    StackNode *assistPtr;		//����ָ��

    assistPtr = (StackNode *)malloc(sizeof(StackNode));	//�����½��

    if(assistPtr == NULL)	//����ʧ�ܣ�����error
	{
		return ERROR;
	}
	else	//����ɹ����������½�㣬����success
	{
        assistPtr->next = s->top;		//�½��ָ���ջ��
        (*assistPtr).data = data;			//��������
        s->top = assistPtr;				//��ָ��ָ����ջ��

        (*s).count++;					//������+1
        return SUCCESS;
	}
}

/**
 *@name			:popLStack(LinkStack *s,ElemType *data)
 *@description	:���ջ�����ݲ�����ջ��
 *@param		:*s(ջ�ṹ��ָ��),*data(���������)
 *@return		:Status
 *@notice		:none
*/
Status popLStack(LinkStack *s,ElemType *data)
{
    StackNode *assistPtr;		//����ָ��

    *data = (*(s->top)).data;	//�������

    assistPtr = s->top;			//����ջ����ɾ����ջ��
    s->top = s->top->next;
    free(assistPtr);

    (*s).count--;			//��������һ

    return SUCCESS;
}

/**
 *@name			:getTopLStack(LinkStack *s,ElemType *e)
 *@description	:�õ�ջ��Ԫ��
 *@param		:*s(ջ�ṹ��ָ��),*e(���������)
 *@return		:Status
 *@notice		:none
*/
Status getTopLStack(LinkStack *s,ElemType *e)
{
	*e = (*(s->top)).data;		//��ջ�����ݸ��Ƹ�*e
	return SUCCESS;
}

/**
 *@name			:LStackLength(LinkStack *s,int *length)
 *@description	:���ջ����
 *@param		:*s(ջ�ṹ��ָ��),*length
 *@return		:Status
 *@notice		:none
*/
Status LStackLength(LinkStack *s,int *length)
{
	int amount;		//������
    StackNode *assitPtr;	//����ָ��

    assitPtr = s->top;
    for(amount = 0;assitPtr != NULL; amount++)	//����ָ�벻ָ���ʱ��������+1������ָ������
	{
		assitPtr = assitPtr->next;
	}

	*length = amount;

	return SUCCESS;
}

/**
 *@name			:clearLStack(LinkStack *s)
 *@description	:���ջ
 *@param		:*s(ջ�ṹ��ָ��)
 *@return		:Status
 *@notice		:none
*/
Status clearLStack(LinkStack *s)
{
	StackNode *assistPtr;	//����ָ��

    while(s->top != NULL)	//ջ����ʱ��������ǰջ��������ջ��
	{
        assistPtr = s->top;
        s->top = s->top->next;

        free(assistPtr);
	}

    return SUCCESS;
}

/**
 *@name			:destroyLStack(LinkStack *s)
 *@description	:����ջ
 *@param		:*s(ջ�ṹ��ָ��)
 *@return		:Status
 *@notice		:none
*/
Status destroyLStack(LinkStack *s)
{
	StackNode *assistPtr;	//����ָ��

    while(s->top != NULL)	//ջ����ʱ��������ǰջ��������ջ��
	{
        assistPtr = s->top;
        s->top = s->top->next;

        free(assistPtr);
	}

    free(s);		//����ջ�Ľṹ��

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

