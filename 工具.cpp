#include "����.hpp"

template<typename T>
����::vector����<T>::vector����()
{
}

template<typename T>
����::vector����<T>::~vector����()
{
}

template<typename T>
// �������Ԫ�غ��������ڽ�Ԫ��ָ����ӵ����������С�����ڴ�ռ���б����п���λ�ã�������ʹ����Щλ�ã����򣬽�Ԫ��ָ����ӵ��б�ĩβ��
int ����::vector����<T>::�������Ԫ��(T* Ԫ��ָ��)
{
	if (�ڴ�ռ��.size()>0)
	{
		�б�[�ڴ�ռ��.pop_back()] = Ԫ��ָ��;
	}
	else
	{
		�б�.push_back(Ԫ��ָ��);
	}
	return 0;
}


template<typename T>
// �ú������ڴ�vector������ɾ��ָ������λ�õ�Ԫ�أ��������ڴ�ռ�������¼������
int ����::vector����<T>::����ɾ��Ԫ��(int ����)
{
	delete �б�[����];
	�б�[����] = nullptr;
	�ڴ�ռ��.push_back(����);
	return 0;
}

