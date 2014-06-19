#ifndef BOX_OBJECT_LOGIC_HPP
#define BOX_OBJECT_LOGIC_HPP

#include "controller/logic.hpp"
#include "flappy_box/model/box.hpp"

namespace flappy_box
{
namespace controller
{

class BoxObjectLogic : public ::controller::Logic::ObjectLogic
{
public:
	BoxObjectLogic(std::shared_ptr<::flappy_box::model::Box> object);

    virtual bool advance(::controller::Logic&, ::controller::InputEventHandler::keyboard_event const&) override;

private:
	std::shared_ptr<::flappy_box::model::Box> _object;
};

} //::controller
} //::flappy_box

#endif // BOX_OBJECT_LOGIC_HPP
