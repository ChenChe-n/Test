#pragma once
#include <vector>
namespace ���� {
	template<typename T>
	class vector����
	{
	private:
		std::vector<int> �ڴ�ռ��;
	public:
		std::vector<T*> �б�;
		vector����();
		~vector����();
		int �������Ԫ��(T* Ԫ��ָ��);
		int ����ɾ��Ԫ��(int ����);
	};
}