//
//  imgui_mvc_tests.m
//  imgui-mvc-tests
//
//  Created by Alex on 04/04/2018.
//

#import <XCTest/XCTest.h>

#include "IULayer.hpp"
#include "IUWindowController.hpp"

class IUTestLayer : public IULayer {
public:
    std::vector<IULayer*> subviews() { return _subviews; };
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
}

@end


