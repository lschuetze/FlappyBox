#include "flappy_box/view/box_drawable.hpp"
#include "GL/freeglut.h"

using namespace ::flappy_box::view;

BoxDrawable::BoxDrawable(std::shared_ptr<::flappy_box::model::Box> object) : _object(object)
{
}

BoxDrawable::~BoxDrawable()
{
}

void BoxDrawable::visualize(::view::GlRenderer& r, ::view::GlutWindow& w)
{
	using namespace std::chrono;
	_object->setDegree(duration_cast<milliseconds>(r.game_model()->timestamp().time_since_epoch()).count() / 10 % 360);

	glRotated(_object->degree(), 0.0f, 0.0f, 1.0f);
	glTranslated(0., 0., _object->position()(2));

	glBegin(GL_LINES);
	glColor3f(0.75f, 0.75f, 0.75f);

	//bottom quarter
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//upwards
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//top quarter
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glEnd();

	w.invalidate();
}
