#define BOOST_TEST_MODULE position_component
#include <boost/test/included/unit_test.hpp>

#include <position_component.h>

BOOST_AUTO_TEST_CASE(position_component_constructor)
{
    esc::Components::Position position;

    BOOST_TEST(position.x == 0);
    BOOST_TEST(position.y == 0);
    BOOST_TEST(position.z == 0);
}

BOOST_AUTO_TEST_CASE(position_component_manager_costructor)
{
    esc::Components::PositionManager manager;

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(position_manager_add_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();

    p_manager.add(e1);

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(position_manager_check_for_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    p_manager.add(e1);

    BOOST_TEST(p_manager.has(e1));
    BOOST_TEST(!p_manager.has(e2));
}

BOOST_AUTO_TEST_CASE(position_manager_find_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    p_manager.add(e1);

    auto find = p_manager.find(e1);

    int count = 0;
    for(find.first; find.first != find.second; find.first++)
        count++;

    BOOST_TEST(count == 1);
}

BOOST_AUTO_TEST_CASE(position_manager_cant_find_entity)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto e1 = e_manager.create();
    auto e2 = e_manager.create();

    p_manager.add(e1);

    auto find = p_manager.find(e2);

    BOOST_TEST(std::distance(find.first, find.second) == 0);
}

BOOST_AUTO_TEST_CASE(position_manager_find_many)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto control_entity = e_manager.create();

    int good_count = 0;
    for(int i=0; i< 50; i++)   
    {
        auto cur = e_manager.create();
        for(int j=0; j<10; j++)
        {
            p_manager.add(cur);

            if(j%2 == 0)
            {
                p_manager.add(control_entity);
                good_count++;
            }
        }
    }

    BOOST_TEST(good_count == 250);

    //Now check for control entity
    BOOST_TEST(p_manager.has(control_entity));

    //Let's count control components
    auto find = p_manager.find(control_entity);

    BOOST_TEST(std::distance(find.first, find.second) == good_count);
}

BOOST_AUTO_TEST_CASE(position_can_change)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto entity = e_manager.create();
    p_manager.add(entity);

    auto find = p_manager.find(entity);

    (*find.first).second->x = 15;
    (*find.first).second->y = 27;
    (*find.first).second->z = -4;

    auto find2 = p_manager.find(entity);

    BOOST_TEST((*find2.first).second->x == 15);
    BOOST_TEST((*find2.first).second->y == 27);
    BOOST_TEST((*find2.first).second->z == -4);
}

BOOST_AUTO_TEST_CASE(add_position_return_value)
{
    esc::Components::PositionManager p_manager;
    esc::EntityManager e_manager;

    auto entity = e_manager.create();
    auto position = p_manager.add(entity);

    (*position).second->x = 13;
    (*position).second->y = 44;
    (*position).second->z = 8;

    auto find2 = p_manager.find(entity);

    BOOST_TEST((*find2.first).second->x == 13);
    BOOST_TEST((*find2.first).second->y == 44);
    BOOST_TEST((*find2.first).second->z == 8);
}