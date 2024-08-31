#pragma once
#include <vector>
namespace 工具 {
	template<typename T>
	class vector容器
	{
	private:
		std::vector<int> 内存占用;
	public:
		std::vector<T*> 列表;
		vector容器();
		~vector容器();
		int 向量添加元素(T* 元素指针);
		int 向量删除元素(int 索引);
	};
}