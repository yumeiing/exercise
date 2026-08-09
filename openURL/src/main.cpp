#include <raylib.h>
#include <iostream>
#include <string>

/*
 * 没法了，水一下贡献
 */

int main(int argc,char* argv[])
{
    std::string url = "https://baidu.com/baidu?ie=utf-8&wd=";
    if(argc != 1) url += argv[1];
    else
    {
        std::string quastion;
        std::cout << "请输入问题: ";
        std::cin >> quastion;
        url += quastion;
    }

    OpenURL(url.c_str());

    return 0;
}
