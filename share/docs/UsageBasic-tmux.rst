tmux基本使用方法
============

安装
------------
sudo apt install tmux 

新建会话
------------
1. tmux new -s <session_name>

删除会话
------------
1. tmux kill-session删除会话
2. tmux kill-session -t <session_name>删除指定会话

会话内新建窗口
------------
1. <C-b><c>新建

脱离会话
------------
1. <C-b><d>脱离

连接会话
------------
1. tmux a连接

切换窗口
------------
1. <C-b><w>切换
2. <C-b><NUM>在当前会话内切换，NUM可以是0-9

删除窗口
------------
1. <C-b>x删除当前窗口


列出会话
------------
1. tmux ls列出

注意事项
------------
1. tmux的命令可以只写前缀，但必须只匹配一个命令，例: tmux kill-s是不可以的，有两个匹配命令，而tmux kill-ses是可以的，仅匹配tmux kill-session

