@echo off
for /R .\src %%f in (*.rep) do (
    repc -o merged %%f "rep_%%~nf_merged.h"
)
