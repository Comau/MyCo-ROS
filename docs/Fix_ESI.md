修复ESI (EtherCAT Slave Infomation)
====

如果启动myco_ros_control.launch（或 myco_ros_control_v2.launch）时遇到类似以下的报错，可能有下面两个原因。
```
ERROR: slave_no(1) : channel(352) is larger than Input bits (256)
```
## 原因1
你可能用了错的launch文件（详见： [README.md](../README.md)）。如果不知道所用的myco的从站版本的话，只要把两个launch文件都试一下即可。
```sh
$ sudo chrt 10 bash
$ roslaunch myco_robot_bringup myco_ros_control.launch
```
或
```sh
$ sudo chrt 10 bash
$ roslaunch myco_robot_bringup myco_ros_control_v2.launch
```

## 原因2
如果确定不是第一个原因，可以考虑是机械臂上的ESI固件错误。

### 修复ESI固件的方法

将myco通过网线连接到电脑。先通过`ifconfig`指令来确定与myco连接的网卡名称。本软件包默认的名称是eth0 。假如当前名称不是eth0的话，请在下面的步骤中对myco_ethercat_driver/config/write_esi.yaml的相应部分进行修改。
```
eth_name: eth0
```
myco上共有4个EtherCAT从站，如果同一网卡没有连接其他EtherCAT设备的话，4个从站的编号如下图所示：
![myco_robot](images/myco_ethercat_slaves.png)

如果有其他EtherCAT设备的话，请根据实际从站的编号对myco_ethercat_driver/config/write_esi.yaml的相应部分进行修改。
```
slave_no: [1, 2, 3]
```
以及
```
slave_no: [4]
```

#### 使用Version 1版本EtherCAT从站的myco
* 写入模组的ESI  
    将myco_ethercat_driver/config/write_esi.yaml文件中的参数设置如下：
    ```
    eth_name: eth0
    slave_no: [1, 2, 3]
    esi_file: myco_module.esi
    ```

    之后运行以下命令修复ESI
    ```sh
    $ sudo chrt 10 bash
    $ roslaunch myco_ethercat_driver myco_esi_write.launch
    ```
* 写入IO口的ESI  
    将myco_ethercat_driver/config/write_esi.yaml文件中的参数设置如下：
    ```
    eth_name: eth0
    slave_no: [4]
    esi_file: myco_io_port.esi
    ```

    之后运行以下命令修复ESI
    ```sh
    $ sudo chrt 10 bash
    $ roslaunch myco_ethercat_driver myco_esi_write.launch
    ```

    最后重启机械臂即可完成修复。

    为防误操作，修复后在myco_ethercat_driver/script/路径下会生成各个从站原ESI的备份。

#### 使用Version 2版本EtherCAT从站的myco
* 写入模组的ESI  
    将myco_ethercat_driver/config/write_esi.yaml文件中的参数设置如下：
    ```
    eth_name: eth0
    slave_no: [1, 2, 3]
    esi_file: myco_module_v2.esi
    ```

    之后运行以下命令修复ESI
    ```sh
    $ sudo chrt 10 bash
    $ roslaunch myco_ethercat_driver myco_esi_write.launch
    ```
* 写入IO口的ESI  
    将myco_ethercat_driver/config/write_esi.yaml文件中的参数设置如下：
    ```
    eth_name: eth0
    slave_no: [4]
    esi_file: myco_io_port_v2.esi
    ```

    之后运行以下命令修复ESI
    ```sh
    $ sudo chrt 10 bash
    $ roslaunch myco_ethercat_driver myco_esi_write.launch
    ```

    最后重启机械臂即可完成修复。

    为防误操作，修复后在myco_ethercat_driver/script/路径下会生成各个从站原ESI的备份。