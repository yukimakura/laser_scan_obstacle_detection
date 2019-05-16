# laser_scan_obstacle_detection
[![Build Status](https://travis-ci.org/yukimakura/laser_scan_obstacle_detection.svg?branch=master)](https://travis-ci.org/yukimakura/laser_scan_obstacle_detection)

## Description
/scanトピックを購読して、パラメータ(detect_distance)で指定した値の
範囲内に障害物が検出されたらメッセージを表示するパッケージです。   
前、右、左、斜め右前、斜め左前の5方向でメッセージを出力します。

## Demo
[![https://i.ytimg.com/vi/uU4q2TWX9uM/hqdefault.jpg?sqp=-oaymwEjCPYBEIoBSFryq4qpAxUIARUAAAAAGAElAADIQj0AgKJDeAE=&amp;rs=AOn4CLAUEL6UA1Dj27RxkLq_uxTGmniuuQ](https://img.youtube.com/vi/uU4q2TWX9uM/0.jpg)](https://www.youtube.com/watch?v=uU4q2TWX9uM)

## Requirement
ROS(Kinetic KAME)   
もしくは互換性があるとされる物。

## Install
```
$ mkdir catkin_ws/src -p
$ cd catkin_ws/src
$ catkin_init_workspace
$ git clone https://github.com/yukimakura/laser_scan_obstacle_detection.git
$ cd ../
$ catkin_make
$ source ~/catkin_ws/devel/setup.bash
```

## Licence
MIT

## Author

[yukimakura](https://twitter.com/yukimakura86)
