#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <regex>

Command::Command(State &state) : state(state) {}

void Command::execute(Player *player) {
    player->executed(*this);
}

void Command::execute(Petani *petani) {}
void Command::execute(Peternak *peternak) {}
void Command::execute(Walikota *walikota) {}


vector<Location> Command::inputListLocation(const string &line) {
    regex validation(R"(([A-Z]+\d+)(\s*,\s*([A-Z]\d+))*)");
    smatch match;
    if (!regex_search(line, match, validation) || match.suffix().length() > 0) {
        throw InvalidInputLocationListException();
    }

    vector<Location> result;
    regex pattern(R"(\w+\d+)");

    auto words_begin = sregex_iterator(line.begin(), line.end(), pattern);
    auto words_end = sregex_iterator();

    for (sregex_iterator it = words_begin; it != words_end; ++it) {
        istringstream iss(it->str());
        Location l; iss >> l;
        result.push_back(l);
    }

    return result;
}

int Command::stringToInt(const string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] == '-' && str.size() != 1) {
            continue;
        }
        if (!isdigit(str[i])) {
            throw invalid_argument("Input is not a number!");
        }
    }
    return stoi(str);
}