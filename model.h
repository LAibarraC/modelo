#pragma once

// model.h
// https://helloacm.com/model-view-controller-explained-in-c/
#pragma once
#include <string>
using namespace std;
#include "common.h"
// Model is responsible for data get and set
class Model {
public:
    Model(const string& data) {
        this->SetData(data);
    }
    Model() { } // default constructor
    string Data() {
        return this->data;
    }

    void SetData(const string& data) {
        this->data = data;
        if (this->event != nullptr) { // data change callback event
            this->event(data);
        }
    }
    //  register the event when data changes.
    void RegisterDataChangeHandler(DataChangeHandler handler) {
        this->event = handler;
    }
private:
    string data = "";
    DataChangeHandler event = nullptr;
};

class model
{
};

