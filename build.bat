@echo off
pushd

cd .\game\
call .\build.bat
cd ..
move .\game\program.exe .

cd .\exploit\injector\
call .\build.bat
cd ..
move .\injector\injector.exe ..

cd .\godmode\
call .\build.bat
cd ..\..
move .\exploit\godmode\godmode.dll

popd
