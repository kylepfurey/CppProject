@echo off
cd %USERPROFILE%
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
call .\bootstrap-vcpkg.bat
.\vcpkg integrate install
.\vcpkg install sdl2 sdl2-image sdl2-ttf sdl2-mixer sdl2-net
pause
