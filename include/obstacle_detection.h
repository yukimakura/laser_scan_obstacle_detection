#ifndef   OBSTACLE_DETECTION_H
#define   OBSTACLE_DETECTION_H
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <iostream>
#include <utility>
#include <vector>

class obstacle_detection{
    typedef struct{
        int l,fl,f,fr,r;
    }OBJECT_DIR;
    private:
        std::pair<float,float> after_before_num_fn_(int num,int max_point_num);
        void search_obj_dir_(float deg,OBJECT_DIR *data);
        void print_obj_dir_(OBJECT_DIR obj);

        float near_dist_;
        float body_cut_data_;
    public:
        obstacle_detection(float near_dist,float body_cut_data);
        void scan_CB(const sensor_msgs::LaserScan msg);

};

#endif // OBSTACLE_DETECTION_H