#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    while(1){
            auto now = std::chrono::system_clock::now(); // lấy thời gian hiện tại
            std::time_t now_time = std::chrono::system_clock::to_time_t(now); // chuyển về time_t
            std::cout << "get real time: " << std::ctime(&now_time) <<std::endl; // định dạng chuỗi
    }


    return 0;
}
