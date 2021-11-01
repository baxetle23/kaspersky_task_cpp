#include "checker.h"
#include "timework.h"
#include <iostream>

using namespace std;

//i need check regist letter?
Checker::Checker(ExtensionContent&& data_) :
    extension_content_(move(data_)) {
    for (auto& pair : extension_content_) {
        statistics_[pair.first] = 0;
    }
    statistics_["errors"s] = 0;
    statistics_["files"s] = 0;
}

void Checker::CheckFile(const filesystem::path path) {
    auto checked_strings = CheckExtension(path.filename().string());
    if (checked_strings != nullopt) {
        ifstream file (path.string());
        if (!file) {
            statistics_.at("errors"s) += 1;
        } else {
            string buffer;
            while(getline(file, buffer)) {
                if (checked_strings.value()->second.count(buffer)) {
                    statistics_.at(checked_strings.value()->first) += 1;
                    break;
                }
            }
        }
    }
    statistics_.at("files"s) += 1;
}

optional<ExtensionContentIter> Checker::CheckExtension(string_view namefile) const {
    auto pos = namefile.rfind('.');
    if (pos != string::npos) {
        string check_extension{namefile.begin() + pos + 1, namefile.end()};
        transform(check_extension.begin(), check_extension.end(), check_extension.begin(), ::tolower);
        auto iter = extension_content_.find(check_extension);
        if (iter != extension_content_.end()) {
            return optional<unordered_map<string, unordered_set<string>>::const_iterator>{iter};
        }
    }
    return nullopt;
}

void Checker::PrintStat(ostream& out) const {
    out << std::endl;
    out << "====== Scan result ======"s << std::endl;
    out << "Processed files: "s << statistics_.at("files"s) << std::endl;
    out << "JS detects: "s << statistics_.at("js"s) << std::endl;
    out << "CMD detects: "s << statistics_.at("cmd"s) + statistics_.at("bat"s) << std::endl;
    out << "EXE detects: "s << statistics_.at("exe"s) + statistics_.at("dll"s) << std::endl;
    out << "Errors: "s << statistics_.at("errors"s) << std::endl;
    out << "Execution time: "s;
    time_work_.GetTime(out);
    out << std::endl;
    out << "========================="s << std::endl << std::endl;

}
