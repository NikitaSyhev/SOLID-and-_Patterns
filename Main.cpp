//Ётот проект создан с помощью классического шаблона
#include <iostream>
#include <memory>




//SOLID

// Single Responcibility

// Open - Closed

// Liskov Substitution

// Interface Integration - много интерфейсов лучше чем один

//Dependancy Inversion


//ѕаттерн проектировани¤: фабричный метод

//Base class (fabric method)
//class Dialog
//void render ()
// abstract Button CreateButton() <- fabric method

//WindowDialog: public Dialog 
// Button CreateButton() return Windows button

//class WebDialog: public Dialog
//Button createButton() return HTMLButton


class Button {
public:
	virtual void render() = 0;
	virtual ~Button() {};
};

class WindowsButton :public Button {
public:
	void render() override {
		std::cout << "Render windows button\n";
	};
};

class HTMLButton : public Button{
public:
	void render() override {
		std::cout << "HTML overrride" << std::endl;
	};
};

class Dialog {
public:
	void render() {
		std::shared_ptr<Button> button = createButton();
		button->render();
	}
	virtual std::shared_ptr<Button> createButton() = 0;
	virtual ~Dialog() {}

};

class WindowsDialog :public Dialog {
public:
	std::shared_ptr<Button> createButton()  override{
		return std::make_shared<HTMLButton>();
	}
};



int main(){

	std::cout << " Hello, world! " << std::endl;




	std::shared_ptr<Dialog>		dialog;
	std::string config;

	std::cout << "Enter config ( Windows or Web" << std::endl;

	if (config == "Widows") {
		dialog = std::make_shared<WindowsDialog>();
	}

	else if (config == "Web") {
		dialog = std::make_shared<WindowsDialog>();
	}
	else {
		throw "Error: inknown config";
	}

	dialog->render();



	return 0;
} 