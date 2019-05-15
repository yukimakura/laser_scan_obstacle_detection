#include "obstacle_detection.h"
inline std::pair<float,float> obstacle_detection::after_before_num_fn_(int num,int max_point_num){
    std::pair<float,float> tmp;
    tmp.first = num-1 < 0 ? max_point_num : num-1;
    tmp.second = num+1 > max_point_num ? 0 : num+1;
    return tmp;
}

obstacle_detection::obstacle_detection(float near_dist,float body_cut_data){
    near_dist_ = near_dist;
    body_cut_data_ = body_cut_data;
    std::cout << "detect_distance: " << near_dist_ << "m" << std::endl;
    std::cout << "body_cut_area_deg: +-" << body_cut_data_ << "deg" << std::endl;
    obs_data_pub = n_.advertise<object_direction_msgs::Object_direction>("object_dir", 100);
}

void obstacle_detection::search_obj_dir_(float deg,OBJECT_DIR *data){
    float area = (360.0 - (body_cut_data_*2))/5;
    object_direction_msgs::Object_direction obsmsg;
    if(body_cut_data_<deg && deg <=body_cut_data_+area){
        data->r = 1;
    }else if(body_cut_data_ + area < deg && deg <= body_cut_data_ + (area*2)){
        data->fr = 1;
    }else if(body_cut_data_ + (area*2) < deg && deg <= body_cut_data_ + (area*3)){
        data->f = 1;
    }else if(body_cut_data_ + (area*3) < deg && deg <= body_cut_data_ + (area*4)){
        data->fl = 1;
    }else if(body_cut_data_ + (area*4) < deg && deg <= body_cut_data_ + (area*5)){
        data->l = 1;
    }
}

void obstacle_detection::print_obj_dir_(OBJECT_DIR obj){
    if(obj.f){
        std::cout << "前方に障害物" << std::endl;
    }
    if(obj.fl){
        std::cout << "左前に障害物" << std::endl;
    }
    if(obj.fr){
        std::cout << "右前に障害物" << std::endl;
    }
    if(obj.r){
        std::cout << "右に障害物" << std::endl;
    }
    if(obj.l){
        std::cout << "左に障害物" << std::endl;
    }
}
void obstacle_detection::scan_CB(const sensor_msgs::LaserScan msg)
{
    int points_num = msg.ranges.size();
    std::vector<std::pair<float,float> >  near_detec_pair;
    std::pair<float,float> tmp,cnt_before_after;
    float one_point_per_deg = 360.0/points_num;
    
    OBJECT_DIR obj_dir = {0,0,0,0,0};

    std::cout << "----------------------------------------------------"<<std::endl;
    for(int a = 1; a < points_num-1;a++){
        cnt_before_after = after_before_num_fn_(a,points_num);
        if(msg.ranges[a] != 0 && msg.ranges[a] < near_dist_){
            search_obj_dir_(a*one_point_per_deg,&obj_dir);
        }
    }
    print_obj_dir_(obj_dir);
    
    object_direction_msgs::Object_direction obs_msg;
    obs_msg.f = obj_dir.f;
    obs_msg.fr = obj_dir.fr;
    obs_msg.r = obj_dir.r;
    obs_msg.fl = obj_dir.fl;
    obs_msg.l = obj_dir.l;
    obs_data_pub.publish(obs_msg);
}
