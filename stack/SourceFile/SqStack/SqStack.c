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
 *	1.0				2021��4��3��	QiWeidong							������к���
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
 *@name			:initStack
 *@description	:��ʼ��ջ
 *@param		:*s(the *elem), sizes
 *@return		:Status
 *@notice		:none
*/
Status initStack(SqStack *s,int sizes)
{
	if(s == NULL)		//���������Ϊ�ṹ������ռ�ʧ�ܣ�����ERROR
	{
		return ERROR;
	}
	else
	{
		s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));	//�����û�����Ĵ�СΪջ����ռ�

		if(s->elem == NULL)		//�������ʧ�ܣ�����ERROR
		{
			return ERROR;
		}
		else					//����ɹ������ʼ��ջ������SUCCESS
		{
			(*s).top = -1;
			(*s).size = sizes;
			return SUCCESS;
		}
	}
}

/**
 *@name			:isEmptyStack(SqStack *s)
 *@description	:�ж�ջ�Ƿ�Ϊ��
 *@param		:*s(the StackStruct)
 *@return		:Status
 *@notice		:none
*/
Status isEmptyStack(SqStack *s)
{
    if((*s).top == -1)		//���ջ�գ�����1
	{
        return 1;
	}
	else 					//ջ���գ�����0
	{
        return 0;
	}
}

/**
 *@name			:pushStack(SqStack *s,ElemType data)
 *@description	:��ջ����������
 *@param		:*s(the *elem), data
 *@return		:Status
 *@notice		:none
*/
Status pushStack(SqStack *s,ElemType data)
{
    (*s).top++;		//������
    s->elem[(*s).top] = data;

    return SUCCESS;
}

/**
 *@name			:popStack(SqStack *s,ElemType *data)
 *@description	:���ջ�����ݲ�����ջ��
 *@param		:*s(the *elem), *data
 *@return		:Status
 *@notice		:none
*/
Status popStack(SqStack *s,ElemType *data)
{
    *data = s->elem[(*s).top];		//��ջ�����ݴ���data
    (*s).top--;						//����ջ��

    return SUCCESS;
}

/**
 *@name			:getTopStack(SqStack *s,ElemType *e)
 *@description	:�õ�ջ��Ԫ��
 *@param		:*s(StackStruct),*e(data)
 *@return		:Status
 *@notice		:none
*/
Status getTopStack(SqStack *s,ElemType *e)
{
	*e = s->elem[(*s).top];		//����ǰջ�����ݴ���*e

	return SUCCESS;
}

/**
 *@name			:stackLength(SqStack *s,int *length)
 *@description	:���ջ�ĵ�ǰ����
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
 *@description	:���ջ
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
 *@description	:����ջ
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

