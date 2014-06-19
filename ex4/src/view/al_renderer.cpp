# include "view/al_renderer.hpp"

using namespace ::view;

AlRenderer::AlRenderer(std::shared_ptr< model::Game const > const& g)
: _game_model(g)
{}

std::shared_ptr< model::Game const > const& AlRenderer::game_model() const
{
	return _game_model;
}

AlRenderer::delegate_factory_type& AlRenderer::audible_factory()
{
	return _audible_factory;
}

AlRenderer::delegate_factory_type const& AlRenderer::audible_factory() const
{
	return _audible_factory;
}

void AlRenderer::auralize_model()
{
    // TODO 4.3: call delegates
    for(auto& modelObject : _game_model->objects())
    {
        auto data = modelObject->getData<Audible>();
        if(data == nullptr)
        {
            try
            {
                data = _audible_factory.create_for(modelObject);
                modelObject->registerData(data);
            }
            catch(std::out_of_range)
            {

            }
        }
        data->auralize(*this);
    }
}
