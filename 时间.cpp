#include <chrono>	
#include <thread>
#include "时间.hpp"
namespace 时间
{

	namespace 单位 {
		std::chrono::duration<long long, std::nano> 纳秒(long long time) {
			return std::chrono::duration<long long, std::nano>{time};
		}
		std::chrono::duration<double> 秒(double time) {
			return std::chrono::duration<double>{time};
		}
		std::chrono::duration<double, std::milli> 毫秒(double time) {
			return std::chrono::duration<double, std::milli>{time};
		}
	}


	void high_sleep(std::chrono::duration<unsigned long long, std::nano> 纳秒) {
		auto nowtime = std::chrono::high_resolution_clock::now();
		auto endtime = nowtime + 纳秒;
		// 定义一个空的 lambda 表达式
		auto empty_lambda = []() {};

		// 粗略等待，直到接近目标时间
		while (std::chrono::high_resolution_clock::now() < endtime - 单位::毫秒(15.6)) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		// 然后使用忙等待实现更高的精度
		while (std::chrono::high_resolution_clock::now() < endtime) {
			empty_lambda(); // 调用空的 lambda 表达式，避免被编译器优化
		}
	}

	void  计时器::开始() {
		if (当前计时器状态 == 未开始 or 当前计时器状态 == 结束计时) {
			重置();
			开始时间 = std::chrono::high_resolution_clock::now();
			当前计时器状态 = 计时开始;
		}
	}

	// 暂停计时，记录当前时间作为暂停点
	void 计时器::暂停() {
		if (当前计时器状态 == 计时开始) {
			暂停时间 = std::chrono::high_resolution_clock::now();
			当前计时器状态 = 暂停计时;
		}
	}

	// 结束暂停并继续计时，计算暂停期间的时间差并累加到总暂停时长
	void 计时器::继续() {
		if (当前计时器状态 == 暂停计时) {
			暂停时长 += std::chrono::high_resolution_clock::now() - 暂停时间;
			当前计时器状态 = 计时开始;
		}
	}

	void 计时器::结束() {
		if (当前计时器状态 == 计时开始) {
			结束时间 = std::chrono::high_resolution_clock::now();
			当前计时器状态 = 结束计时;
		}
	}


	std::chrono::duration<double, std::milli> 计时器::返回计时时长_毫秒() {
		return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(返回计时时长_纳秒());
	}
	std::chrono::duration<double> 计时器::返回计时时长_秒() {
		return std::chrono::duration_cast<std::chrono::duration<double>>(返回计时时长_纳秒());
	}
	std::chrono::duration<long long, std::nano> 计时器::返回计时时长_纳秒() {

		switch (当前计时器状态)
		{
		case 时间::计时器::未开始:
			return std::chrono::duration<long long, std::nano>{0};
		case 时间::计时器::计时开始:
			return std::chrono::high_resolution_clock::now() - 开始时间 - 暂停时长;
		case 时间::计时器::暂停计时:
			return 暂停时间 - 开始时间 - 暂停时长;
		case 时间::计时器::结束计时:
			return 结束时间 - 开始时间 - 暂停时长;
		default:
			return std::chrono::duration<long long, std::nano>{0};
		}
	}
	// 重置计时器，回到初始状态
	void 计时器::重置() {
		当前计时器状态 = 未开始;
		开始时间 = std::chrono::high_resolution_clock::time_point{};
		暂停时间 = std::chrono::high_resolution_clock::time_point{};
		暂停时长 = std::chrono::duration<long long, std::nano>{ 0 };
	}



	void tick计时器::初始化() {
		_tick间隔时间 = _间隔时间 / _目标Tick;
		_总轮数 = 1;
		_总Tick = 0;
		内部计时器.重置();
	}

	tick计时器::tick计时器(unsigned int 目标tick, std::chrono::duration<long long, std::nano> 间隔时间数) {
		是否为高精休眠 = true;
		_目标Tick = 目标tick;
		_间隔时间 = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(间隔时间数);
		初始化();
	}
	tick计时器::tick计时器(unsigned int 目标tick, std::chrono::duration<double> 间隔时间数) {
		是否为高精休眠 = false;
		_目标Tick = 目标tick;
		_间隔时间 = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(间隔时间数);
		初始化();
	}

	std::chrono::duration<double, std::milli> tick计时器::增加计数() {
		内部计时器.开始();

		if (内部计时器.返回计时时长_纳秒() >= _间隔时间 * _总轮数)
		{
			上一段时间tick数 = _Tick数;
			_总轮数++;
			_Tick数 = 0;
		}

		auto tt1 = _总Tick * _tick间隔时间 - 内部计时器.返回计时时长_纳秒();

		if (tt1 > std::chrono::duration<long long, std::nano>{0})
		{
			if (是否为高精休眠)
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

		_Tick数++;
		_总Tick++;
		return tt1;
	}




	void tick计时器::修改目标tick属性(unsigned int 目标tick, std::chrono::duration<long long, std::nano> 间隔时间数)
	{
		是否为高精休眠 = true;
		_目标Tick = 目标tick;
		_间隔时间 = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(间隔时间数);
		初始化();
	}
	void tick计时器::修改目标tick属性(unsigned int 目标tick, std::chrono::duration<double> 间隔时间数)
	{
		是否为高精休眠 = false;
		_目标Tick = 目标tick;
		_间隔时间 = std::chrono::duration_cast<std::chrono::duration<long long, std::nano>>(间隔时间数);
		初始化();
	}

}