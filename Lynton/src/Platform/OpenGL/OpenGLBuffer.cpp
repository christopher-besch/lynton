#include "lypch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Lynton
{
    // VertexBuffer
    OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
    {
        LY_PROFILE_FUNCTION();

        // GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
        // binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state.
        glCreateBuffers(1, &m_renderer_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
        // ToDo: hardcoded for now
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, float* vertices)
    {
        LY_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_renderer_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
        // ToDo: hardcoded for now
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        LY_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_renderer_id);
    }

    void OpenGLVertexBuffer::bind() const
    {
        LY_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
    }

    void OpenGLVertexBuffer::unbind() const
    {
        LY_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::set_data(const void* data, uint32_t size)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }


    // IndexBuffer
    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t count, uint32_t* indices)
        : m_count(count)
    {
        LY_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_renderer_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
        // ToDo: hardcoded for now
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        LY_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_renderer_id);
    }

    void OpenGLIndexBuffer::bind() const
    {
        LY_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
    }

    void OpenGLIndexBuffer::unbind() const
    {
        LY_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
