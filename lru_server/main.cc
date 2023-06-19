#include <drogon/drogon.h>
#include <iostream>

int main() {
    //Set HTTP listener address and port
    std::cout << "server starting ..." << std::endl;
    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
