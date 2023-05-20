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
			test_Check.push(str[i]); //×óÀ¨ºÅÈëÕ»
		}
		else
		{
			if (test_Check.empty()) { return false; }
			char gettop_pop = ' ';
			gettop_pop = test_Check.top();//»ñÈ¡Õ»¶¥ÔªËØ
			test_Check.pop(); //³öÕ»
			if (str[i] == '(' && gettop_pop != ')') { return false; }
			if (str[i] == '[' && gettop_pop != ']') { return false; }
			if (str[i] == '{' && gettop_pop != '}') { return false; }
		}
	}
	return test_Check.empty(); //±íÊ¾ËùÓÐÆ¥ÅäÍê³É£¬ÊÇ·ñÕ»¿Õ£¬Õ»¿ÕÎªÆ¥Åä³É¹¦
	/*
	
	1.×óÀ¨ºÅÈëÕ»
	2.¼ì²âµ½·Ç×óÀ¨ºÅ(ÅÐ¶ÏÊÇ·ñÎªÕ»¿Õ),Õ»¿ÕÆ¥ÅäÊ§°Ü
	3.·ÇÕ»¿Õ£¬¸ù¾Ý³öÕ»µÄÀ¨ºÅÅÐ¶ÏÊÇ·ñÓÚÆäÏà·û£¬²»Ïà·ûºÏÆ¥ÅäÊ§°Ü
	4.Ñ­»·½áÊøºó£¬×îºóÅÐ¶ÏÊÇ·ñÎªÕ»¿Õ£¬ÊÇÕ»¿Õ£ºÆ¥Åä³É¹¦£¬·ñÔò£ºÆ¥ÅäÊ§°Ü¡£

	*/

}