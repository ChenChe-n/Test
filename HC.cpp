#include "HC.Hpp"

std::u32string HC::HC����ģ��::ת����(std::u32string Դ����)
{

	return U"err";
}

std::wstring HC::HC����ģ��::������(HC����ģ��& �����)
{
	uint32_t ���ֽ�;
	long long �ֽ���ָ��;
	std::chrono::duration<int, std::milli> ι��ʱ��{ 50 };
	std::chrono::high_resolution_clock::time_point �ϴ���ͣ����ʱ�� = std::chrono::high_resolution_clock::now();
	while (true)
	{
		�ֽ���ָ�� = �����.�ֽ���ָ��;
		���ֽ� = �����.�ֽ���[�ֽ���ָ��];
		switch (���ֽ�)
		{
		case 0://��ֹ����ָ��
			return L"end";
			break;
		case 1://��תָ��
			if (std::chrono::high_resolution_clock::now() - �ϴ���ͣ����ʱ�� > ι��ʱ��)
			{
				std::this_thread::sleep_for(std::chrono::duration<int, std::milli>{15});
				�ϴ���ͣ����ʱ�� = std::chrono::high_resolution_clock::now();
			}
			�����.�ֽ���ָ�� = �����.�ֽ���[�ֽ���ָ�� + 1];
			break;
		case 2://�����ж�ָ���ǰ�ֽ�����һλ����������ڶ�λ������Ϊ����ת��λ�ã�����λ������Ϊ����ת��λ��
			if (�����.�ֽ���[�ֽ���ָ�� + 1])
			{
				�����.�ֽ���ָ�� = �ֽ���ָ�� + 2;
			}
			else
			{
				�����.�ֽ���ָ�� = �����.�ֽ���[�ֽ���ָ�� + 3];
			}
			break;
		case 3://˯��ָ����ֽ�����һλ��ֵ˯�߶�Ӧ������
			std::this_thread::sleep_for(std::chrono::duration<int,std::milli>{�����.�ֽ���[�ֽ���ָ�� + 1]});
			�ϴ���ͣ����ʱ�� = std::chrono::high_resolution_clock::now();
			break;
		case 10:
			break;
		default:
			break;
		}
	}
	return L"err";
}