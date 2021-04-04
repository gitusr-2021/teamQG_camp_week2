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
 *	1.0				2021��4��3��	QiWeidong							������к���
 *
 ***************************************************************************************/
int main()
{
	char option;		//�û������ѡ��
	ElemType data;		//ջ��ŵ�����
    int FctStatus;      //��ź�������ֵ�ı���
    int isStack = 0;   	//����ջ�Ƿ����
    int sizes;			//ջ���ܳ�
    int length; 		//��ǰջ�ĳ���

	SqStack *StackPtr = NULL;	//ջ�Ľṹ���ָ��

	while(1)
	{
		menu();
        optionInput(&option);

        if(isStack == 0)	//ջ������ʱ��ֻ��ִ��ջ�ĳ�ʼ��
		{
            switch(option)
            {
				case 'a':
					printf("������ջ���ܳ���\n");
					numberInput(&sizes);

					StackPtr = (SqStack *)malloc(sizeof(SqStack));	//Ϊջ�ṹ������ռ�
					FctStatus = initStack(StackPtr,sizes);	//��ʼ��ջ�����շ���ֵ

                    Function_Status_PRINT(FctStatus,"��ʼ��ʧ��","��ʼ���ɹ�");		//��ӡ�����������

                    if(FctStatus)		//��ʼ���ɹ���isStack��1
					{
						isStack = 1;
					}

					break;

				default:
					printf("��δ��ʼ��ջ�����ȳ�ʼ��\n");
					break;
            }
		}
		else
		{
            switch(option)
            {
				case 'a':
                    printf("ջ�Ѵ��ڣ������ظ���ʼ��\n");
                    break;

                case 'b':
                    FctStatus = isEmptyStack(StackPtr);	//�����жϺ��������ս��

                    Function_Status_PRINT(FctStatus,"ջ����","ջ��");	//��ӡ���
                    break;

				case 'c':
                    if((*StackPtr).top < ((*StackPtr).size-1))	//ջδ��ʱ����ʾ�û�����
					{
						printf("���������ݣ�\n");
						numberInput(&data);

                        pushStack(StackPtr,data);
                        printf("����������\n");
					}
					else
					{
						printf("ջ����\n");
					}

					break;

				case 'd':
                    if((*StackPtr).top == -1)
					{
						printf("ջ�ѿգ��޷���ջ\n");
					}
					else		//ջ����ʱ�����ݳ�ջ
					{
                        popStack(StackPtr, &data);
                        printf("��ջ������Ϊ%d\n",data);
					}

					break;

				case 'e':
					if((*StackPtr).top == -1)
					{
						printf("ջ�ѿգ�������\n");
					}
					else		//ջ����ʱ����ȡ���ݲ���ӡ
					{
                        getTopStack(StackPtr, &data);
                        printf("��ǰջ������Ϊ%d\n",data);
					}

					break;

				case 'f':
					stackLength(StackPtr,&length);		//�õ���ǰջ�ĳ��Ȳ���ӡ
					printf("��ǰջ����Ϊ%d\n",length);

					break;

				case 'g':
                    clearStack(StackPtr);
                    printf("ջ�����\n");

                    break;

                case 'h':
                	destroyStack(StackPtr);
                	StackPtr = NULL;
                	isStack = 0;
                	printf("ջ������\n");

					break;

				default:
					printf("ѡ����Ч����������Чѡ��\n");
					break;

			}
		}

	}




}
