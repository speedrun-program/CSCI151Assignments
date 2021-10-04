
#include <iostream>
#include <string>

int main()
{
    std::cout << "Mad libs program\n";
    
    // mad lib from here:
    // https://www.it.iitb.ac.in/~vijaya/ssrvm/worksheetscd/getWorksheets.com/Language%20Arts/madlibsdoc.pdf
    
    std::string textParts[] = {
        "\nI walk through the color jungle. I take out my\n",
        "",
        " canteen. There's a\n",
        "",
        " parrot with a ",
        "",
        "\n",
        "",
        " in his mouth right there in front\nof me in the ",
        "",
        " trees! I gaze at his\n",
        "",
        " ",
        "",
        ". A sudden\nsound awakes me from my daydream! A panther's\n",
        "",
        " in front of my head! I\n",
        "",
        " his ",
        "",
        "\nbreath. I remember I have a packet of ",
        "",
        "\nthat makes go into a deep slumber! I\n",
        "",
        " it away from me in front of the\n",
        "",
        ".Yes he's eating it! I\n",
        "",
        " away through the\n",
        "",
        " jungle. I meet my parents at the\ntent. Phew! It's been an exciting day in the jungle.\n\n",
        "Type visible character(s) and press Enter to end program.\n"
    };

    std::string askForAdjective = "adjective: ";
    std::string askForNoun = "noun: ";
    std::string askForVerb = "verb: ";

    std::string askForWords[] = {
        askForAdjective,
        askForAdjective,
        askForAdjective,
        askForNoun,
        askForAdjective,
        askForAdjective,
        askForNoun,
        askForVerb,
        askForVerb,
        askForAdjective,
        askForNoun,
        askForVerb,
        askForNoun,
        askForVerb,
        askForAdjective
    };

    std::string inputtedString = "";

    for (int i = 0; i < 15; i++) // length of askForWords is 15
    {
        std::cout << askForWords[i];
        std::cin >> inputtedString;
        textParts[1 + (i * 2)] = inputtedString;
    }

    for (int i = 0; i < 32; i++) // length of textParts is 32
    {
        std::cout << textParts[i];
    }

    std::cin >> inputtedString;

    return 0;
}
