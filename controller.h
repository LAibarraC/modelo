#pragma once

// controller.h
// https://helloacm.com/model-view-controller-explained-in-c/
#pragma once
#include "model.h"
#include "view.h"

// Controller combines Model and View
class Controller {
public:
    Controller(const Model& model, const View& view) {
        this->SetModel(model);
        this->SetView(view);
    }
    void SetModel(const Model& model) {
        this->model = model;
    }
    void SetView(const View& view) {
        this->view = view;
    }
    // when application starts
    void OnLoad() {
        this->view.Render();
    }
private:
    Model model;
    View view;
};

class controller
{
};

