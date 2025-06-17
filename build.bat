@echo off
g++ -std=c++20 main.cpp -o Data_Structure
if %ERRORLEVEL% EQU 0 (
    echo Build successful!
) else (
    echo Build failed!
) 