#include "工具.hpp"

template<typename T>
工具::vector容器<T>::vector容器()
{
}

template<typename T>
工具::vector容器<T>::~vector容器()
{
}

template<typename T>
// 向量添加元素函数，用于将元素指针添加到向量容器中。如果内存占用列表中有空闲位置，则优先使用这些位置；否则，将元素指针添加到列表末尾。
int 工具::vector容器<T>::向量添加元素(T* 元素指针)
{
	if (内存占用.size()>0)
	{
		列表[内存占用.pop_back()] = 元素指针;
	}
	else
	{
		列表.push_back(元素指针);
	}
	return 0;
}


template<typename T>
// 该函数用于从vector容器中删除指定索引位置的元素，并将其内存占用情况记录下来。
int 工具::vector容器<T>::向量删除元素(int 索引)
{
	delete 列表[索引];
	列表[索引] = nullptr;
	内存占用.push_back(索引);
	return 0;
}

