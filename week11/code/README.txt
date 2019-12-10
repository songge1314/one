./10-1&  表示后台运行，不占用终端。
ps aux|grep 10-1 查看10-1的进程
//ps是显示当前状态处于running的进程，grep表示在这些里搜索，
而ps aux是显示所有进程和其状态.

ps -ef|grep 10-1 与上面差不多，只是风格不同。

kill -6 2654  kill -6 命令， 它可以让主动让进程abort/coredump

守护进程自启：
1. 在etc/rc.local在里面加入/home/songge/test/week11/code/6-8 > /dev/null & 
可能还要chmod +x ./rc.local

2.在/etc/rc.d/init.d/ 下写脚本文件，然后chmod +x ./autoruntest
再然后chkconfig --add autoruntest  添加服务
注意守护进程放在/usr/local/bin/ 下
pidfile在/var/run/autoruntest.pid
