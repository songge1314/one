1. gcc -shared -fPIC -o libdylib.so aoprand.c base.c
2. gcc a.c -o a ./libdylib.so
