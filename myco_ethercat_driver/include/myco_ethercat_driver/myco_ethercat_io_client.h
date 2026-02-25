/*
Created on Tus Nov 17 15:36 2020

@author: Burb

 Software License Agreement (BSD License)

 Copyright (c) 2020, Han's Robot Co., Ltd.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.
  * Neither the name of the copyright holders nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/
// author: Burb

#ifndef MYCO_ETHERCAT_IO_CLIENT_H
#define MYCO_ETHERCAT_IO_CLIENT_H

#include <ros/ros.h>
#include <vector>
#include <myco_ethercat_driver/myco_ethercat_manager.h>
#include <myco_robot_msgs/mycoIODRead.h>
#include <myco_robot_msgs/mycoIODWrite.h>
#include <std_srvs/SetBool.h>

#include <pthread.h>
#include <time.h>

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

namespace myco_io_txpdo {

const int DIGITAL_INPUT=0;
const int ANALOG_INPUT_CHANNEL1=1;
const int ANALOG_INPUT_CHANNEL2=2;
const int SMART_CAMERA_X=3;
const int SMART_CAMERA_Y=4;

}

namespace myco_io_rxpdo {

const int DIGITAL_OUTPUT=0;

}

namespace  myco_ethercat_driver {

class MycoEtherCATIOClient{

private:
    EtherCatManager* manager_;
    ros::NodeHandle n_;
    ros::NodeHandle io_nh_;
    std::vector<MycoPDOunit> pdo_input; // txpdo
    std::vector<MycoPDOunit> pdo_output; //rxpdo
    int slave_no_;

    ros::ServiceServer read_sdo_; //20201116
    ros::ServiceServer read_do_; //20201130
    ros::ServiceServer write_sdo_; //20201117
    ros::ServiceServer get_txsdo_server_;//20201120
    ros::ServiceServer get_rxsdo_server_;//20201120

public:
    MycoEtherCATIOClient(EtherCatManager* manager, int slave_no, const ros::NodeHandle& nh, std::string io_port_name);
    ~MycoEtherCATIOClient();
    int32_t readSDO_unit(int n); // 20201117
    int32_t readDO_unit(int n); // 20201130
    void writeOutput_unit(int n, int32_t val);
    int32_t writeSDO_unit(int n); // 20201117

    int16_t readInput_unit(int n);
    int32_t readOutput_unit(int n);
    // bool writeOutput_unit(int n, int32_t val);

    std::string getTxSDO();
    std::string getRxSDO();

    bool readSDO_cb(myco_robot_msgs::mycoIODRead::Request &req, myco_robot_msgs::mycoIODRead::Response &resp); // 20201117
    bool readDO_cb(myco_robot_msgs::mycoIODRead::Request &req, myco_robot_msgs::mycoIODRead::Response &resp); // 20201130
    bool writeSDO_cb(myco_robot_msgs::mycoIODWrite::Request &req, myco_robot_msgs::mycoIODWrite::Response &resp); // 20201117
    bool getRxSDO_cb(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &resp);
    bool getTxSDO_cb(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &resp);
};

}

#endif
