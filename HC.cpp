#include "HC.Hpp"

std::u32string HC::HC代码模块::转换器(std::u32string 源代码)
{

	return U"err";
}

std::wstring HC::HC代码模块::解释器(HC数据模块& 虚拟机)
{
	uint32_t 单字节;
	long long 字节码指针;
	std::chrono::duration<int, std::milli> 喂狗时间{ 50 };
	std::chrono::high_resolution_clock::time_point 上次暂停程序时间 = std::chrono::high_resolution_clock::now();
	while (true)
	{
		字节码指针 = 虚拟机.字节码指针;
		单字节 = 虚拟机.字节码[字节码指针];
		switch (单字节)
		{
		case 0://终止程序指令
			return L"end";
			break;
		case 1://跳转指令
			if (std::chrono::high_resolution_clock::now() - 上次暂停程序时间 > 喂狗时间)
			{
				std::this_thread::sleep_for(std::chrono::duration<int, std::milli>{15});
				上次暂停程序时间 = std::chrono::high_resolution_clock::now();
			}
			虚拟机.字节码指针 = 虚拟机.字节码[字节码指针 + 1];
			break;
		case 2://条件判断指令，当前字节码后第一位是条件，后第二位是条件为真跳转的位置，第三位是条件为假跳转的位置
			if (虚拟机.字节码[字节码指针 + 1])
			{
				虚拟机.字节码指针 = 字节码指针 + 2;
			}
			else
			{
				虚拟机.字节码指针 = 虚拟机.字节码[字节码指针 + 3];
			}
			break;
		case 3://睡眠指令，按字节码下一位数值睡眠对应毫秒数
			std::this_thread::sleep_for(std::chrono::duration<int,std::milli>{虚拟机.字节码[字节码指针 + 1]});
			上次暂停程序时间 = std::chrono::high_resolution_clock::now();
			break;
		case 10:
			break;
		default:
			break;
		}
	}
	return L"err";
}