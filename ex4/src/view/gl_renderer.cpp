#include "view/gl_renderer.hpp"
#include "view/glut_window.hpp"
#include "GL/freeglut.h"

using namespace ::view;

GlRenderer::GlRenderer(std::shared_ptr< ::model::Game const > const& g)
: _game_model(g)
{}

std::shared_ptr< ::model::Game const > const& GlRenderer::game_model() const
{
	return _game_model;
}

GlRenderer::delegate_factory_type& GlRenderer::drawable_factory()
{
	return _drawable_factory;
}

GlRenderer::delegate_factory_type const& GlRenderer::drawable_factory() const
{
	return _drawable_factory;
}

void GlRenderer::visualize_model(GlutWindow& w)
{
	// TODO 4.3: initialize OpenGL context, call delegates and swap buffers
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0f, -7.0f, 0.0f, //eye
		0.0f, 0.0f, 0.0f, //center
		0.0f, 0.0f, 1.0f); //up vector

	for (auto& modelObject : _game_model->objects())
	{
		auto data = modelObject->getData<Drawable>();
		if (data == nullptr)
		{
			try
			{
				data = _drawable_factory.create_for(modelObject);
				modelObject->registerData(data);
			}
			catch (std::out_of_range)
			{
				std::cerr << "error getting drawable for model object" << std::endl;
			}
		}
		data->visualize(*this, w);
	}
	glutSwapBuffers();
}

void GlRenderer::resize(GlutWindow& win)
{
	glViewport(0, 0, win.width(), win.height());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //Reset the camera
	gluPerspective(45., win.width() / double(win.height()), .5, 100.);
}
