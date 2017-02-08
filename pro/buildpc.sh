 g++  ../src/QJCore/*.cpp \
    ../src/QJCtrl/*.cpp \
    ../src/QJFrame/*.cpp \
    ../src/QJAPP/*.cpp \
-o ../out/linux/QIJIA  -std=c++0x  -pthread \
-lncurses -I/opt/ncurses/include/ncurses -I/opt/ncurses/include \
-I ../src  -I ../src/QJCore/ -I../src/QJCtrl/ -I../src/QJFrame/ -I../src/QJAPP/ 
