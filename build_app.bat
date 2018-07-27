call build_repc.bat
qmake echo_app.pro
mingw32-make debug
.\debug\echo_app.exe
