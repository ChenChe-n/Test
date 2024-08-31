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
//        T ��Ա[4];
//
//        // Ĭ�Ϲ��캯��
//        vector4() = default;
//
//        // ���������캯��
//        vector4(T x, T y, T z, T w) {
//            ��Ա[0] = x;
//            ��Ա[1] = y;
//            ��Ա[2] = z;
//            ��Ա[3] = w;
//        }
//
//        // �������ʼ���Ĺ��캯��
//        vector4(T x[4]) {
//            ��Ա[0] = x[0];
//            ��Ա[1] = x[1];
//            ��Ա[2] = x[2];
//            ��Ա[3] = x[3];
//        }
//
//        // ���ظ�ֵ����������� vector4 ����ֵ
//        vector4& operator=(const vector4& other) {
//            if (this != &other) {
//                ��Ա[0] = other.��Ա[0];
//                ��Ա[1] = other.��Ա[1];
//                ��Ա[2] = other.��Ա[2];
//                ��Ա[3] = other.��Ա[3];
//            }
//            return *this;  // ���ص�ǰ���������
//        }
//
//        // ģ�����ظ�ֵ����������ڱ�����ֵ
//        template<typename T2>
//        vector4& operator=(T2 scalar) {
//            ��Ա[0] = scalar;
//            ��Ա[1] = scalar;
//            ��Ա[2] = scalar;
//            ��Ա[3] = scalar;
//            return *this;  // ���ص�ǰ���������
//        }
//
//        // ���ؼӷ���������������������
//        vector4 operator+(const vector4& other) const {
//            return vector4(
//                ��Ա[0] + other.��Ա[0],
//                ��Ա[1] + other.��Ա[1],
//                ��Ա[2] + other.��Ա[2],
//                ��Ա[3] + other.��Ա[3]
//            );
//        }
//
//        // ���ؼӷ��������������������
//        vector4 operator+(T scalar) const {
//            return vector4(
//                ��Ա[0] + scalar,
//                ��Ա[1] + scalar,
//                ��Ա[2] + scalar,
//                ��Ա[3] + scalar
//            );
//        }
//
//        // ���ؼ�����������������������
//        vector4 operator-(const vector4& other) const {
//            return vector4(
//                ��Ա[0] - other.��Ա[0],
//                ��Ա[1] - other.��Ա[1],
//                ��Ա[2] - other.��Ա[2],
//                ��Ա[3] - other.��Ա[3]
//            );
//        }
//
//        // ���ؼ����������������������
//        vector4 operator-(T scalar) const {
//            return vector4(
//                ��Ա[0] - scalar,
//                ��Ա[1] - scalar,
//                ��Ա[2] - scalar,
//                ��Ա[3] - scalar
//            );
//        }
//
//        // ���س˷���������������������
//        vector4 operator*(const vector4& other) const {
//            return vector4(
//                ��Ա[0] * other.��Ա[0],
//                ��Ա[1] * other.��Ա[1],
//                ��Ա[2] * other.��Ա[2],
//                ��Ա[3] * other.��Ա[3]
//            );
//        }
//
//        // ���س˷��������������������
//        vector4 operator*(T scalar) const {
//            return vector4(
//                ��Ա[0] * scalar,
//                ��Ա[1] * scalar,
//                ��Ա[2] * scalar,
//                ��Ա[3] * scalar
//            );
//        }
//
//        // ���س�����������������������
//        vector4 operator/(const vector4& other) const {
//            return vector4(
//                ��Ա[0] / other.��Ա[0],
//                ��Ա[1] / other.��Ա[1],
//                ��Ա[2] / other.��Ա[2],
//                ��Ա[3] / other.��Ա[3]
//            );
//        }
//
//        // ���س����������������������
//        vector4 operator/(T scalar) const {
//            return vector4(
//                ��Ա[0] / scalar,
//                ��Ա[1] / scalar,
//                ��Ա[2] / scalar,
//                ��Ա[3] / scalar
//            );
//        }
//
//        // ��Ԫ�����������������
//        friend std::ostream& operator<<(std::ostream& os, const vector4& vec) {
//            os << "(" << vec.��Ա[0] << ", " << vec.��Ա[1] << ", " << vec.��Ա[2] << ", " << vec.��Ա[3] << ")";
//            return os;
//        }
//    };
//
//}
namespace ��ʾ
{
	class �ַ�����
	{
	public:
		struct  �ַ�������
		{
			sf::Color �ַ�����ɫ;
			std::wstring* �ַ���;
			int �ַ����ֺ�;
			int ����ID;
			sf::Vector2f �ַ�����ʾ����;
		};
		sf::RenderWindow* window = nullptr;
		std::vector<sf::Font> ����;
		std::vector<sf::Text> �ַ���Ⱦ��;
		int ��ʾ�ַ���(�ַ�������& _�ַ�������);
		�ַ�����();
		~�ַ�����();

	private:

	};

    class �����ܶ�������
    {
    public:
        sf::RenderWindow* window = nullptr;
        sf::Texture* ����ָ�� = nullptr;
        std::vector<sf::Vertex> ��������;

		int ��Ӷ���(std::vector<sf::Vertex> _��������);
		int ��ն���();
		int ��ʾ��������();
        �����ܶ�������();
        ~�����ܶ�������();
    private:
    };

	class �˵���
	{
	#define �˵�_MAX_LEVEL 16
	public:
		struct  _��ʾ����
		{
			enum ���������б�
			{
				ֱ����ʾ=0,
				���뵭��=1,
			};
			//��������
			���������б� ��������;
			//��������
			std::chrono::high_resolution_clock::time_point ������ʼʱ��;
			int ����״̬;
			std::chrono::duration<int, std::nano> ����Ŀ��ʱ��;
			//�˵�����
			sf::Vector2f �˵���ʾ����ƫ��;//������Ǻ��ϼ��˵����ĵ������ƫ��

			//���Ӧ���ڱ�����ʾ
			sf::Vector2f �˵��������δ�С;
			sf::Color �˵�����������ɫ;//�������ͼ�����ֻ������ɫ

			//���Ӧ��Ϊ����ж�����ͼ��
			sf::Vector2f �˵���������;
			sf::Vector2f �˵����δ�С;
			int �˵�����ID = -1;
			sf::Color �˵�������ɫ;//�������ͼ�����������ͼ

			//�������ѡ��������ʾ
			sf::Vector2f �˵��ַ�������;
			sf::Color �ַ�����ɫ;
			int �˵��ַ����ֺ� = -1;
			int �˵�����ID = -1;
			std::wstring �˵��ַ���;

		};


		struct  _��������
		{
			enum ���������б�
			{
				�հײ˵�=0,
				��ʾ�˵�=1,
				��ʾ�����˵�=2,
			};
			//��������
			���������б� ��������;
			//�˵�����
			long long ����{0};
			double ������{0};
			std::wstring �ַ���;
		};


		class �˵�������
		{
		public:
			_��ʾ���� ��ʾ����;
			_�������� ��������;
			void* ���˵�ָ�� = nullptr;
			std::vector<�˵�������> �Ӳ˵��б�;
		public:
			�˵�������();
			~�˵�������();
		private:

		};


	public:
		_��ʾ���� ��ʾ����;
		_�������� ��������;
		std::vector<�˵�������> �Ӳ˵��б�;
		sf::RenderWindow* window = nullptr;
		sf::Texture* ����ָ�� = nullptr;

		//�˵���֡��ʾ����
		std::vector<sf::Vector2f> �����ж�����[�˵�_MAX_LEVEL];
		std::vector<�����ܶ�������> ������ʾ����[�˵�_MAX_LEVEL];
		std::vector<�ַ�����::�ַ�������> �ַ�����ʾ����[�˵�_MAX_LEVEL];

	public:
		int ��ʾ�˵�();
		int ����Ӳ˵�(�˵������� _�Ӳ˵�);
		int ɾ���Ӳ˵�(�˵�������* ���˵�, unsigned char �Ӳ˵�����);

		�˵���();
		~�˵���();
	};
}