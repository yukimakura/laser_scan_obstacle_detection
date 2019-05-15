#include "obstacle_detection.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "obstacle_detection_node");
    float near_dist=1.0,body_cut_data=75.0;
    ros::NodeHandle n_arg("~");
    ros::NodeHandle n;
    n_arg.getParam("detect_distance", near_dist);
    n_arg.getParam("body_cut_area_deg_plusminus", body_cut_data);
    obstacle_detection obs(near_dist,body_cut_data);
    ros::Subscriber sub = n.subscribe("scan", 10, &obstacle_detection::scan_CB,&obs);
    

    ros::spin();

    return 0;
}