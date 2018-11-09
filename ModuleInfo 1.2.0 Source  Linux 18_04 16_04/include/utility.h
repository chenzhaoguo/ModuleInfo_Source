#ifndef MYNTEYE_BASE_UTILITY_H_
#define MYNTEYE_BASE_UTILITY_H_
#pragma once

#include <string>

#include <opencv2/core/core.hpp>

#include "mynteye.h"

namespace mynteye {

MYNTEYE_API std::string Exec(const char *cmd);

/**
 * Finds the suggested device name.
 * @param found whether our camera is found or not.
 * @return the found device name, or default one.
 * @note Only find our camera on Linux. On other platforms, return default name and <code>found</code> is false.
 * The default name is <code>MYNTEYE</code> On Windows, <code>0</code> otherwise.
 */
MYNTEYE_API std::string FindDeviceName(bool *found);

MYNTEYE_API cv::Rect DrawInfo(const cv::Mat& im, const std::string &text,
    const Gravity &gravity = Gravity::TOP_LEFT, const int &margin = 5,
    const int &offset_x = 0, const int &offset_y = 0);

}  // namespace mynteye

#endif  // MYNTEYE_BASE_UTILITY_H_
