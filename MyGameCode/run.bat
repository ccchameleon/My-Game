
@echo off

g++ -o my_program main.cpp

if %errorlevel% equ 0 (
    echo Compilation successful.
    main.cpp < inputs.txt
) else (
    echo Compilation Failed.
)
