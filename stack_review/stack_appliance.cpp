#include <iostream>
#include <stack>
#include "stack_appliance.h"
using namespace std;

bool bracketCheck(const char str[],int length)
{
	stack<char> test_Check;
	for (int i = 0; i < length; i++)
	{
		if (str[i]=='('||str[i]=='['||str[i]=='{')
		{
			test_Check.push(str[i]); //��������ջ
		}
		else
		{
			if (test_Check.empty()) { return false; }
			char gettop_pop = ' ';
			gettop_pop = test_Check.top();//��ȡջ��Ԫ��
			test_Check.pop(); //��ջ
			if (str[i] == '(' && gettop_pop != ')') { return false; }
			if (str[i] == '[' && gettop_pop != ']') { return false; }
			if (str[i] == '{' && gettop_pop != '}') { return false; }
		}
	}
	return test_Check.empty(); //��ʾ����ƥ����ɣ��Ƿ�ջ�գ�ջ��Ϊƥ��ɹ�
	/*
	
	1.��������ջ
	2.��⵽��������(�ж��Ƿ�Ϊջ��),ջ��ƥ��ʧ��
	3.��ջ�գ����ݳ�ջ�������ж��Ƿ�����������������ƥ��ʧ��
	4.ѭ������������ж��Ƿ�Ϊջ�գ���ջ�գ�ƥ��ɹ�������ƥ��ʧ�ܡ�

	*/

}