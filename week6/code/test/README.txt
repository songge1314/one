1.远程调用动态库
gcc dyremote.c -o dyremote ../dynamiclib/libdylib.so -I../dynamiclib

2.远程动态库显式调用
gcc -rdynamic -o dytest dytest.c -ldl -I../dynamiclib
