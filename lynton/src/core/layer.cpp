#include "layer.h"

#include "pch.h"

namespace Lynton {
Layer::Layer(const std::string& name)
    : m_name(name)
{
    log_lynton_extra("Creating Layer'{}'", m_name);
}

Layer::~Layer()
{
    log_lynton_extra("Deleting Layer '{}'", m_name);
}
} // namespace Lynton
