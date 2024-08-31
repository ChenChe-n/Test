#include "高速精简语言.hPP"
#include <iostream>
#include <unordered_map>

double HC_code::HC_code_虚拟机::访问数据(int 指针)
{
	if (指针>=0)
	{
		return 数据内存[指针];
	}
	else
	{
		return 寄存器[abs(指针)];
	}
}

double HC_code::HC_code_虚拟机::写入数据(int 指针, double 值)
{
	if (指针 >= 0)
	{
		数据内存[指针] = 值;
		return 值;
	}
	else
	{
		寄存器[abs(指针)] = 值;
		return 值;
	}
}

HC_code::HC_code_虚拟机::HC_code_虚拟机()
{

}

HC_code::HC_code_虚拟机::~HC_code_虚拟机()
{

}

int HC_code::HC_code_虚拟机::HC_code_编译器()
{
	源代码.clear();
	std::vector<std::wstring> 语句块;
	std::vector<std::vector<std::wstring>> 指令;
	size_t 字符串指针 = 0;
	size_t n1 = 0;
	//代码分块;
	while (true){
		if (字符串指针 >= 源代码.size() - 1) {
			break;
		};
		if (源代码[字符串指针] == L';') {
			语句块.push_back(源代码.substr(n1, 字符串指针 - n1));
			n1 = 字符串指针 + 1;
		}
		字符串指针++;
	}

	std::wstring 临时字符串;
	std::vector<std::wstring> 临时字符串组;
	// 分割语句块中的单词
	for (const auto& 语句 : 语句块) {
		for (const auto& 字符 : 语句) {
			if (字符 == L' ' || 字符 == L'\t') {
				if (临时字符串.size() != 0) {
					临时字符串组.push_back(临时字符串);
					临时字符串.clear();
				}
			}
			else {
				临时字符串.push_back(字符);
			}
		}
		if (临时字符串.size() != 0) {
			临时字符串组.push_back(临时字符串);
		}
		指令.push_back(临时字符串组);
	}

	// 编译指令
	int 数值id = 0;
	int 字符串id = 0;
	std::unordered_map<std::wstring, int> 数值变量表;
	for (size_t i = 1; i < max_寄存器; i++)
	{
		数值变量表[L"reg" + std::to_wstring(i)] = -1 * i;
	}
	std::unordered_map<std::wstring, int> 字符串变量表;
	std::unordered_map<std::wstring, int> 标签表;
	_字节码 临时字节码;
	for (const auto& 指令组 : 指令) {
		//初始化
		临时字符串 = 指令组[0];
		临时字节码.指令=HC_code_指令类型::error;
		临时字节码.输出		= 0;
		临时字节码.输入1	= 0;
		临时字节码.输入2	= 0;


		//指令判断
		if (临时字符串 == L"label"){
			标签表[指令组[1]] = 源代码.size() - 1;
		}
		if (临时字符串 == L"string") {
			字符串变量表[指令组[1]]=字符串id;
			字符串内存[字符串id]=指令组[2];
			字符串id++;
		}
		if (临时字符串 == L"double") {
			数值变量表[指令组[1]] = 数值id;
			if (指令组[2].size()==0)
			{
				数据内存[数值id] = 0;
			}
			else
			{
				数据内存[数值id] = std::stod(指令组[2]);
			}
			数值id++;
		}
		if (临时字符串==L"end") {
			临时字节码.指令 = HC_code_指令类型::end;
			执行码.push_back(临时字节码);
		}
		else if (临时字符串==L"+")
		{
			临时字节码.指令 = HC_code_指令类型::Addition;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"-")
		{
			临时字节码.指令 = HC_code_指令类型::subtraction;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"*")
		{
			临时字节码.指令 = HC_code_指令类型::multiplication;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"/")
		{
			临时字节码.指令 = HC_code_指令类型::division;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"and")
		{
			临时字节码.指令 = HC_code_指令类型::_and;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"or")
		{
			临时字节码.指令 = HC_code_指令类型::_or;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"not")
		{
			临时字节码.指令 = HC_code_指令类型::_not;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
		}
		else if (临时字符串 == L"if")
		{
			临时字节码.指令 = HC_code_指令类型::_if;
			临时字节码.输入1 = 数值变量表[指令组[1]];
			临时字节码.输入2 = 数值变量表[指令组[2]];
		}
		else if (临时字符串 == L"jump")
		{
			临时字节码.指令 = HC_code_指令类型::jump;
			临时字节码.输入2 = 标签表[指令组[1]];
		}
		else if (临时字符串 == L"jump_if")
		{
			临时字节码.指令 = HC_code_指令类型::jump_if;
			临时字节码.输入1 = 数值变量表[指令组[1]];
			临时字节码.输入2 = 标签表[指令组[2]];
		}
		else if (临时字符串 == L"greater")
		{
			临时字节码.指令 = HC_code_指令类型::greater;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"less")
		{
			临时字节码.指令 = HC_code_指令类型::less;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"equal")
		{
			临时字节码.指令 = HC_code_指令类型::equal;
			临时字节码.输出 = 数值变量表[指令组[1]];
			临时字节码.输入1 = 数值变量表[指令组[2]];
			临时字节码.输入2 = 数值变量表[指令组[3]];
		}
		else if (临时字符串 == L"print")
		{
			if (指令组[1].size() == 0)
			{
				临时字节码.指令 = HC_code_指令类型::print;
				临时字节码.输入1 = 数值变量表[指令组[2]];
				临时字节码.输出 = 0;
			}
			else
			{
				临时字节码.指令 = HC_code_指令类型::print;
				临时字节码.输入1 = 0;
				临时字节码.输出 = 字符串变量表[指令组[1]];
			}
		}

		//添加代码
		执行码.push_back(临时字节码);
	}
	return 0;
}


int HC_code::HC_code_解释器(HC_code_虚拟机& 容器)
{
	int 指令指针 = -1;
	_字节码 字节码;

	while (true)
	{
		指令指针 = 容器.寄存器[0];
		字节码 = 容器.执行码[指令指针];

		指令指针 ++;
		switch (字节码.指令)
		{
		case HC_code::error:
			return -1;
			break;
		case HC_code::end:
			return 0;
			break;
		case HC_code::Addition:
			容器.写入数据(字节码.输出, 容器.访问数据(字节码.输入1) + 容器.访问数据(字节码.输入2));
			break;
		case HC_code::subtraction:
			容器.写入数据(字节码.输出, 容器.访问数据(字节码.输入1) - 容器.访问数据(字节码.输入2));
			break;
		case HC_code::multiplication:
			容器.写入数据(字节码.输出, 容器.访问数据(字节码.输入1) * 容器.访问数据(字节码.输入2));
			break;
		case HC_code::division:
			容器.写入数据(字节码.输出, 容器.访问数据(字节码.输入1) / 容器.访问数据(字节码.输入2));
			break;
		case HC_code::_and:
			容器.写入数据(字节码.输出,(容器.访问数据(字节码.输入1) * 容器.访问数据(字节码.输入2)!= 0.0f) ? 1.0f : 0.0f);
			break;
		case HC_code::_or:
			容器.写入数据(字节码.输出, (容器.访问数据(字节码.输入1) != 0.0f || 容器.访问数据(字节码.输入2) != 0.0f) ? 1.0f : 0.0f);
			break;
		case HC_code::_not:
			容器.写入数据(字节码.输出, (容器.访问数据(字节码.输入1) != 0.0f) ? 0.0f : 1.0f);
			break;
		case HC_code::_if:
			if (容器.访问数据(字节码.输入1) == 0)
			{
				指令指针 = 字节码.输入2;
			}
			break;
		case HC_code::jump:
			指令指针 = 字节码.输入2;
			break;
		case HC_code::jump_if:
			if (容器.访问数据(字节码.输入1) != 0)
			{
				指令指针 = 字节码.输入2;
			}
			break;
		case HC_code::greater:
			容器.写入数据(字节码.输出, (容器.访问数据(字节码.输入1) > 容器.访问数据(字节码.输入2)) ? 1.0f : 0.0f);
			break;
		case HC_code::less:
			容器.写入数据(字节码.输出, (容器.访问数据(字节码.输入1) < 容器.访问数据(字节码.输入2)) ? 1.0f : 0.0f);
			break;
		case HC_code::equal:
			容器.写入数据(字节码.输出, ((float)容器.访问数据(字节码.输入1) == (float)容器.访问数据(字节码.输入2)) ? 1.0f : 0.0f);
			break;
		case HC_code::print:
			if (字节码.输出==0)
			{
				std::wcout<<容器.访问数据(字节码.输入1)<<"\n";
			}
			else
			{
				std::wcout << 容器.字符串内存[字节码.输入2]<<"\n";
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

