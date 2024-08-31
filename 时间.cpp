#include <chrono>	
#include <thread>
#include "ʱ��.hpp"
namespace ʱ��
{

	namespace ��λ {
		std::chrono::duration<long long, std::nano> ����(long long time) {
			return std::chrono::duration<long long, std::nano>{time};
		}
		std::chrono::duration<double> ��(double time) {
			return std::chrono::duration<double>{time};
		}
		std::chrono::duration<double, std::milli> ����(double time) {
			return std::chrono::duration<double, std::milli>{time};
		}
	}


	void high_sleep(std::chrono::duration<unsigned long long, std::nano> ����) {
		auto nowtime = std::chrono::high_resolution_clock::now();
		auto endtime = nowtime + ����;
		// ����һ���յ� lambda ���ʽ
		auto empty_lambda = []() {};

		// ���Եȴ���ֱ���ӽ�Ŀ��ʱ��
		while (std::chrono::high_resolution_clock::now() < endtime - ��λ::����(15.6)) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		// Ȼ��ʹ��æ�ȴ�ʵ�ָ��ߵľ���
		while (std::chrono::high_resolution_clock::now() < endtime) {
			empty_lambda(); // ���ÿյ� lambda ���ʽ�����ⱻ�������Ż�
		}
	}

	void  ��ʱ��::��ʼ() {
		if (��ǰ��ʱ��״̬ == δ��ʼ or ��ǰ��ʱ��״̬ == ������ʱ) {
			����();
			��ʼʱ�� = std::chrono::high_resolution_clock::now();
			��ǰ��ʱ��״̬ = ��ʱ��ʼ;
		}
	}

	// ��ͣ��ʱ����¼��ǰʱ����Ϊ��ͣ��
	void ��ʱ��::��ͣ() {
		if (��ǰ��ʱ��״̬ == ��ʱ��ʼ) {
			��ͣʱ�� = std::chrono::high_resolution_clock::now();
			��ǰ��ʱ��״̬ = ��ͣ��ʱ;
		}
	}

	// ������ͣ��������ʱ��������ͣ�ڼ��ʱ���ۼӵ�����ͣʱ��
	void ��ʱ��::����() {
		if (��ǰ��ʱ��״̬ == ��ͣ��ʱ) {
			��ͣʱ�� += std::chrono::high_resolution_clock::now() - ��ͣʱ��;
			��ǰ��ʱ��״̬ = ��ʱ��ʼ;
		}
	}

	void ��ʱ��::����() {
		if (��ǰ��ʱ��״̬ == ��ʱ��ʼ) {
			����ʱ�� = std::chrono::high_resolution_clock::now();
			��ǰ��ʱ��״̬ = ������ʱ;
		}
	}


	std::chrono::duration<double, std::milli> ��ʱ��::���ؼ�ʱʱ��_����() {
		return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(���ؼ�ʱʱ��_����());
	}
	std::chrono::duration<double> ��ʱ��::���ؼ�ʱʱ��_��() {
		return std::chrono::duration_cast<std::chrono::duration<double>>(���ؼ�ʱʱ��_����());
	}
	std::chrono::duration<long long, std::nano> ��ʱ��::���ؼ�ʱʱ��_����() {

		switch (��ǰ��ʱ��״̬)
		{
		case ʱ��::��ʱ��::δ��ʼ:
			return std::chrono::duration<long long, std::nano>{0};
		case ʱ��::��ʱ��::��ʱ��ʼ:
			return std::chrono::high_resolution_clock::now() - ��ʼʱ�� - ��ͣʱ��;
		case ʱ��::��ʱ��::��ͣ��ʱ:
			return ��ͣʱ�� - ��ʼʱ�� - ��ͣʱ��;
		case ʱ��::��ʱ��::������ʱ:
			return ����ʱ�� - ��ʼʱ�� - ��ͣʱ��;
		default:
			return std::chrono::duration<long long, std::nano>{0};
		}
	}
	// ���ü�ʱ�����ص���ʼ״̬
	void ��ʱ��::����() {
		��ǰ��ʱ��״̬ = δ��ʼ;
		��ʼʱ�� = std::chrono::high_resolution_clock::time_point{};
		��ͣʱ�� = std::chrono::high_resolution_clock::time_point{};
		��ͣʱ�� = std::chrono::duration<long long, std::nano>{ 0 };
	}



	void tick��ʱ��::��ʼ��() {
		_tick���ʱ�� = _���ʱ�� / _Ŀ��Tick;
		_������ = 1;
		_��Tick = 0;
		�ڲ���ʱ��.����();
	}

	tick��ʱ��::tick��ʱ��(unsigned int Ŀ��tick, std::chrono::duration<long long, std::nano> ���ʱ����) {
		�Ƿ�Ϊ�߾����� = true;
		_Ŀ��Tick = Ŀ��tick;
		_���ʱ�� = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(���ʱ����);
		��ʼ��();
	}
	tick��ʱ��::tick��ʱ��(unsigned int Ŀ��tick, std::chrono::duration<double> ���ʱ����) {
		�Ƿ�Ϊ�߾����� = false;
		_Ŀ��Tick = Ŀ��tick;
		_���ʱ�� = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(���ʱ����);
		��ʼ��();
	}

	std::chrono::duration<double, std::milli> tick��ʱ��::���Ӽ���() {
		�ڲ���ʱ��.��ʼ();

		if (�ڲ���ʱ��.���ؼ�ʱʱ��_����() >= _���ʱ�� * _������)
		{
			��һ��ʱ��tick�� = _Tick��;
			_������++;
			_Tick�� = 0;
		}

		auto tt1 = _��Tick * _tick���ʱ�� - �ڲ���ʱ��.���ؼ�ʱʱ��_����();

		if (tt1 > std::chrono::duration<long long, std::nano>{0})
		{
			if (�Ƿ�Ϊ�߾�����)
			{
				high_sleep(tt1);
			}
			else
			{
				//if (tt1>= std::chrono::duration<long long, std::nano>{15000000})
				//{
				//	std::this_thread::sleep_for(tt1);
				//}
				//else
				//{
				//	high_sleep(tt1);
				//}
				std::this_thread::sleep_for(tt1);
			}
		}

		_Tick��++;
		_��Tick++;
		return tt1;
	}




	void tick��ʱ��::�޸�Ŀ��tick����(unsigned int Ŀ��tick, std::chrono::duration<long long, std::nano> ���ʱ����)
	{
		�Ƿ�Ϊ�߾����� = true;
		_Ŀ��Tick = Ŀ��tick;
		_���ʱ�� = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(���ʱ����);
		��ʼ��();
	}
	void tick��ʱ��::�޸�Ŀ��tick����(unsigned int Ŀ��tick, std::chrono::duration<double> ���ʱ����)
	{
		�Ƿ�Ϊ�߾����� = false;
		_Ŀ��Tick = Ŀ��tick;
		_���ʱ�� = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(���ʱ����);
		��ʼ��();
	}

}