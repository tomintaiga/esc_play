#define BOOST_TEST_MODULE component_manager
#include <boost/test/included/unit_test.hpp>

#include <component_manager.h>

struct TestPosition
{
    int x;
    int y;
    int z;

    TestPosition(): x{}, y{}, z{} {}
};

BOOST_AUTO_TEST_CASE(component_manager_constructor)
{
    esc::Components::ComponentManager<TestPosition> manager;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(component_manager_add_entity)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    auto component = c_manager.add(e1);

    BOOST_TEST((*component).second->x == 0);
    BOOST_TEST((*component).second->y == 0);
    BOOST_TEST((*component).second->z == 0);
}

struct TestPositionArgs
{
    int x;
    int y;
    int z;
    TestPositionArgs() = delete;
    TestPositionArgs(int X, int Y, int Z): x{X}, y{Y}, z{Z} {}
};

BOOST_AUTO_TEST_CASE(component_manager_add_entity_with_args)
{
    esc::Components::ComponentManager<TestPositionArgs> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    auto component = c_manager.add(e1, 10, 20, 30);

    BOOST_TEST((*component).second->x == 10);
    BOOST_TEST((*component).second->y == 20);
    BOOST_TEST((*component).second->z == 30);
}

BOOST_AUTO_TEST_CASE(component_manager_has)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    auto component = c_manager.add(e1);

    BOOST_TEST(c_manager.has(e1));
    BOOST_TEST(!c_manager.has(e2));
}

BOOST_AUTO_TEST_CASE(component_manager_find_single_entity)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    c_manager.add(e1);

    auto find = c_manager.find(e1);

    BOOST_TEST(std::distance(find.first, find.second) == 1);
}

BOOST_AUTO_TEST_CASE(component_manager_cant_find_entity)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();
    c_manager.add(e1);

    auto find = c_manager.find(e2);
    BOOST_TEST(std::distance(find.first, find.second) == 0);
}

BOOST_AUTO_TEST_CASE(component_manager_can_find_many_components)
{
    esc::Components::ComponentManager<TestPosition> c_manager;
    esc::EntityManager e_manager;

    auto control_entity = e_manager.create();

    int good_count = 0;
    for(int i=0; i< 50; i++)   
    {
        auto cur = e_manager.create();
        for(int j=0; j<10; j++)
        {
            c_manager.add(cur);

            if(j%2 == 0)
            {
                c_manager.add(control_entity);
                good_count++;
            }
        }
    }

    BOOST_TEST(good_count == 250);

    //Now check for control entity
    BOOST_TEST(c_manager.has(control_entity));

    //Let's count control components
    auto find = c_manager.find(control_entity);

    BOOST_TEST(std::distance(find.first, find.second) == good_count);
}