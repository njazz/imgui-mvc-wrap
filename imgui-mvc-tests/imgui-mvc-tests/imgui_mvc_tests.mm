//
//  imgui_mvc_tests.m
//  imgui-mvc-tests
//
//  Created by Alex on 04/04/2018.
//

#import <XCTest/XCTest.h>

#include "IULayer.hpp"
#include "IUWindowController.hpp"
#include "IUObserver.hpp"
#include "IUView.hpp"
#include "IUViewController.hpp"
#include "IUImplementation.hpp"

class IUTestLayer : public IULayer {

public:
    int drawCalled = 0;
    std::vector<IULayer*> subviews() { return _subviews; };

    virtual void draw() override
    {
        drawCalled++;
        IULayer::draw();
    }
};

@interface imgui_mvc_tests : XCTestCase

@end

@implementation imgui_mvc_tests

- (void)testIULayer
{
    IUTestLayer subLayer;

    IUTestLayer mainLayer;

    IUWindowController winController;

    // add/remove sublayer
    XCTAssert(mainLayer.subviews().size() == 0);
    mainLayer.addSubview(&subLayer);
    XCTAssert(mainLayer.subviews().size() == 1);
    XCTAssert(mainLayer.subviews()[0] == &subLayer);
    mainLayer.removeSubview(&subLayer);
    XCTAssert(mainLayer.subviews().size() == 0);

    // empty window controller
    mainLayer.addSubview(&subLayer);
    XCTAssert(mainLayer.windowController() == 0);
    XCTAssert(subLayer.windowController() == 0);
    mainLayer.removeAllSubviews();

    // set window controller
    mainLayer.addSubview(&subLayer);
    mainLayer.setWindowController(&winController);
    XCTAssert(mainLayer.windowController() == &winController);
    XCTAssert(subLayer.windowController() == &winController);
    mainLayer.removeAllSubviews();

    // draw calls test
    mainLayer.addSubview(&subLayer);
    mainLayer.addSubview(&subLayer);
    mainLayer.draw();
    XCTAssert(subLayer.drawCalled == 2);
    mainLayer.hidden = true;
    mainLayer.draw();
    XCTAssert(subLayer.drawCalled == 2);
}

- (void)testIUObserver
{
    int observerCalled = 0;
    IUObserver b = IUObserver([&observerCalled]() {
        observerCalled++;
    });

    b();
    XCTAssert(observerCalled == 1);

    b.setCallback([&observerCalled]() {
        observerCalled = 3;
    });
    b();
    XCTAssert(observerCalled == 3);
}

- (void)testIUView
{
    IUView v1;

    int v1o1 = 1;
    int v1o2 = 2;

    int observerValue;
    IUObserver o1 = IUObserver([&observerValue]() {
        observerValue = 10;
    });
    IUObserver o2 = IUObserver([&observerValue]() {
        observerValue = 20;
    });

    // add observer
    v1.addObserverFor(v1o1, &o1);
    v1.addObserverFor(v1o2, &o2);

    v1.updated(v1o1);
    XCTAssert(observerValue == 10);
    v1.updated(v1o2);
    XCTAssert(observerValue == 20);

    // remove observer
    observerValue = 0;
    v1.removeObserverFor(v1o2, &o2);
    v1.updated(v1o2);
    XCTAssert(observerValue == 0);
}

- (void)testIUViewController
{
    // stub
    IUViewController vc;

    printf("GLFW %s\n", glfwGetVersionString());

    // UPDATE to GLFW 3.3
    IUWindowController* winC = new IUWindowController;
    //    delete winC;
    //vc.setWindowController(&winC);

    //vc.setWindowController(0);
}

- (void)testIUImplementation
{
    IUImplementation i1;
    IUImplementation i2;

    GLFWwindow* w1 = glfwCreateWindow(100, 100, "w1", glfwGetPrimaryMonitor(), 0);
    GLFWwindow* w2 = glfwCreateWindow(100, 100, "w2", glfwGetPrimaryMonitor(), 0);

    i1.init(w1, NO);
    i2.init(w2, NO);

    XCTAssert(glfwGetCurrentContext() == i2.glWindow);
    XCTAssert(ImGui::GetCurrentContext() == i2.context);

    i1.switchContext();

    XCTAssert(glfwGetCurrentContext() == i1.glWindow);
    XCTAssert(ImGui::GetCurrentContext() == i1.context);
}

@end

