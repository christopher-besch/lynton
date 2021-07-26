#include "layer.h"

#include "pch.h"

namespace Lynton {

Layer::Layer(const std::string& name, vec3 camera_origin, scalar camera_width, scalar camera_height)
    : m_name(name), m_camera(new Camera(camera_origin, camera_width, camera_height))
{
    log_lynton_general("Creating Layer '{}'", m_name);
}

Layer::~Layer()
{
    log_lynton_general("Deleting Layer '{}'", m_name);
    delete m_camera;
}

} // namespace Lynton
