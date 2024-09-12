#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "db_connection/db_connection.h"


using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    ucout << "Received a GET request\n";
    json::value response_data;
    response_data[U("message")] = json::value::string(U("Hello, World!"));

    MYSQL *conn;
    if (connect_to_database(conn)){
        std::cout<<"Connected";
    }
    close_database_connection(conn);
    request.reply(status_codes::OK, response_data);
}

int main() {
    uri_builder uri(U("http://localhost:3001"));
    auto addr = uri.to_uri().to_string();
    http_listener listener(addr);

    listener.support(methods::GET, handle_get);

    try {
        listener
            .open()
            .then([&listener]() { ucout << "Starting to listen at: " << listener.uri().to_string() << std::endl; })
            .wait();

        std::string line;
        std::getline(std::cin, line);
    } catch (const std::exception &e) {
        std::cerr << "Something went wrong: " << e.what() << std::endl;
    }

    return 0;
}
