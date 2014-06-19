#include "flappy_box/controller/flappy_engine.hpp"
#include "flappy_box/controller/box_object_logic.hpp"
#include "flappy_box/view/box_audible.hpp"
#include "flappy_box/view/box_drawable.hpp"
#include "flappy_box/model/box.hpp"
#include "view/glut_window.hpp"

#include "AL/al.h"
#include "AL/alut.h"

using namespace ::flappy_box::controller;

void FlappyEngine::init(int& argc, char** argv)
{
	super::init(argc, argv);

	if (!alutInit(&argc, argv))
	{
		//error
		std::clog << "Error while initializing AL" << std::endl;
	}
	//create the renderer
	_al_renderer = std::make_shared<::view::AlRenderer>(::view::AlRenderer(game_model()));
	_gl_renderer = std::make_shared<::view::GlRenderer>(::view::GlRenderer(game_model()));

	using namespace ::flappy_box::model;
	game_model()->addGameObject(std::make_shared<Box>(Box()));

	_gl_renderer->drawable_factory().register_module<Box>(
		[](const std::shared_ptr<Box>& o) { return std::make_shared<::flappy_box::view::BoxDrawable>(o); }
	);

	_al_renderer->audible_factory().register_module<Box>(
		[](const std::shared_ptr<Box>& o) { return std::make_shared<::flappy_box::view::BoxAudible>(o); }
	);

	game_logic()->logic_factory().register_module<Box>(
		[](const std::shared_ptr<Box>& o) { return std::make_shared<::flappy_box::controller::BoxObjectLogic>(o); }
	);
}

void FlappyEngine::run()
{
	::view::GlutWindow window("window", 800, 600, _gl_renderer, shared_from_this());

	super::run();
	alutExit();
}

void FlappyEngine::step(::controller::InputEventHandler::keyboard_event const& ev)
{
	game_logic()->advance_model(ev);
	_al_renderer->auralize_model();
}