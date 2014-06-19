#include "flappy_box/model/box.hpp"

using namespace ::flappy_box::model;

Box::Box(const bool dynamic_flag, const std::string& name)
: super(dynamic_flag, name),
_speed(0.0f), _deg(0.0f)
{
	_position << 0, 0, 0;
	//_position = vec3_type::Zero;
	_graviton << 0, 0, -5;
	_accel << 0, 0, 0;
}

Box::~Box()
{
}

vec3_type Box::graviton() const
{
	return _graviton;
}

vec3_type Box::position() const
{
	return _position;
}

vec3_type& Box::position()
{
	return _position;
}

float Box::speed() const
{
	return _speed;
}

float& Box::speed()
{
	return _speed;
}

vec3_type Box::acceleration() const
{
	return _accel;
}

vec3_type& Box::acceleration()
{
	return _accel;
}

float Box::degree() const
{
	return _deg;
}

void Box::setPosition(vec3_type& pos)
{
	_position = pos;
}

void Box::setSpeed(float speed)
{
	_speed = speed;
}

void Box::setAcceleration(vec3_type& accel)
{
	_accel = accel;
}

void Box::setDegree(float deg)
{
	_deg = deg;
}
