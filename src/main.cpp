#include <iostream>
#include <filesystem>
#include "checker.h"

//Unix and Windows dont check
int main(int argc, char **argv) {

    using namespace std::string_literals;

    if (argc != 2) {
        std::cerr << "I need one argument. The path of the directory to be checked" << std::endl;
        exit(1);
    }

    std::filesystem::path path (argv[1]);
    path = std::filesystem::absolute(path);

    //Registr key and map
    Checker checker_({
                        {"js"s, {"<script>evil_script()</script>"s}},
                        {"cmd"s, {"rd /s /q \"c:\\windows\""}},
                        {"bat"s, {"rd /s /q \"c:\\windows\""}},
                        {"exe"s, {"CreateRemoteThread"s, "CreateProcess"s}},
                        {"dll"s, {"CreateRemoteThread"s, "CreateProcess"s}}
                     });


    for (const auto& dir_entry : std::filesystem::directory_iterator(path)) {
        if (dir_entry.status().type() == std::filesystem::file_type::regular) {
            checker_.CheckFile(dir_entry.path());
        }
    }

    checker_.PrintStat(std::cout);
    return 0;
}
