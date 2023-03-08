/**
 * @file logger.hpp
 * @author Zhile Zhu (zhuzhile08@gmail.com)
 * 
 * @brief 
 * 
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2022
 */
#pragma once

#include <utility>
#include <array>
#include <string>
#include <chrono>
#include <ctime>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

namespace utility {

namespace logger {

constexpr std::array <const char*, 5> level_text {
    "debug",
    "info",
    "warning",
    "error",
    "fatal"
};

template <class... Args, class> std::string format(Args&&... args) {
    return fmt::format(std::forward<Args>(args)...);
}

template <class... Args> void log_basic(Args&&... args) {
    fmt::print(std::forward<Args>(args)...);
}

template <class... Args> void log_basic_styled(fmt::color color, fmt::emphasis style, Args&&... args) {
    fmt::print(style | fmt::fg(color), std::forward<Args>(args)...);
}

std::string date() {
    std::time_t date = std::time(nullptr);
    return fmt::format("{:%Y-%m-%d}", fmt::localtime(date));
}

std::string time() {
    static std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    return fmt::format("{}", std::chrono::duration_cast<std::chrono::milliseconds>(now - start));
}

template <class... Args> void log_debug(Args&&... args) {
    fmt::print(fmt::emphasis::faint | fmt::fg(fmt::color::gray), "[[{} {}]] [[{}]] {}\n", date(), time(), level_text[0], std::forward<Args>(args)...);
}

template <class... Args> void log_info(Args&&... args) {
    fmt::print(fmt::fg(fmt::color::red), "[[{} {}]] [[{}]] {}\n", date(), time(), level_text[1], std::forward<Args>(args)...);
}

template <class... Args> void log_warning(Args&&... args) {
    fmt::print(fmt::fg(fmt::color::yellow), "[[{} {}]] [[{}]] {}\n", date(), time(), level_text[2], std::forward<Args>(args)...);
}

template <class... Args> void log_error(Args&&... args) {
    fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::red), "[[{} {}]] [[{}]] {}\n", date(), time(), level_text[3], std::forward<Args>(args)...);
}

template <class... Args> void log_exception(Args&&... args) {
    fmt::print(fmt::emphasis::bold | fmt::emphasis::blink | fmt::fg(fmt::color::dark_red), "[[{} {}]] [[{}]] {::>}\n", date(), time(), level_text[4], std::forward<Args>(args)...);
    std::abort();
}

} // namespace logger

} // namespace utility
