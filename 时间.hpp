#pragma once
#include <chrono>	
#include <thread>
namespace 时间
{

	namespace 单位 {
		std::chrono::duration<long long, std::nano> 纳秒(long long time);
		std::chrono::duration<double> 秒(double time);
		std::chrono::duration<double, std::milli> 毫秒(double time);
	}


	void high_sleep(std::chrono::duration<unsigned long long, std::nano> 纳秒);
	class 计时器
	{
	private:
		std::chrono::high_resolution_clock::time_point 开始时间;
		std::chrono::high_resolution_clock::time_point 结束时间;
		std::chrono::high_resolution_clock::time_point 暂停时间;
		std::chrono::duration<long long, std::nano> 暂停时长{ 0 }; // 使用duration来存储暂停时长
	public:
		enum 状态
		{
			未开始=0,
			计时开始=1,
			暂停计时=2,
			结束计时=3,
		};
		状态 当前计时器状态 = 未开始;
		// 开始计时
		void 开始();

		// 暂停计时，记录当前时间作为暂停点
		void 暂停();

			// 结束暂停并继续计时，计算暂停期间的时间差并累加到总暂停时长
		void 继续();

		void 结束();


		std::chrono::duration<double, std::milli> 返回计时时长_毫秒();
		std::chrono::duration<double> 返回计时时长_秒();
		std::chrono::duration<long long, std::nano> 返回计时时长_纳秒();
		// 重置计时器，回到初始状态
		void 重置();
	};


	class tick计时器
	{
		bool 是否为高精休眠=false;
		int _目标Tick = 30;
		int _总轮数 = 1;
		long long _总Tick = 0;
		std::chrono::duration<long long, std::nano> _tick间隔时间{1000000};
		std::chrono::duration<long long, std::nano> _间隔时间{ 1'000'000'000 };
		std::chrono::duration<long long, std::nano> _时间偏移{ 0 };

		void 初始化();

	public:
		计时器 内部计时器;
		int _Tick数 = 0;
		int 上一段时间tick数 = 0;

		tick计时器(unsigned int 目标tick, std::chrono::duration<long long, std::nano> 间隔时间数);
		tick计时器(unsigned int 目标tick, std::chrono::duration<double> 间隔时间数);

		std::chrono::duration<double, std::milli> 增加计数();


		void 修改目标tick属性(unsigned int 目标tick, std::chrono::duration<long long, std::nano> 间隔时间数);
		void 修改目标tick属性(unsigned int 目标tick, std::chrono::duration<double> 间隔时间数);
	private:

	};
}