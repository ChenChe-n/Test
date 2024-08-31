#include <iostream>
#include "显示.hpp"
namespace 显示
{
    int 字符串类::显示字符串(字符串属性& _字符串属性)
    {
        字符渲染器[_字符串属性.字体ID].setFillColor(_字符串属性.字符串颜色);
        字符渲染器[_字符串属性.字体ID].setCharacterSize(_字符串属性.字符串字号);
        字符渲染器[_字符串属性.字体ID].setPosition(_字符串属性.字符串显示坐标);
        字符渲染器[_字符串属性.字体ID].setString(*_字符串属性.字符串);
        window->draw(字符渲染器[_字符串属性.字体ID]);
        return 0;
    }
    字符串类::字符串类()
    {
    }
    字符串类::~字符串类()
    {
    }



    int 高性能顶点数组::添加顶点(std::vector<sf::Vertex> _顶点数据)
    {
        顶点数据.insert(顶点数据.end(), _顶点数据.begin(), _顶点数据.end());
        return 0;
    }

    int 高性能顶点数组::清空顶点()
    {
        顶点数据.clear();
        return 0;
    }

    int 高性能顶点数组::显示顶点数组()
    {
        if (window != nullptr)
        {
            if (纹理指针 != nullptr) {
                sf::RenderStates states;
                states.texture = 纹理指针;
                window->draw(顶点数据.data(), 顶点数据.size(), sf::Triangles, states);
            }
            else {
                window->draw(顶点数据.data(), 顶点数据.size(), sf::Triangles);
            }
        }
        return 0;
    }

    高性能顶点数组::高性能顶点数组()
    {
        顶点数据.reserve(0x4ffff);  // 在构造函数中预分配空间
    }

    高性能顶点数组::~高性能顶点数组()
    {
    }


    菜单类::菜单数据类::菜单数据类()
    {
    }
    菜单类::菜单数据类::~菜单数据类()
    {
    }
    int 菜单类::显示菜单()
    {
        return 0;
    }
    菜单类::菜单类()
    {
    }
    菜单类::~菜单类()
    {
    }

    int 菜单类::添加子菜单(菜单数据类 _子菜单)
    {
        子菜单列表.push_back(_子菜单);
        return 0;
    }

    int 菜单类::删除子菜单(菜单数据类* 父菜单, unsigned char 子菜单索引)
    {
        // 从父菜单的子菜单列表中移除指定索引的子菜单
        父菜单->子菜单列表.erase(父菜单->子菜单列表.begin() + 子菜单索引);
        return 0;
    }






}

