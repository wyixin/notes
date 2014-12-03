# [i3 improved tiling wm](http://i3wm.org/docs/)

## 基本用法
i3 默认修饰符是 Alt, 配置文件中可以选择使用 Alt(Mod1) 或者 Winkey(Mod4) 作为修饰符。
### 打开终端
    $mod + Enter
### 窗口

* 在 i3 中，窗口布局分为：
  - 默认(defualt): 每个窗口分配一定空间
  - 叠加(stacking): 只显示焦点窗口，其他窗口以列表形式在顶部平铺
  - 标签式(tabbed): 类似叠加，窗口在顶部垂直单号显示
  ![](img/i3wm_1.png "窗口示意图")
  $mod + e 默认， $mod + s 叠加, $mod + w 标签式, $mod + f 全屏显示

* 浮动与平铺
  i3支持将窗口切换为浮动模式，使用$mod+Shift+space进行切换

* 窗口分割方向
  新建窗口时切割父窗口的方向，使用 $mod + v （h） 或 $mod + Shift + V (v)

* 窗口大小
  按下 $mod + r，然后使用 hjkl 或方向键进行调整,使用 Shift + hjkl 或方向键进行反向调整，调整结束按下回车键离开调整模式

* 窗口边框
  - 无边框：$mod+u
  - 普通模式：$mod+t
  - 单像素边框：$mod+y

### 启动应用程序
  $mod + d 打开 dmenu, 输入应用名称
  $mod + Shift + Q 关闭窗口
  
### 重启 & 退出
    Mod Shift r        重启i3
    Mod Shift e        退出i3

参考：
[Linux 桌面平铺管理器 - i3wm](http://www.jianshu.com/p/JBGSWF)
[deepin i3](http://wiki.linuxdeepin.com/index.php?title=I3)