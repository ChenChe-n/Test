#pragma once
#include <chrono>	
#include <thread>
namespace ʱ��
{

	namespace ��λ {
		std::chrono::duration<long long, std::nano> ����(long long time);
		std::chrono::duration<double> ��(double time);
		std::chrono::duration<double, std::milli> ����(double time);
	}


	void high_sleep(std::chrono::duration<unsigned long long, std::nano> ����);
	class ��ʱ��
	{
	private:
		std::chrono::high_resolution_clock::time_point ��ʼʱ��;
		std::chrono::high_resolution_clock::time_point ����ʱ��;
		std::chrono::high_resolution_clock::time_point ��ͣʱ��;
		std::chrono::duration<long long, std::nano> ��ͣʱ��{ 0 }; // ʹ��duration���洢��ͣʱ��
	public:
		enum ״̬
		{
			δ��ʼ=0,
			��ʱ��ʼ=1,
			��ͣ��ʱ=2,
			������ʱ=3,
		};
		״̬ ��ǰ��ʱ��״̬ = δ��ʼ;
		// ��ʼ��ʱ
		void ��ʼ();

		// ��ͣ��ʱ����¼��ǰʱ����Ϊ��ͣ��
		void ��ͣ();

			// ������ͣ��������ʱ��������ͣ�ڼ��ʱ���ۼӵ�����ͣʱ��
		void ����();

		void ����();


		std::chrono::duration<double, std::milli> ���ؼ�ʱʱ��_����();
		std::chrono::duration<double> ���ؼ�ʱʱ��_��();
		std::chrono::duration<long long, std::nano> ���ؼ�ʱʱ��_����();
		// ���ü�ʱ�����ص���ʼ״̬
		void ����();
	};


	class tick��ʱ��
	{
		bool �Ƿ�Ϊ�߾�����=false;
		int _Ŀ��Tick = 30;
		int _������ = 1;
		long long _��Tick = 0;
		std::chrono::duration<long long, std::nano> _tick���ʱ��{1000000};
		std::chrono::duration<long long, std::nano> _���ʱ��{ 1'000'000'000 };
		std::chrono::duration<long long, std::nano> _ʱ��ƫ��{ 0 };

		void ��ʼ��();

	public:
		��ʱ�� �ڲ���ʱ��;
		int _Tick�� = 0;
		int ��һ��ʱ��tick�� = 0;

		tick��ʱ��(unsigned int Ŀ��tick, std::chrono::duration<long long, std::nano> ���ʱ����);
		tick��ʱ��(unsigned int Ŀ��tick, std::chrono::duration<double> ���ʱ����);

		std::chrono::duration<double, std::milli> ���Ӽ���();


		void �޸�Ŀ��tick����(unsigned int Ŀ��tick, std::chrono::duration<long long, std::nano> ���ʱ����);
		void �޸�Ŀ��tick����(unsigned int Ŀ��tick, std::chrono::duration<double> ���ʱ����);
	private:

	};
}