#include <iostream>
#include <string>
using namespace std;
class Building;
// class Good_friend;
class Good_friend
{
public:
    Good_friend();
    
    ~Good_friend();
    Good_friend(const Good_friend &f1);
    void visit();
    Building *building = NULL; // Building 类型的指针并不会调用默认构造函数
};
class Building
{

    friend void good_friend(Building &building); // good_friend全局函数为Building的友元
    // friend class Good_friend;
    friend void Good_friend ::visit();

public:
    Building();
    string m_sittingRoom;

private:
    string m_bedRoom;

protected:
    string m_wareHouse;
};

void good_friend(Building &building)
{
    cout << "访问你的公有属性：" << building.m_sittingRoom << endl;
    cout << "访问你的保护属性：" << building.m_wareHouse << endl;
    cout << "访问你的私有属性：" << building.m_bedRoom << endl;
}
Building::Building()
{
    m_sittingRoom = "客厅";
    m_bedRoom = "卧室";
    m_wareHouse = "仓库";
    cout << "Build的默认构造" << endl;
}

Good_friend::Good_friend()
{
    building = new Building; // 需要为该指针分配内存
    cout << "Good_friend的默认构造" << endl;
}
Good_friend::Good_friend(const Good_friend &f)
{
    building = new Building;
    *building = *f.building;
    cout << "Good_friend的拷贝构造" << endl;
}
Good_friend::~Good_friend()
{
    if (building != NULL)
    {
        building = NULL;
    }
    delete building;
    cout << "Good_friend的析构函数" << endl;
}
void Good_friend::visit()
{
    cout << "访问私有属性：" << building->m_sittingRoom << endl;
}
void test01()
{
    Building b1;
    good_friend(b1);
}
void test02()
{
    Good_friend good_friend1;
    Good_friend good_friend2(good_friend1);

    good_friend1.visit();
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 1;
}