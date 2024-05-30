#pragma once
#include <vector>
#include <iostream>

class Command {
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class CommandManager {
private:
	std::vector<std::unique_ptr<Command>> history;
	std::vector<std::unique_ptr<Command>> redoStack;
public:
	void executeCommand(std::unique_ptr<Command> command) {
		command->execute();
		history.push_back(std::move(command));
		redoStack.clear();
	}
	void undo() {
		if (!history.empty()) {
			history.back()->undo();
			redoStack.push_back(std::move(history.back()));
			history.pop_back();
		}
	}

	void redo() {
		if (!redoStack.empty()) {
			redoStack.back()->execute();
			history.push_back(std::move(redoStack.back()));
			redoStack.pop_back();
		}
	}
};