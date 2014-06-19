#pragma once
#include "view/al_renderer.hpp"
#include "flappy_box/model/box.hpp"
#include <AL/al.h>
#include <AL/alut.h>

namespace flappy_box
{
	namespace view
	{
		class BoxAudible : public ::view::AlRenderer::Audible
		{
		public:
			BoxAudible(std::shared_ptr<::flappy_box::model::Box> object);
			virtual ~BoxAudible();
			virtual void auralize(::view::AlRenderer& r) override;

		private:
			std::shared_ptr<::flappy_box::model::Box> _object;
			ALuint _al_box_source[2];
			ALuint _al_buffer[2];
			const double base_frequency;
			const double target_frequency;
		};

	} //::view
} //::flappy_box
