# include "controller/logic.hpp"

using namespace ::controller;

Logic::Logic(const std::shared_ptr< ::model::Game >& g) : _model(g)
{
	
}

bool Logic::advance_model(const ::controller::InputEventHandler::keyboard_event& ev)
{
	// TODO 4.3: set current timestamp in model and call delegates
	_model->setTimestamp(std::chrono::steady_clock::now());

	for (auto& modelObject : _model->objects())
	{
		if (modelObject->is_dynamic())
		{
            auto data = modelObject->getData<ObjectLogic>();
            if(data == nullptr)
            {
                try
                {
                    data = _obj_logic_factory.create_for(modelObject);
                    modelObject->registerData(data);
                }
                catch(std::out_of_range)
                {
                    std::cerr << "error getting logic for model object" << std::endl;
                }
            }
            data->advance(*this, ev);
        }
	}
	return true;
}
