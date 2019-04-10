add_executable(test_entity_manager test_entity_manager.cpp)
target_link_libraries(test_entity_manager ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(EntityManager test_entity_manager)

add_executable(test_component_manager test_component_manager.cpp)
target_link_libraries(test_component_manager ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(ComponentManager test_component_manager)