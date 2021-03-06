/*
 * window abstraction for Windows
 */

#pragma once

#include "Lynton/Core/Window.h"
#include "Lynton/Renderer/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace Lynton
{

	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_window;
		Scope<GraphicsContext> m_context;
		
		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vsync;

			EventCallback event_callback;
		};
		WindowData m_data;
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void on_update() override;

		inline unsigned int get_width() const override { return m_data.width; }
		inline unsigned int get_height() const override { return m_data.height; }

		inline void set_event_callback(const EventCallback& callback) override { m_data.event_callback = callback; }
		
		void set_vsync(bool enabled) override;
		inline bool is_vsync() const override { return m_data.vsync; }

		inline virtual void* get_native_window() const override { return m_window;  }
	private:
		virtual void init(const WindowProperties& props);
		virtual void shutdown();
	};
	
}
