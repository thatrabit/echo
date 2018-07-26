call build_lib.bat
qmake "CONFIG+=gui" "LIBS+=release/echo.dll"
mingw32-make
