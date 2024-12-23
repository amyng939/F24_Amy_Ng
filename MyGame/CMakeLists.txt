add_executable(MyGame Source.cpp MyGame.h MyGame.cpp Counter.h Counter.cpp)

include_directories(../Avo/include)

target_link_libraries(MyGame Avo)