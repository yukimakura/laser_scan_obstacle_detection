# laser_scan_obstacle_detection


## Description
/scanトピックを購読して、パラメータ(detect_distance)で指定した値の
範囲内に障害物が検出されたらメッセージを表示するパッケージです。   
前、右、左、斜め右前、斜め左前の5方向でメッセージを出力します。

## Demo

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