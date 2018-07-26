call build_lib.bat
qmake "CONFIG+=test" "LIBS+=release/echo.dll"
mingw32-make
.\release\echo_test.exe -silent
