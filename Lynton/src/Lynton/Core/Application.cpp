#include "lypch.h"

#include "Application.h"
#include "Core.h"

#include "Lynton/Events/ApplicationEvent.h"
#include "Lynton/Core/Log.h"

#include "Lynton/Renderer/Renderer.h"

#include "Lynton/Core/Input.h"
#include "GLFW/glfw3.h"

namespace Lynton
{

	Application* Application::s_instance = nullptr;

	Application::Application(const std::string& name)
	{
		LY_PROFILE_FUNCTION();

		LY_CORE_ASSERT(!s_instance, "Application already exists!")
		s_instance = this;

		// create window handler
		m_window = Window::create(WindowProperties(name));
		m_window->set_event_callback(LY_BIND_EVENT_FUNCTION(Application::on_event));

		Renderer::init();

		// ImGui
		m_imgui_layer = new ImGuiLayer();
		push_overlay(m_imgui_layer);
	}

	Application::~Application()
	{
		Renderer::shutdown();
	}

	void Application::push_layer(Layer* layer)
    {
		LY_PROFILE_FUNCTION();

		m_layer_stack.push_layer(layer);
		layer->on_attach();
    }

	void Application::push_overlay(Layer* layer)
    {
		LY_PROFILE_FUNCTION();

		m_layer_stack.push_overlay(layer);
		layer->on_attach();
    }

	void Application::close()
	{
		m_running = false;
	}

	void Application::run()
	{
		LY_PROFILE_FUNCTION();

		while (m_running)
		{
			LY_PROFILE_SCOPE("Run Loop");

			// ToDo: temporary
			float time = (float)glfwGetTime();
			TimeStep time_step = time - m_last_frame_time;
			m_last_frame_time = time;

			if (!m_minimized)
			{
				LY_PROFILE_SCOPE("LayerStack on_update");

		        for (Layer* layer : m_layer_stack)
				    layer->on_update(time_step);
			}

			m_imgui_layer->begin();
			{
				LY_PROFILE_SCOPE("LayerStack on_imgui_render");

			    for (Layer* layer : m_layer_stack)
				    layer->on_imgui_render();
			}
			m_imgui_layer->end();

			m_window->on_update();
		}
	}

	void Application::on_event(Event& event)
	{
		LY_PROFILE_FUNCTION();

		EventDispatcher dispatcher(event);
		// when the event is a WindowCloseEvent -> call on_window_close
		dispatcher.dispatch<WindowCloseEvent>(LY_BIND_EVENT_FUNCTION(Application::on_window_close));
		dispatcher.dispatch<WindowResizedEvent>(LY_BIND_EVENT_FUNCTION(Application::on_window_resize));

		// ToDo: put break into loop instead of if?
	    // sending the event through every layer until one handles it -> overlays get events first
		for ( auto iterator = m_layer_stack.rbegin(); iterator != m_layer_stack.rend(); ++iterator)
		{
			if (event.m_handled)
				break;
			(*iterator)->on_event(event);
		}
	}

	bool Application::on_window_close(WindowCloseEvent& event)
    {
		m_running = false;
		return true;
    }

	bool Application::on_window_resize(WindowResizedEvent& event)
	{
		LY_PROFILE_FUNCTION();

		m_minimized = event.get_width() == 0 || event.get_height() == 0;

		Renderer::on_window_resize(event.get_width(), event.get_height());

		return false;
	}

}
