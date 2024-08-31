#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>
#include <chrono>
//namespace sf {
//    template<typename T>
//    class vector4 {
//    public:
//        T 成员[4];
//
//        // 默认构造函数
//        vector4() = default;
//
//        // 参数化构造函数
//        vector4(T x, T y, T z, T w) {
//            成员[0] = x;
//            成员[1] = y;
//            成员[2] = z;
//            成员[3] = w;
//        }
//
//        // 用数组初始化的构造函数
//        vector4(T x[4]) {
//            成员[0] = x[0];
//            成员[1] = x[1];
//            成员[2] = x[2];
//            成员[3] = x[3];
//        }
//
//        // 重载赋值运算符，用于 vector4 对象赋值
//        vector4& operator=(const vector4& other) {
//            if (this != &other) {
//                成员[0] = other.成员[0];
//                成员[1] = other.成员[1];
//                成员[2] = other.成员[2];
//                成员[3] = other.成员[3];
//            }
//            return *this;  // 返回当前对象的引用
//        }
//
//        // 模板重载赋值运算符，用于标量赋值
//        template<typename T2>
//        vector4& operator=(T2 scalar) {
//            成员[0] = scalar;
//            成员[1] = scalar;
//            成员[2] = scalar;
//            成员[3] = scalar;
//            return *this;  // 返回当前对象的引用
//        }
//
//        // 重载加法运算符，向量与向量相加
//        vector4 operator+(const vector4& other) const {
//            return vector4(
//                成员[0] + other.成员[0],
//                成员[1] + other.成员[1],
//                成员[2] + other.成员[2],
//                成员[3] + other.成员[3]
//            );
//        }
//
//        // 重载加法运算符，向量与标量相加
//        vector4 operator+(T scalar) const {
//            return vector4(
//                成员[0] + scalar,
//                成员[1] + scalar,
//                成员[2] + scalar,
//                成员[3] + scalar
//            );
//        }
//
//        // 重载减法运算符，向量与向量相减
//        vector4 operator-(const vector4& other) const {
//            return vector4(
//                成员[0] - other.成员[0],
//                成员[1] - other.成员[1],
//                成员[2] - other.成员[2],
//                成员[3] - other.成员[3]
//            );
//        }
//
//        // 重载减法运算符，向量与标量相减
//        vector4 operator-(T scalar) const {
//            return vector4(
//                成员[0] - scalar,
//                成员[1] - scalar,
//                成员[2] - scalar,
//                成员[3] - scalar
//            );
//        }
//
//        // 重载乘法运算符，向量与向量相乘
//        vector4 operator*(const vector4& other) const {
//            return vector4(
//                成员[0] * other.成员[0],
//                成员[1] * other.成员[1],
//                成员[2] * other.成员[2],
//                成员[3] * other.成员[3]
//            );
//        }
//
//        // 重载乘法运算符，向量与标量相乘
//        vector4 operator*(T scalar) const {
//            return vector4(
//                成员[0] * scalar,
//                成员[1] * scalar,
//                成员[2] * scalar,
//                成员[3] * scalar
//            );
//        }
//
//        // 重载除法运算符，向量与向量相除
//        vector4 operator/(const vector4& other) const {
//            return vector4(
//                成员[0] / other.成员[0],
//                成员[1] / other.成员[1],
//                成员[2] / other.成员[2],
//                成员[3] / other.成员[3]
//            );
//        }
//
//        // 重载除法运算符，向量与标量相除
//        vector4 operator/(T scalar) const {
//            return vector4(
//                成员[0] / scalar,
//                成员[1] / scalar,
//                成员[2] / scalar,
//                成员[3] / scalar
//            );
//        }
//
//        // 友元函数，用于输出向量
//        friend std::ostream& operator<<(std::ostream& os, const vector4& vec) {
//            os << "(" << vec.成员[0] << ", " << vec.成员[1] << ", " << vec.成员[2] << ", " << vec.成员[3] << ")";
//            return os;
//        }
//    };
//
//}
namespace 显示
{
	class 字符串类
	{
	public:
		struct  字符串属性
		{
			sf::Color 字符串颜色;
			std::wstring* 字符串;
			int 字符串字号;
			int 字体ID;
			sf::Vector2f 字符串显示坐标;
		};
		sf::RenderWindow* window = nullptr;
		std::vector<sf::Font> 字体;
		std::vector<sf::Text> 字符渲染器;
		int 显示字符串(字符串属性& _字符串属性);
		字符串类();
		~字符串类();

	private:

	};

    class 高性能顶点数组
    {
    public:
        sf::RenderWindow* window = nullptr;
        sf::Texture* 纹理指针 = nullptr;
        std::vector<sf::Vertex> 顶点数据;

		int 添加顶点(std::vector<sf::Vertex> _顶点数据);
		int 清空顶点();
		int 显示顶点数组();
        高性能顶点数组();
        ~高性能顶点数组();
    private:
    };

	class 菜单类
	{
	#define 菜单_MAX_LEVEL 16
	public:
		struct  _显示数据
		{
			enum 动画类型列表
			{
				直接显示=0,
				淡入淡出=1,
			};
			//动画类型
			动画类型列表 动画类型;
			//动画属性
			std::chrono::high_resolution_clock::time_point 动画开始时间;
			int 动画状态;
			std::chrono::duration<int, std::nano> 动画目标时长;
			//菜单属性
			sf::Vector2f 菜单显示中心偏移;//代表的是和上级菜单中心点的坐标偏移

			//这个应用于背景显示
			sf::Vector2f 菜单背景矩形大小;
			sf::Color 菜单背景矩形颜色;//如果有贴图，这个只会上颜色

			//这个应用为鼠标判定，贴图等
			sf::Vector2f 菜单矩形坐标;
			sf::Vector2f 菜单矩形大小;
			int 菜单纹理ID = -1;
			sf::Color 菜单矩形颜色;//如果有贴图，这个会上贴图

			//这个用于选项名称显示
			sf::Vector2f 菜单字符串坐标;
			sf::Color 字符串颜色;
			int 菜单字符串字号 = -1;
			int 菜单字体ID = -1;
			std::wstring 菜单字符串;

		};


		struct  _功能数据
		{
			enum 功能类型列表
			{
				空白菜单=0,
				显示菜单=1,
				显示容器菜单=2,
			};
			//功能类型
			功能类型列表 功能类型;
			//菜单数据
			long long 整数{0};
			double 浮点数{0};
			std::wstring 字符串;
		};


		class 菜单数据类
		{
		public:
			_显示数据 显示数据;
			_功能数据 功能数据;
			void* 父菜单指针 = nullptr;
			std::vector<菜单数据类> 子菜单列表;
		public:
			菜单数据类();
			~菜单数据类();
		private:

		};


	public:
		_显示数据 显示数据;
		_功能数据 功能数据;
		std::vector<菜单数据类> 子菜单列表;
		sf::RenderWindow* window = nullptr;
		sf::Texture* 纹理指针 = nullptr;

		//菜单单帧显示队列
		std::vector<sf::Vector2f> 窗口判定队列[菜单_MAX_LEVEL];
		std::vector<高性能顶点数组> 矩形显示队列[菜单_MAX_LEVEL];
		std::vector<字符串类::字符串属性> 字符串显示队列[菜单_MAX_LEVEL];

	public:
		int 显示菜单();
		int 添加子菜单(菜单数据类 _子菜单);
		int 删除子菜单(菜单数据类* 父菜单, unsigned char 子菜单索引);

		菜单类();
		~菜单类();
	};
}