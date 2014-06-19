#pragma once

#include "controller/glut_engine.hpp"
#include "view/gl_renderer.hpp"
#include "view/al_renderer.hpp"

namespace flappy_box
{
	namespace controller
	{
		class FlappyEngine : public ::controller::GlutEngine
		{
		private:
			typedef ::controller::GlutEngine super;
		public:
			virtual void init(int& argc, char** argv) override;
			virtual void run() override;
		protected:
			virtual void step(InputEventHandler::keyboard_event const& ev = ::controller::InputEventHandler::keyboard_event()) override;
		private:
			std::shared_ptr<::view::GlRenderer> _gl_renderer;
			std::shared_ptr<::view::AlRenderer> _al_renderer;
		};
	}
}
