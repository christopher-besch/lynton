#pragma once

#include "Lynton/Core/Layer.h"
#include "Lynton/Events/ApplicationEvent.h"
#include "Lynton/Events/KeyEvent.h"
#include "Lynton/Events/MouseEvent.h"

namespace Lynton
{

	// engine defined ImGui overlay
	class  ImGuiLayer : public Layer
	{
	private:
		bool m_block_events = true;
		float m_time = 0.0f;
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer() = default;

		virtual void on_attach() override;
		virtual void on_detach() override;
		virtual void on_event(Event& e) override;
		virtual void on_imgui_render() override;

		void begin();
		void end();

		void set_block_events(bool block_events) { m_block_events = block_events; }
	};

}
