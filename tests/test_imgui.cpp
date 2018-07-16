#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "IUAction.hpp"
#include "IUBase.hpp"

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
{};

TEST_CASE("IUBase")
{
    SECTION("1")
    {
        TestBase tb;
    }
}

TEST_CASE("IULayerBase")
{
    SECTION("1")
    {}
}

TEST_CASE("IUView")
{
    SECTION("1")
    {}
}

