#ifndef __HTTP_SERVICE_H__
#define __HTTP_SERVICE_H__

#include <memory>

#include "common/httplib/httplib.h"

namespace robot_dog {
    namespace services {
        class HttpServer {
        public:
            HttpServer();
            ~HttpServer();

            void Run(const std::string ip = "localhost", const int port = 3000);
        private:
            void Init();
            void handleObuPostRequest(const httplib::Request& req, httplib::Response& res);
        private:
            std::unique_ptr<httplib::Server> http_server_ptr_;
        };

    } // namespace services
}// namespace robot_dog


#endif
