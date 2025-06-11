#include "http_service.h"
#include "common/json/json.hpp"
#include "common/public_fun.h"
#include "apps/robot_dog_main.h"
#include "common/struct/CommonStruct.h"

#define OBU_TOPIC "/Speech/ObuCmdMsg"

using Json = nlohmann::json;
namespace robot_dog {
    namespace services {

        HttpServer::HttpServer()
        {
            Init();
        }

        HttpServer::~HttpServer()
        {

        }

        void HttpServer::Run(const std::string ip, const int port)
        {
            if(http_server_ptr_)
            {
                AINFO << "Start listen: " << ip << ":" << port;
                std::thread([this, ip, port]() {
                    http_server_ptr_->listen(ip, port);
                }).detach();
            }
        }

        void HttpServer::Init()
        {
            http_server_ptr_ = std::make_unique<httplib::Server>();
            //obu_pub_ = nh_.advertise<ros_interface::ObuCmdMsg>(OBU_TOPIC, 10);

            // http_server_ptr_->Get("/hi", [](const httplib::Request& req, httplib::Response& res) {
            //     res.set_content("Hello World!", "text/plain");
            // });

            http_server_ptr_->Post("/api/message", [this](const httplib::Request& req, httplib::Response& res){
                handleObuPostRequest(req, res);
            });
        }

        void HttpServer::handleObuPostRequest(const httplib::Request& req, httplib::Response& res)
        {
            if (AfxGetApp() == nullptr) {
                Json rsp;
                rsp["status"] = "error";
                rsp["message"] = "ros error";
                res.status = 500;
                res.set_content(rsp.dump(), "application/json");
                return;
            }

            try {
                if (req.method != "POST") {
                    Json rsp;
                    rsp["status"] = "error";
                    rsp["message"] = "Only POST method is allowed";
                    res.status = 405; // Method Not Allowed
                    res.set_content(rsp.dump(), "application/json");
                    return;
                }

                std::string body = req.body;
                std::cout << "Received POST request with body: " << body << std::endl;

                if (body.empty()) {
                    Json rsp;
                    rsp["status"] = "error";
                    rsp["message"] = "Empty request body";
                    res.status = 400; // Bad Request
                    res.set_content(rsp.dump(), "application/json");
                    return;
                }

                Json data = Json::parse(body);

                if (!data.contains("code") || !data.contains("val")) {
                    Json rsp;
                    rsp["status"] = "error";
                    rsp["message"] = "Missing required fields: code or val";
                    res.status = 400; // Bad Request
                    res.set_content(rsp.dump(), "application/json");
                    return;
                }

                robot_dog::ObuCmdMsg obu_msg;
                obu_msg.name = "wechat";
                robot_dog::ObuCmd obu_cmd;
                obu_cmd.code = data["code"].get<int>();
                obu_cmd.val = data["val"].get<int>();
                obu_msg.obu_cmd_list.push_back(obu_cmd);

                AfxGetApp()->PublishVideoOnInt(obu_msg);
                std::cout << "publish data: " << data.dump() << std::endl;

                Json rsp;
                rsp["status"] = "success";
                rsp["message"] = "Data sent to ROS";
                res.status = 200;
                res.set_content(rsp.dump(), "application/json");

            } catch (const nlohmann::json::parse_error& ex) {
                Json rsp;
                rsp["status"] = "error";
                rsp["message"] = std::string("JSON parse error: ") + ex.what();
                res.status = 400;
                res.set_content(rsp.dump(), "application/json");
                std::cout << "JSON parse error: " << ex.what() << std::endl;
            } catch (const std::exception& ex) {
                Json rsp;
                rsp["status"] = "error";
                rsp["message"] = ex.what();
                res.status = 500;
                res.set_content(rsp.dump(), "application/json");
                std::cout << "error: " << ex.what() << std::endl;
            }
        }

    } // namespace services
}  // namespace robot_dog
