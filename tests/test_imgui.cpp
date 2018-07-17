#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "IUAction.hpp"
#include "IUBase.hpp"
#include "IULayerBase.hpp"

TEST_CASE("IUAction")
{
    SECTION("1")
    {
        IUAction a;

        bool* bb = new bool;
                *bb = false;
        a.setCallback([bb](){
            *bb = true;
        });

        REQUIRE(*bb == false);

        a.action();

        REQUIRE(*bb == true);

        //
        *bb = false;
        IUAction a2([bb](){
            *bb = true;
        });

        REQUIRE(*bb == false);

        a();

        REQUIRE(*bb == true);

    }
}

class TestBase:public IUBaseT<TestBase>
{
public:
    std::vector<TestBase*>& components(){return _components;}
};

TEST_CASE("IUBase")
{
    SECTION("1")
    {
        TestBase tb;

        REQUIRE(tb.components().size() == 0);

        TestBase nc;

        tb.addComponent(&nc);
        tb.draw();

        REQUIRE(tb.components().size() == 1);

        tb.removeComponent(&nc);
        tb.draw();

        REQUIRE(tb.components().size() == 0);

    }
}

TEST_CASE("IULayerBase")
{
    SECTION("1")
    {
        IULayerBase lb;

    }
}

TEST_CASE("IUView")
{
    SECTION("1")
    {}
}

