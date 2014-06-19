#include "factory_map.hpp"
#include "model/game_object.hpp"
#include "view/al_renderer.hpp"
#include "view/gl_renderer.hpp"
#include "view/glut_window.hpp"
#include "controller/glut_engine.hpp"
#include <iostream>



class TestGameObject : public model::GameObject
{
public:
    TestGameObject(const bool dynamic_flag = true, const std::string& name = "Object1")
        : model::GameObject(dynamic_flag, name)
    {
    }

    virtual ~TestGameObject() { }
};

class TestAudible : public view::AlRenderer::Audible
{
public:
    virtual void auralize(view::AlRenderer & r) override
    {
        std::cout << "auralize" << std::endl;
    }
};

class TestDrawable : public view::GlRenderer::Drawable
{
public:
    virtual void visualize(view::GlRenderer & r, view::GlutWindow & w) override
    {
        std::cout << "visualize" << std::endl;
    }
};

class TestLogic : public controller::Logic::ObjectLogic
{
public:
    virtual bool advance(controller::Logic & l, const controller::InputEventHandler::keyboard_event & ev) override
    {
        std::cout << "thinking" << std::endl;
        return true;
    }
};

class TestGlutEngine : public controller::GlutEngine
{
public:
    typedef controller::GlutEngine super;

    TestGlutEngine() : super()
    {
        gl_renderer = std::shared_ptr<view::GlRenderer> ( new view::GlRenderer(game_model()));
        al_renderer = std::shared_ptr<view::AlRenderer> ( new view::AlRenderer(game_model()));
    }

    virtual void run() override
    {
        window = std::shared_ptr<view::GlutWindow>(new view::GlutWindow("window", 800, 600, gl_renderer, shared_from_this()));
        super::run();
    }

    virtual void step(const keyboard_event &ev) override
    {
        super::step(ev);
        al_renderer->auralize_model();
    }

    std::shared_ptr<view::GlutWindow> window;
    std::shared_ptr<view::GlRenderer> gl_renderer;
    std::shared_ptr<view::AlRenderer> al_renderer;
};

int main( int argc, char** argv )
{
    // TODO 4.3: test factory and delegates here
    std::shared_ptr< TestGlutEngine > game_engine( new TestGlutEngine );

    game_engine->game_logic()->logic_factory().register_module<TestGameObject>(
                [](const std::shared_ptr<TestGameObject>& o) { return std::make_shared< TestLogic >(); }
                );

    game_engine->gl_renderer->drawable_factory().register_module<TestGameObject>(
                [](const std::shared_ptr<TestGameObject>& o) { return std::make_shared< TestDrawable >(); }
                );

    game_engine->al_renderer->audible_factory().register_module<TestGameObject>(
                [](const std::shared_ptr<TestGameObject>& o) { return std::make_shared< TestAudible >(); }
                );

    std::shared_ptr< TestGameObject > testObject1( new TestGameObject(true, "Object1"));

    game_engine->game_model()->addGameObject(testObject1);

    game_engine->init( argc, argv );
    game_engine->run();

    return 0;
}
