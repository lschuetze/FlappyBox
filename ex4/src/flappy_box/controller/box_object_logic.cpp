#include "flappy_box/controller/box_object_logic.hpp"
#include <cmath>

using namespace ::controller;
using namespace ::flappy_box::controller;

BoxObjectLogic::BoxObjectLogic(std::shared_ptr<::flappy_box::model::Box> object)
: _object(object)
{
}

bool BoxObjectLogic::advance(Logic& l, InputEventHandler::keyboard_event const& ev)
{
	bool result = false;
	//explizites euler verfahren
	_object->speed() += l.game_model()->timestep().count() * (_object->acceleration()(2) + _object->graviton()(2));
	_object->position()(2) += l.game_model()->timestep().count() * _object->speed();
	
	switch (ev.key)
	{
	case 'w':
		_object->acceleration()(2) = 20.0;
		result = true;
		break;
	}
	//exponentieller Zerfall
	_object->acceleration()(2) *= pow(0.50, l.game_model()->timestep().count());

	return result;
}


