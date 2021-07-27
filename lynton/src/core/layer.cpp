#include "layer.h"

#include "pch.h"

namespace Lynton {

Layer::Layer(const std::string& name)
    : m_name(name)
{
    log_lynton_general("Creating Layer '{}'", m_name);
}

Layer::~Layer()
{
    log_lynton_general("Deleting Layer '{}'", m_name);
    delete m_camera;
}

} // namespace Lynton
