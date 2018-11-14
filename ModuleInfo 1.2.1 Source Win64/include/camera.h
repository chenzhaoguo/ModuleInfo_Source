#ifndef MYNTEYE_API_CAMERA_H_
#define MYNTEYE_API_CAMERA_H_
#pragma once

#include <memory>
#include <vector>

#include <opencv2/core/core.hpp>

#include "callback.h"
#include "camera_information.h"
#include "imudata.h"
#include "init_parameters.h"
#include "mynteye.h"
#include "resolution.h"

namespace mynteye {

class CameraPrivate;

/**
 * The main class to use the MYNT EYE camera.
 */
class MYNTEYE_API Camera {
public:
    /** Constructor. */
    Camera();
    /** Destructor. */
    ~Camera();

    /**
     * Sets mode.
     * default: ::MODE_AUTO_DETECT
     * @param mode the compute mode.
     * @see ::Mode
     */
    void SetMode(const Mode &mode);

    /**
     * Sets scale factor to the grabbed images.
     * @param scale the scale factor.
     */
    void SetScale(float scale);

    /**
     * Opens the MYNE EYE camera.
     * @return ::SUCCESS if ok, otherwise error.
     */
    ErrorCode Open(const InitParameters &params);

    /**
     * Tests if the camera is opened.
     * @return `true` if opened.
     */
    bool IsOpened();

    /**
     * Sets framerate & IMU frequency.
     * @return ::SUCCESS if ok, otherwise failed.
     * @note Only supported on Linux now.
     */
    ErrorCode SetRate(const Rate &rate);

    /**
     * Gets hard ware version.
     * @return ::hard ware version.
     * @note Only supported on Linux now.
     */
    std::string GetHardWareVersion();

    /**
     * Gets control property value.
     * @param prop the control property, see ::ControlProperty.
     * @return the control property value, `-1` means failed.
     * @note Only supported on Linux now.
     */
    std::int32_t GetControlProperty(const ControlProperty &prop);

    /**
     * Sets control property value.
     * @param prop the control property, see ::ControlProperty.
     * @param value the control property value.
     * @return ::SUCCESS if ok, otherwise failed.
     * @note Only supported on Linux now.
     */
    ErrorCode SetControlProperty(const ControlProperty &prop, std::int32_t value);

    /**
     * Requests erase chip.
     * @return ::SUCCESS if ok, otherwise failed.
     * @note Only supported on Linux now.
     */
    ErrorCode RequestEraseChip();

    /**
     * Requests zero drift calibration.
     * @return ::SUCCESS if ok, otherwise failed.
     * @note Only supported on Linux now.
     */
    ErrorCode RequestZeroDriftCalibration();

    /**
     * Activates async grap feature.
     * @param keep_imu_frequency whether keep imu frequency or not.
     */
    void ActivateAsyncGrabFeature(bool keep_imu_frequency = false);

    /**
     * Deactivates async grap feature.
     */
    void DeactivateAsyncGrabFeature();

    /**
     * Tests if the async grap feature is activated.
     * @return `true` if activated.
     */
    bool IsAsyncGrabFeatureActivated();

    /**
     * Activates depth map feature.
     */
    void ActivateDepthMapFeature();

    /**
     * Deactivates depth map feature.
     */
    void DeactivateDepthMapFeature();

    /**
     * Tests if the depth map feature is activated.
     * @return `true` if activated.
     */
    bool IsDepthMapFeatureActivated();

    /**
     * Activates point cloud feature.
     */
    void ActivatePointCloudFeature();

    /**
     * Deactivates point cloud feature.
     */
    void DeactivatePointCloudFeature();

    /**
     * Tests if the point cloud feature is activated.
     * @return `true` if activated.
     */
    bool IsPointCloudFeatureActivated();

    /**
     * Sets grab error callback.
     */
    void SetGrabErrorCallback(GrabErrorCallback callback);

    /**
     * Sets process grab callbacks.
     */
    void SetGrabProcessCallbacks(
        GrabPreProcessCallback pre_callback,
        GrabPostProcessCallback post_callback);

    /**
     * Sets process rectification callbacks.
     */
    void SetRectifyProcessCallbacks(
        RectifyPreProcessCallback pre_callback,
        RectifyPostProcessCallback post_callback);

    /**
     * Sets process depth map callbacks.
     */
    void SetDepthMapProcessCallbacks(
        DepthMapPreProcessCallback pre_callback,
        DepthMapPostProcessCallback post_callback);

    /**
     * Sets process point cloud callbacks.
     */
    void SetPointCloudProcessCallbacks(
        PointCloudPreProcessCallback pre_callback,
        PointCloudPostProcessCallback post_callback);

    /**
     * Grabs the new image, and process it.
     * @note The grabbing function is typically called in the main loop.
     * @note If ActivateAsyncGrabFeature(), you should SetGrabErrorCallback() to listen the grab error.
     *       And this method only return ::ERROR_CAMERA_GRAB_FAILED if there is not a new frame (it will block a moment to wait for grabbing).
     * @return ::SUCCESS if ok, otherwise error.
     */
    ErrorCode Grab();

    /**
     * Retrieves a image of wanted type.
     * @param mat the Mat to store the image.
     * @param view defines the image type wanted, see ::View.
     * @return ::SUCCESS if ok, otherwise error.
     * @note The retrieve function should be called after the function Camera::Grab.
     */
    ErrorCode RetrieveImage(cv::Mat &mat, const View &view = View::VIEW_LEFT);

    /**
     * Retrieves the IMU datas.
     * @param imudatas the given IMU datas.
     * @return ::SUCCESS if ok, otherwise error.
     */
    ErrorCode RetrieveIMUData(std::vector<IMUData> &imudatas);

    /**
     * Retrieves the IMU datas.
     * @param imudatas the given IMU datas.
     * @param timestamp the hardware timestamp which elapsed after camera working, in unit 0.1ms.
     * @return ::SUCCESS if ok, otherwise error.
     * @deprecated
     */
    ErrorCode RetrieveIMUData(std::vector<IMUData> &imudatas, std::uint32_t &timestamp);

    /**
     * Returns the lastest hardware timestamp which indicates when retrieved.
     * the raw images and imu datas. It's the elapsed time after camera working, in unit 0.1ms.
     * @return the hardware timestamp.
     */
    std::uint32_t GetTimestamp();

    /**
     * Returns the time of exposure.
     * @note The value must be in [0,240]. It represents different times at different frame rates.
     * The maximum value "240" at the frame rate 10/25/50 fps represents 14.99/18.03/17.81 ms.
     * @return the time of exposure.
     */
    std::uint16_t GetExposureTime();

    /**
     * Returns the current image size.
     * @return the current image size.
     */
    Resolution GetResolution();

    /**
     * Returns the camera informations.
     * @return the camera informations.
     */
    CameraInformation GetCameraInformation();

    /**
     * Returns the calibration parameters.
     * @return the calibration parameters.
     */
    CalibrationParameters GetCalibrationParameters();

    /**
     * Returns the dropped count in some process.
     * @return the dropped count in some process.
     */
    std::uint64_t GetDroppedCount(const Process &proc);

    /**
     * Closes the camera and free the memory.
     */
    void Close();

    /**
     * Activates plugin.
     * @param libpath the plugin library path.
     */
    void ActivatePlugin(const std::string &libpath);

    /**
     * Deactivates plugin.
     */
    void DeactivatePlugin();

    /**
     * Tests if plugin is activated.
     * @return `true` if activated.
     */
    bool IsPluginActivated();

    /**
     * Tests if firmware is latest.
     * @return `true` if latest.
     */
    bool IsFirmwareLatest();

    /**
     * Returns the SDK root directory.
     * @return the SDK root directory.
     */
    static std::string GetSDKRoot();

    /**
     * Returns the SDK version.
     * @return the SDK version.
     */
    static std::string GetSDKVersion();

private:
    std::unique_ptr<CameraPrivate> d_ptr;

    friend class CameraPrivate;
};

}  // namespace mynteye

#endif  // MYNTEYE_API_CAMERA_H_
