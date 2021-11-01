#ifndef CHECKER_H
#define CHECKER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string_view>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <optional>
#include <iostream>
#include "timework.h"

using ExtensionContent = std::unordered_map<std::string, std::unordered_set<std::string>>;
using ExtensionContentIter = std::unordered_map<std::string, std::unordered_set<std::string>>::const_iterator;
class Checker {
private:
    ExtensionContent extension_content_;
    std::unordered_map<std::string, size_t> statistics_;
    Timework time_work_;

    std::optional<ExtensionContentIter> CheckExtension(std::string_view) const;
public:
    Checker() = delete;
    explicit Checker(ExtensionContent&&);
    void CheckFile(const std::filesystem::path);
    void PrintStat(std::ostream&) const;
    ~Checker() = default;
};

#endif // CHECKER_H
