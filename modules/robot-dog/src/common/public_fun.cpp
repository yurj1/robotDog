/*
                  _ooOoo_
                 o8888888o
                 88" . "88
                 (| -_- |)
                 O\  =  /O
              ____/`---'\____
            .'  \\|     |//  `.
            /  \\|||  :  |||//  \
          /  _||||| -:- |||||-  \
          |   | \\\  -  /// |   |
          | \_|  ''\---/''  |   |
          \  .-\__  `-`  ___/-. /
        ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
    | | :  `- \`.;`\ _ /`;.`/ - ` : | |
    \  \ `-.   \_ __\ /__ _/   .-` /  /
  ======`-.____`-.___\_____/___.-`____.-'======
				   `      =---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		          佛祖保佑       永无BUG

 */

#include "public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function;

extern athena::function::RobotDogMain *theApp;

athena::function::RobotDogMain*& AfxGetApp()
{
  return theApp;
}
