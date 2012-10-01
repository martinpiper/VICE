cd ..
del TTTTVICE.zip
rmdir /S /Q TTTTVICE
mkdir TTTTVICE
xcopy VICE\*.* TTTTVICE\VICE\ /S /E
cd TTTTVICE
cd VICE
call CleanProjectFullyWithAttrib.bat
