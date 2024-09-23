add_executable(MyGame MyGame.cpp)

include_directories(../Avo/include)

target_link_libraries(MyGame Avo)