./10-1&  表示后台运行，不占用终端。
ps aux|grep 10-1 查看10-1的进程
//ps是显示当前状态处于running的进程，grep表示在这些里搜索，
而ps aux是显示所有进程和其状态.

ps -ef|grep 10-1 与上面差不多，只是风格不同。

kill -6 2654  kill -6 命令， 它可以让主动让进程abort/coredump
