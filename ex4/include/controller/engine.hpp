# pragma once

# include "model/game.hpp"
# include "controller/logic.hpp"

namespace controller
{
	class Engine : // TODO 4.1: insert base classes
		public InputEventHandler,
		public std::enable_shared_from_this<::controller::Engine>
	{
	public:
        Engine(const std::shared_ptr< Logic >& = std::shared_ptr<::controller::Logic>(
            new ::controller::Logic(std::shared_ptr<::model::Game>(new ::model::Game()))));

		virtual void init(int&, char**) = 0;
		virtual void run() = 0;

		std::shared_ptr< ::model::Game >&             game_model();
        std::shared_ptr< ::model::Game const > const  game_model() const;

		std::shared_ptr< Logic >&             game_logic();
        std::shared_ptr< Logic const > const  game_logic() const;

	protected:
		// Calls everything we need to advance the game.
		// Override this function to integrate new behavior and component that have to be called after the model was updated.
		virtual void step(InputEventHandler::keyboard_event const& ev = controller::InputEventHandler::keyboard_event());

		// TODO 4.1: declare handle function
		// Implements abstract class InputEventHandler. Simply calls function step providing the keyboard_event ev as an argument.
		// Input events should be provided by some input-event-provider (e.g. GlutWindow).
		// Override this function to change event distribution and processing.
		virtual bool handle(InputEventHandler::keyboard_event const& ev) override;

	private:
		std::shared_ptr< ::model::Game > _model;
		std::shared_ptr< Logic >       _logic;

	}; // Engine

} // controller::
