/*#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AdjacencyList.h"
#include <algorithm>
#include <cctype>

std::string removeExtraWhitespace(const std::string& str) {
    std::string result = str;
    // Remove extra whitespace
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

TEST_CASE("1", "[flag]")
{
    string input = R"(7 2
    google.com gmail.com
    google.com maps.com
    facebook.com ufl.edu
    ufl.edu google.com
    ufl.edu gmail.com
    maps.com facebook.com
    gmail.com maps.com)";

    string expectedOutput = R"(facebook.com0.20
    gmail.com0.20
    google.com0.10
    maps.com0.30
    ufl.edu0.20)";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(2);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}

TEST_CASE("2", "[flag]")
{
    string input = R"(1 8
    a.com b.com
    )";

    string expectedOutput = R"(a.com0.00
    b.com0.00)";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(8);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}

TEST_CASE("3", "[flag]")
{
    string input = R"( 
    5 13
    stackoverflow.com ufl.edu
    aman.com ufl.edu
    ufl.edu samsung.com
    aman.com stackoverflow.com
    ufl.edu stackoverflow.com
    )";

    string expectedOutput = R"(aman.com0.00
    samsung.com0.01
    stackoverflow.com0.01
    ufl.edu0.01)";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(13);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}

TEST_CASE("4", "[flag]")
{
    string input = R"(
    5 12
    python.org twitter.com
    github.com getbootstrap.com
    reactjs.org disney.com
    mozilla.org google.com
    python.org ufl.edu
    )";

    string expectedOutput = R"(disney.com0.00
    getbootstrap.com0.00
    github.com0.00
    google.com0.00
    mozilla.org0.00
    python.org0.00
    reactjs.org0.00
    twitter.com0.00
    ufl.edu0.00)";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(12);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}

TEST_CASE("5", "[flag]")
{
    string input = R"(
    2 2
    NIKE.com ADIDAS.com
    ADIDAS.com NIKE.com
    )";

    string expectedOutput = R"(
	ADIDAS.com 0.50
	NIKE.com 0.50
   )";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(2);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}

TEST_CASE("6", "[flag]")
{
    string input = R"(
    227 9
    getbootstrap.com github.com
    github.com openai.com
    chase.com aman.com
    reactjs.org google.com
    facebook.com chase.com
    youtube.com mozilla.org
    zoom.us apple.com
    getbootstrap.com weather.com
    mozilla.org samsung.com
    roblox.com pcbuildinguf.com
    zoom.us youtube.com
    pcbuildinguf.com apple.com
    zoom.us github.com
    instagram.com facebook.com
    facebook.com aman.com
    facebook.com weather.com
    instagram.com getbootstrap.com
    chase.com stackoverflow.com
    openai.com aman.com
    wikipedia.org pcbuildinguf.com
    roblox.com aman.com
    wikipedia.org youtube.com
    samsung.com pcbuildinguf.com
    aman.com samsung.com
    disney.com stackoverflow.com
    weather.com instagram.com
    microsoft.com samsung.com
    apple.com zoom.us
    github.com reactjs.org
    reactjs.org ufl.edu
    microsoft.com instagram.com
    github.com pcbuildinguf.com
    zoom.us microsoft.com
    microsoft.com weather.com
    weather.com getbootstrap.com
    reactjs.org python.org
    youtube.com aman.com
    youtube.com microsoft.com
    stackoverflow.com zoom.us
    roblox.com openai.com
    google.com python.org
    facebook.com reactjs.org
    github.com facebook.com
    chase.com reactjs.org
    disney.com getbootstrap.com
    roblox.com github.com
    youtube.com openai.com
    aman.com openai.com
    pcbuildinguf.com youtube.com
    zoom.us wikipedia.org
    facebook.com mozilla.org
    github.com samsung.com
    instagram.com chase.com
    ufl.edu samsung.com
    getbootstrap.com mozilla.org
    getbootstrap.com samsung.com
    google.com zoom.us
    roblox.com disney.com
    stackoverflow.com aman.com
    disney.com chase.com
    mozilla.org openai.com
    stackoverflow.com python.org
    aman.com disney.com
    pcbuildinguf.com reactjs.org
    zoom.us mozilla.org
    weather.com roblox.com
    python.org pcbuildinguf.com
    chase.com apple.com
    ufl.edu apple.com
    getbootstrap.com aman.com
    python.org stackoverflow.com
    mozilla.org chase.com
    pcbuildinguf.com aman.com
    apple.com roblox.com
    openai.com stackoverflow.com
    github.com chase.com
    mozilla.org zoom.us
    reactjs.org facebook.com
    zoom.us aman.com
    mozilla.org getbootstrap.com
    microsoft.com disney.com
    wikipedia.org roblox.com
    ufl.edu instagram.com
    pcbuildinguf.com python.org
    samsung.com python.org
    pcbuildinguf.com roblox.com
    wikipedia.org apple.com
    stackoverflow.com chase.com
    mozilla.org stackoverflow.com
    disney.com wikipedia.org
    chase.com pcbuildinguf.com
    microsoft.com google.com
    wikipedia.org github.com
    reactjs.org chase.com
    openai.com reactjs.org
    disney.com pcbuildinguf.com
    openai.com ufl.edu
    python.org microsoft.com
    getbootstrap.com stackoverflow.com
    openai.com roblox.com
    stackoverflow.com getbootstrap.com
    apple.com pcbuildinguf.com
    google.com facebook.com
    weather.com reactjs.org
    youtube.com disney.com
    google.com pcbuildinguf.com
    stackoverflow.com weather.com
    facebook.com wikipedia.org
    chase.com weather.com
    zoom.us ufl.edu
    python.org ufl.edu
    getbootstrap.com instagram.com
    youtube.com samsung.com
    wikipedia.org facebook.com
    pcbuildinguf.com facebook.com
    wikipedia.org aman.com
    microsoft.com ufl.edu
    chase.com github.com
    google.com ufl.edu
    instagram.com pcbuildinguf.com
    reactjs.org disney.com
    facebook.com zoom.us
    wikipedia.org weather.com
    samsung.com mozilla.org
    pcbuildinguf.com zoom.us
    github.com mozilla.org
    wikipedia.org mozilla.org
    aman.com github.com
    youtube.com stackoverflow.com
    wikipedia.org disney.com
    roblox.com reactjs.org
    chase.com roblox.com
    aman.com weather.com
    stackoverflow.com samsung.com
    openai.com youtube.com
    aman.com pcbuildinguf.com
    openai.com instagram.com
    python.org weather.com
    github.com roblox.com
    weather.com python.org
    openai.com wikipedia.org
    openai.com samsung.com
    youtube.com apple.com
    ufl.edu google.com
    instagram.com weather.com
    openai.com microsoft.com
    apple.com weather.com
    zoom.us getbootstrap.com
    weather.com wikipedia.org
    aman.com ufl.edu
    github.com getbootstrap.com
    youtube.com roblox.com
    aman.com roblox.com
    python.org instagram.com
    python.org reactjs.org
    mozilla.org instagram.com
    mozilla.org microsoft.com
    openai.com getbootstrap.com
    weather.com microsoft.com
    github.com python.org
    weather.com zoom.us
    disney.com facebook.com
    github.com ufl.edu
    instagram.com microsoft.com
    youtube.com reactjs.org
    samsung.com reactjs.org
    stackoverflow.com disney.com
    stackoverflow.com ufl.edu
    instagram.com mozilla.org
    pcbuildinguf.com chase.com
    google.com github.com
    microsoft.com python.org
    instagram.com apple.com
    mozilla.org wikipedia.org
    mozilla.org reactjs.org
    microsoft.com github.com
    youtube.com zoom.us
    python.org wikipedia.org
    python.org apple.com
    mozilla.org github.com
    stackoverflow.com apple.com
    zoom.us weather.com
    ufl.edu github.com
    chase.com wikipedia.org
    roblox.com weather.com
    reactjs.org mozilla.org
    python.org disney.com
    weather.com github.com
    stackoverflow.com reactjs.org
    mozilla.org apple.com
    weather.com pcbuildinguf.com
    facebook.com python.org
    microsoft.com reactjs.org
    apple.com google.com
    microsoft.com aman.com
    samsung.com aman.com
    reactjs.org microsoft.com
    openai.com github.com
    getbootstrap.com disney.com
    wikipedia.org reactjs.org
    chase.com google.com
    google.com disney.com
    getbootstrap.com chase.com
    weather.com facebook.com
    aman.com facebook.com
    facebook.com roblox.com
    wikipedia.org stackoverflow.com
    reactjs.org wikipedia.org
    microsoft.com stackoverflow.com
    getbootstrap.com pcbuildinguf.com
    getbootstrap.com facebook.com
    google.com youtube.com
    python.org mozilla.org
    stackoverflow.com pcbuildinguf.com
    stackoverflow.com microsoft.com
    weather.com ufl.edu
    apple.com facebook.com
    microsoft.com getbootstrap.com
    disney.com github.com
    zoom.us openai.com
    disney.com apple.com
    mozilla.org roblox.com
    aman.com reactjs.org
    samsung.com microsoft.com
    google.com mozilla.org
    microsoft.com facebook.com
    disney.com instagram.com
    )";

    string expectedOutput = R"(aman.com0.05
    apple.com0.05
    chase.com0.04
    disney.com0.04
    facebook.com0.06
    getbootstrap.com0.03
    github.com0.06
    google.com0.03
    instagram.com0.03
    microsoft.com0.04
    mozilla.org0.05
    openai.com0.03
    pcbuildinguf.com0.07
    python.org0.05
    reactjs.org0.07
    roblox.com0.05
    samsung.com0.03
    stackoverflow.com0.03
    ufl.edu0.04
    weather.com0.05
    wikipedia.org0.04
    youtube.com0.02
    zoom.us0.04)";

    string actualOutput;

    AdjacencyList g;
    g.parseInput(input);
    actualOutput = g.pageRank(9);

    REQUIRE(removeExtraWhitespace(actualOutput) == removeExtraWhitespace(expectedOutput));
}
*/