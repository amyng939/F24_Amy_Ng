add_executable(MyGame MyGame.cpp Counter.h Counter.cpp)

include_directories(../Avo/include)

target_link_libraries(MyGame Avo)