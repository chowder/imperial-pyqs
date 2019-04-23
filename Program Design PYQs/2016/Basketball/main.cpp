using namespace std;

#include "Player.h"
#include "Court.h"

int main() {

    /* Larry is a basketball player with skill level 0.9 at (4.5, 3.25).
       Michael is a basketball player with skill level 0.95 at (10.5, 5.1).
       Michael has the ball. */
    Player larry = Player("Larry", 0.9, 4.5, 3.25);
    Player michael = Player("Michael", 0.95, 10.5, 5.1);

    Court court = Court();
    court.addPlayer(&larry);
    //court.addPlayer(&michael);
    michael.giveBall();

    /* Larry moves to coordinates (0.25, 2.2) */
    larry.moveTo(0.25, 2.2);

    /* Michael passes the ball to Larry, who shoots at the basket. The number
    of points scored by Larry is printed */
    michael.passTo(&larry);
    larry.shootBall();
}
