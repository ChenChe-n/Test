#pragma once
#include <vector>
#include <string>
#include <thread>

namespace HC {
	class HC代码模块 {
		enum 字节码列表
		{
			//基础指令
			终止程序 =	0,
			控_跳转 =	1,//跳转配合如果构造循环
			控_如果 =	2,
			控_睡眠	=	3,
			//数据寻址
			//数据结构  堆_访问数组 xxx  堆_访问整数 xxxx

			堆_申请数组 =	10,
			堆_申请整数,
			堆_申请浮点,
			堆_申请字符,

			堆_访问数组,
			堆_访问整数,
			堆_访问浮点,
			堆_访问字符,

			堆_删除数组,
			堆_删除整数,
			堆_删除浮点,
			堆_删除字符,
			//逻辑运算
			控_与 =		25,
			控_或,
			控_非,
			//比较指令
			控_等于比较		=	30,
			控_大于等于比较,
			控_大于比较,
			控_小于等于比较,
			控_小于比较,
			//数值操作
			值_赋值 =	101,
			值_加 =		102,
			值_减 =		103,
			值_乘 =		104,
			值_除 =		105,
			值_乘方 =	106,
			值_开根 =	107,
			//

		};
		class HC数据模块
		{
		public:
			std::u32string				源代码{};
			std::u32string				字节码{};

			long long 寄存器[16]{};
			long long 字节码指针{ 0 };
			//数据区用于存储变量数据
			//空闲区用于存储连续数组中间的空闲内存
			std::vector<std::vector<int>>	数组区{};
			std::vector<unsigned int>		空闲_数组区{};

			std::vector<long long>		整数区{};
			std::vector<unsigned int>	空闲_整数区{};

			std::vector<double>			浮点区{};
			std::vector<unsigned int>	空闲_浮点区{};

			std::vector<std::string>	字符区{};
			std::vector<unsigned int>	空闲_字符区{};
		};

	public:
		std::vector<HC数据模块> 数据{};

		std::u32string 转换器(std::u32string 源代码);

		std::wstring 解释器(HC数据模块& 虚拟机);

	};
}