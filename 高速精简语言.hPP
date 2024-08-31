#pragma once
#include <vector>
#include <array>
#include <string>
#include <bitset>

namespace HC_code {
	enum HC_code_指令类型 {

		//全部是4字节的指令，第一位指令ID，第二位输出，第三位输入1，第四位输入2
		error			= -1,	//错误
		end				= 0,	//结束 

		Addition		= 1,	//加法
		subtraction		= 2,	//减法
		multiplication	= 3,	//乘法
		division		= 4,	//除法

		_and			= 9, 	//逻辑与
		_or				= 10, 	//逻辑或
		_not			= 11, 	//逻辑非

		_if				= 12,	//if语句
		jump			= 13,	//跳转语句
		jump_if			= 14,	//条件跳转语句

		greater			= 15,	//大于比较
		less			= 16,	//小于比较
		equal			= 17,	//等于比较

		print = 50,	//打印语句  第二位类型，第三位为数据，第四位为字符串
	};
	struct _字节码 {
		HC_code_指令类型 指令;
		int 输出;
		int 输入1;
		int 输入2;
	};
	class HC_code_虚拟机
	{
	public:
	#define max_寄存器_ 32
		//存储最大值
		int max_RAM = 1 * 1024 * 1024;
		int max_寄存器 = max_寄存器_;
		//存储代码
		std::wstring				源代码;
		std::vector<_字节码>		执行码;
		//存储数据
		//正数代表数据内存，负数代表寄存器
		//字符串单独调用
		double						寄存器[max_寄存器_];//0号兼职指令指针
		std::vector<double>			数据内存;
		std::vector<std::wstring>	字符串内存;
	public:
		double 访问数据(int 指针);
		double 写入数据(int 指针, double 值);
		int HC_code_编译器();

		HC_code_虚拟机();
		~HC_code_虚拟机();
	private:

	};

	int HC_code_解释器(HC_code_虚拟机& HC_code_容器);

}