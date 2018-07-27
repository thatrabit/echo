call build_repc.bat
qmake echo_test.pro
mingw32-make
.\release\echo_test.exe -silent
