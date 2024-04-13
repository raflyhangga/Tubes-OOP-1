#include <tubesoop1/gui/command/next.h>
#include <tubesoop1/gui/components/messagebox.h>

Next::Next(State& state, MainWindow &window) : Command(state, window) {}

void Next::execute(Petani *petani) {
    string message = "Giliran dilanjut ke pemain berikutnya.\n";
    petani->addAllPlantAge(state.getTotalPlayer());
    state.nextTurn();
    Petani::incrementAllPlantAge();
    window.getStatusBar().setPlayer(state.getCurrentPlayer());

    message += turnInfo();
    MessageBox(&window, "Next", message).exec();
}
void Next::execute(Peternak *peternak) {
    string message = "Giliran dilanjut ke pemain berikutnya.\n";
    state.nextTurn();
    Petani::incrementAllPlantAge();
    window.getStatusBar().setPlayer(state.getCurrentPlayer());

    message += turnInfo();
    MessageBox(&window, "Next", message).exec();
}
void Next::execute(Walikota *walikota) {
    string message = "Giliran dilanjut ke pemain berikutnya.\n";
    state.nextTurn();
    Petani::incrementAllPlantAge();
    window.getStatusBar().setPlayer(state.getCurrentPlayer());

    message += turnInfo();
    MessageBox(&window, "Next", message).exec();
}

string Next::turnInfo() {
    int numberOfPlayers = state.getTotalPlayer();
    string message = "";
    int turn = state.getTurn();
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = state.getPlayer(i);
        message += to_string(i + 1) + ". " + player->getUsername();
        if (turn == i) message += " (giliranmu)";
        message += "\n";
    }
    return message;
}
