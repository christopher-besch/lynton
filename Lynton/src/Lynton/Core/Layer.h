#pragma once

#include "Lynton/Core/TimeStep.h"
#include "Lynton/Core/Core.h"
#include "Lynton/Events/Event.h"

namespace Lynton
{

	class Layer
	{
	protected:
		std::string m_debug_name;
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void on_attach() {}
		virtual void on_detach() {}
		virtual void on_update(TimeStep time_step) {}
		virtual void on_event(Event& event) {}
		virtual void on_imgui_render() {}

		inline const std::string& get_name() const { return m_debug_name; }
	};

}
