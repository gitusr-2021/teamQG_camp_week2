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
int main()
{
	char option;		//�û������ѡ��
	ElemType data;		//ջ��ŵ�����
    int FctStatus;      //��ź�������ֵ�ı���
    int length; 		//��ǰջ�ĳ���

    LinkStack *LStackStrPtr = NULL;	//ջ�ṹ���ָ��

	while(1)
	{
		menu();
        optionInput(&option);

        if(LStackStrPtr == NULL)	//ջ������ʱ��ֻ��ִ��ջ�ĳ�ʼ��
		{
            switch(option)
            {
				case 'a':
					LStackStrPtr = (LinkStack *)malloc(sizeof(LinkStack));	//Ϊջ�ṹ������ռ�
					FctStatus = initLStack(LStackStrPtr);	//��ʼ��ջ�����շ���ֵ

                    Function_Status_PRINT(FctStatus,"��ʼ��ʧ��","��ʼ���ɹ�");		//��ӡ�����������

					break;

				default:
					printf("��δ��ʼ��ջ�����ȳ�ʼ��\n");
					break;
            }
		}
		else		//ջ����ʱ��ִ�г�ʼ���������������
		{
            switch(option)
            {
				case 'a':
                    printf("ջ�Ѵ��ڣ������ظ���ʼ��\n");
                    break;

                case 'b':
                    FctStatus = isEmptyLStack(LStackStrPtr);	//�����жϺ��������ս��

                    Function_Status_PRINT(FctStatus,"ջ����","ջ��");	//��ӡ���
                    break;

				case 'c':
						printf("���������ݣ�\n");
						numberInput(&data);

						FctStatus = pushLStack(LStackStrPtr,data);
						Function_Status_PRINT(FctStatus,"��ջʧ��","��ջ�ɹ�");

					break;


				case 'd':
                    if(LStackStrPtr->top == NULL)
					{
						printf("ջ�ѿգ��޷���ջ\n");
					}
					else		//ջ����ʱ�����ݳ�ջ
					{
                        popLStack(LStackStrPtr, &data);
                        printf("��ջ������Ϊ%d\n",data);
					}

					break;


				case 'e':
					if(LStackStrPtr->top == NULL)
					{
						printf("ջ�ѿգ�������\n");
					}
					else		//ջ����ʱ����ȡ���ݲ���ӡ
					{
                        getTopLStack(LStackStrPtr, &data);
                        printf("��ǰջ������Ϊ%d\n",data);
					}

					break;


				case 'f':
					LStackLength(LStackStrPtr,&length);		//�õ���ǰջ�ĳ��Ȳ���ӡ
					printf("��ǰջ����Ϊ%d\n",length);

					break;


				case 'g':
                    clearLStack(LStackStrPtr);
                    printf("ջ�����\n");

                    break;

                case 'h':
                	destroyLStack(LStackStrPtr);
                	LStackStrPtr = NULL;
                	printf("ջ������\n");

					break;

				default:
					printf("ѡ����Ч����������Чѡ��\n");
					break;

			}
		}

	}





}
