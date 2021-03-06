#include "EditorLayer.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Lynton
{

	EditorLayer::EditorLayer()
        : Layer("Sandbox2D"), m_camera_controller(1280.0f / 720.0f, true)
    {
    }

    void EditorLayer::on_attach()
    {
	    LY_PROFILE_FUNCTION();

	    m_checker_board_texture = Texture2D::create("assets/textures/Checkerboard.png");
	    
	    m_camera_controller.set_zoom_level(5.0f);

	    FrameBufferSpecification frame_buffer_spec;
	    frame_buffer_spec.width = 1280;
	    frame_buffer_spec.height = 720;
	    m_frame_buffer = FrameBuffer::create(frame_buffer_spec);
    }

    void EditorLayer::on_detach()
    {
	    LY_PROFILE_FUNCTION();
    }

    void EditorLayer::on_update(TimeStep time_step)
    {
	    LY_PROFILE_FUNCTION();

	    // update
		if (m_viewport_focused)
	        m_camera_controller.on_update(time_step);

	    // render
	    Renderer2D::reset_stats();
        {
		    LY_PROFILE_SCOPE("Render Prep");
		    m_frame_buffer->bind();
            RenderCommand::set_clear_color({ 0.1f, 0.1f, 0.1f, 0.0f });
	        RenderCommand::clear();
        }

        {
		    LY_PROFILE_SCOPE("Render Draw");

		    static float rotation = 0.0f;
		    rotation += time_step * 50.0f;

            Renderer2D::begin_scene(m_camera_controller.get_camera());
            Renderer2D::draw_quad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_checker_board_texture, 10.0f);
		    Renderer2D::draw_rotated_quad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_checker_board_texture, 20.0f);
            Renderer2D::end_scene();

		    Renderer2D::begin_scene((m_camera_controller.get_camera()));
		    for (float y = -5.0f; y < 5.0f; y += 0.5f)
		    {
			    for ( float x = -5.0f; x < 5.0f; x += 0.5f)
			    {
				    glm::vec4 color = { (x + 5.0f) / 10.0f,  0.4f, (y + 5.0f) / 10.0f, 0.5f };
				    Renderer2D::draw_quad({ x, y, 0.0f }, { 0.45f, 0.45f }, color);
			    }
		    }
		    Renderer2D::end_scene();
        }
		m_frame_buffer->unbind();
    }

    void EditorLayer::on_event(Event& event)
    {
	    m_camera_controller.on_event(event);

    }

    void EditorLayer::on_imgui_render()
    {
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				// Disabling fullscreen would allow the window to be moved to the front of other windows, 
				// which we can't undo at the moment without finer window depth/z control.
				//ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

				if (ImGui::MenuItem("Exit")) Application::get().close();
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::Begin("Settings");

		auto stats = Renderer2D::get_stats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", stats.draw_calls);
		ImGui::Text("Quads: %d", stats.quad_count);
		ImGui::Text("Vertices: %d", stats.get_total_vertex_count());
		ImGui::Text("Indices: %d", stats.get_total_index_count());

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");

		m_viewport_focused = ImGui::IsWindowFocused();
		m_viewport_hovered = ImGui::IsWindowHovered();
		Application::get().get_im_gui_layer()->set_block_events(!m_viewport_focused || !m_viewport_hovered);

		ImVec2 viewport_panel_size = ImGui::GetContentRegionAvail();
		if (m_viewport_size != *((glm::vec2*)&viewport_panel_size) && viewport_panel_size.x > 0 && viewport_panel_size.y > 0)
        {
			m_frame_buffer->resize((uint32_t)viewport_panel_size.x, (uint32_t)viewport_panel_size.y);
			m_viewport_size = { viewport_panel_size.x, viewport_panel_size.y };

			m_camera_controller.on_resize(viewport_panel_size.x, viewport_panel_size.y);
        }
		uint32_t textureID = m_frame_buffer->get_color_attachment_renderer_id();
		ImGui::Image((void*)textureID, viewport_panel_size, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

		ImGui::End();
		ImGui::PopStyleVar();
		ImGui::End();
    }

}
