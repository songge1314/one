gcc编译实验
1. gcc -c aoprand.c base.c
2. ar -rc libtest.a aoprand.c base.c
3. gcc localtest.c -o localtest -L. -ltest
