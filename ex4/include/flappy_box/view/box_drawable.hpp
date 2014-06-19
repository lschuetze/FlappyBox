#pragma once

#include "flappy_box/model/box.hpp"
#include "view/gl_renderer.hpp"
#include "view/glut_window.hpp"


namespace flappy_box
{
	namespace view
	{
		class BoxDrawable :
			public ::view::GlRenderer::Drawable
		{
		public:
			BoxDrawable(std::shared_ptr<::flappy_box::model::Box> object);
			virtual ~BoxDrawable();
			virtual void visualize(::view::GlRenderer&, ::view::GlutWindow&) override;
		private:
			std::shared_ptr<::flappy_box::model::Box> _object;
		};
	}
}

