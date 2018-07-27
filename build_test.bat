call build_repc.bat
qmake echo_test.pro
mingw32-make debug
.\debug\echo_test.exe -silent
