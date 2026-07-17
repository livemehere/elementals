#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Camera::update() {
    viewMatrix_ = glm::mat4(1.0f);

    // T
    viewMatrix_ = glm::translate(viewMatrix_, transform.position);

    // R
    glm::quat quaternion = glm::quat(glm::radians(transform.rotation));
    glm::mat4 quaternionMatrix = glm::mat4_cast(quaternion);
    viewMatrix_ *= quaternionMatrix;

    // inverse
    viewMatrix_ = glm::inverse(viewMatrix_);
}

glm::mat4 Camera::getViewMatrix() const {
    return viewMatrix_;
}

glm::mat4 Camera::getProjectionMatrix(const WindowSize &size) {
    if (std::holds_alternative<PerspectiveProjection>(projection)) {
        const auto& perspective = std::get<PerspectiveProjection>(projection);
        projectionMatrix_ = glm::perspective(glm::radians(perspective.fov),static_cast<float>(size.fb_w)/ static_cast<float>(size.fb_h), perspective.near, perspective.far);
    } else {
        const auto& orthographic = std::get<OrthoGraphicProjection>(projection);
        const float ratio = static_cast<float>(size.w) / static_cast<float>(size.h);
        const float halfHeight = orthographic.height / 2.0f;
        const float halfWidth = ratio * halfHeight;
        projectionMatrix_ = glm::ortho(-halfWidth,halfWidth,-halfHeight,halfHeight, orthographic.near, orthographic.far);
    }
    return projectionMatrix_;
}
