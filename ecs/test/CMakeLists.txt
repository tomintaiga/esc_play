add_executable(test_entity_manager test_entity_manager.cpp)
target_link_libraries(test_entity_manager ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(EntityManager test_entity_manager)

add_executable(test_position_component test_position_component.cpp)
target_link_libraries(test_position_component ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(PositionComponent test_position_component)

add_executable(test_component_manager test_component_manager.cpp)
target_link_libraries(test_component_manager ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(ComponentManager test_component_manager)

add_executable(test_gravity_system test_gravity_system.cpp)
target_link_libraries(test_gravity_system ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(GravitySystem test_gravity_system)